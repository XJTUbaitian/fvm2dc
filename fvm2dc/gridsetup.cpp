/*

 Open source copyright declaration based on BSD open source template:
 https://opensource.org/licenses/BSD-3-Clause

 This file is part of the fvm2d distribution.


 Copyright (c) 2018, Mingtao Li.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 * Neither the name of the copyright holder nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY Mingtao Li "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


 @author Mingtao Li
 mingtao.li@gmail.com
 */

/*
 * gridsetup.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: limingtao
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// OPS header file
#define  OPS_2D
#include "ops_seq.h"

#include "globalvars.h"

#include "gridsetup_kernel.h"

void gridsetup() {
	//ops_diagnostic_output();
	int iter_range[] = { 0, xL1 + 1, 0, 1 };

	//XU,按照原始的fortran版本，是根据xl和xcells算出dx，然后进行xu的计算，从xu(2)到xu(L1)。在当前的ops版本中
	//我们为了全部统一，从xu(0)到xu(L1)都给做出来。把xmin、xmax和xcells设置成全局变量，才能直接从cuda调用。
	//所以在globalvars声明了ops_constan的xmin、xmax和xcells

	ops_par_loop(gridsetup_kernel_facex, "gridsetup_kernel_facex", fvm2dc_grid,
			2, iter_range, ops_arg_dat(facex, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_idx());

	//X,按照原始的fortran版本，是根据xu的值算x的，在setup1中，我们仍然保留这样的算法
	//X的iter_range范围仍然与上述iter_range,所以我们不做修改。但是会用到当前点的facex和右边一点的facex，
	//所以我们用了S2D_00_P10。（在将来的版本中可能会改为更为迅捷的基于xlength和xcells的算法。）
	ops_par_loop(gridsetup_kernel_cellx, "gridsetup_kernel_cellx", fvm2dc_grid,
			2, iter_range, ops_arg_dat(cellx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(facex, 1, S2D_00_P10, "double", OPS_READ),
			ops_arg_idx());

	//XCV，就是x方向主控制容积，根据facex计算出来
	ops_par_loop(gridsetup_kernel_facedx, "gridsetup_kernel_facedx",
			fvm2dc_grid, 2, iter_range,
			ops_arg_dat(facedx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(facex, 1, S2D_00_M10, "double", OPS_READ),
			ops_arg_idx());

	//XDIFF
	ops_par_loop(gridsetup_kernel_celldx, "gridsetup_kernel_celldx",
			fvm2dc_grid, 2, iter_range,
			ops_arg_dat(celldx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(cellx, 1, S2D_00_M10, "double", OPS_READ),
			ops_arg_idx());


	//ops_print_dat_to_txtfile(facex, "facex.dat");
	//	ops_par_loop(gridsetup_kernel_xcvs, "gridsetup_kernel_xcvs", fvm2dc_grid, 2, iter_range,
	//	              ops_arg_dat(xcvs, 1, S2D_00, "double", OPS_WRITE),
	//				  ops_arg_dat(celldx, 1, S2D_00_P10_M10, "double", OPS_READ),
	//	              ops_arg_idx());

	iter_range[0] = 0;
	iter_range[1] = 1;
	iter_range[2] = 0;
	iter_range[3] = yM1 + 1;
	ops_par_loop(gridsetup_kernel_facey, "gridsetup_kernel_facey", fvm2dc_grid,
			2, iter_range, ops_arg_dat(facey, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_idx());

	ops_par_loop(gridsetup_kernel_celly, "gridsetup_kernel_celly", fvm2dc_grid,
			2, iter_range, ops_arg_dat(celly, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(facey, 1, S2D_00_0P1, "double", OPS_READ),
			ops_arg_idx());

	ops_par_loop(gridsetup_kernel_facedy, "gridsetup_kernel_facedy",
			fvm2dc_grid, 2, iter_range,
			ops_arg_dat(facedy, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(facey, 1, S2D_00_0M1, "double", OPS_READ),
			ops_arg_idx());

	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
			fvm2dc_grid, 2, iter_range,
			ops_arg_dat(celldy, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(celly, 1, S2D_00_0M1, "double", OPS_READ),
			ops_arg_idx());

	ops_print_dat_to_txtfile(facex, "facex.dat");
	ops_print_dat_to_txtfile(facey, "facey.dat");
	ops_print_dat_to_txtfile(cellx, "cellx.dat");
	//	ops_print_dat_to_txtfile(celly, "celly.dat");
	//	ops_print_dat_to_txtfile(celldx, "celldx.dat");
	//	ops_print_dat_to_txtfile(celldy, "celldy.dat");
	//	ops_print_dat_to_txtfile(facedx, "facedx.dat");
	//	ops_print_dat_to_txtfile(facedy, "facedy.dat");

	if (coordmode == 1) {

	} else if (coordmode == 2) {

	} else if (coordmode == 3) {

	} else {

	}

}
