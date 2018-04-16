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

	int iter_range[] = { 0, 1, 0, 1 }; //局部变量

	//******************************************************
	//以下内容改自simpler95的ugrid部分
	//******************************************************

	//XU,按照原始的fortran版本，是根据xl和xcells算出dx，然后进行xu的计算，从xu(2)到xu(L1)。在当前的ops版本中
	//我们为了全部统一，从xu(0)到xu(L1)都给做出来。把xmin、xmax和xcells设置成全局变量，才能直接从cuda调用。
	//所以在globalvars声明了ops_constan的xmin、xmax和xcells

	//用一个kernel把所有的x方向网格变量都设置好
	iter_range[0] = 0;
	iter_range[1] = xL1;
	iter_range[2] = 0;
	iter_range[3] = 1;
	ops_par_loop(gridsetup_kernel_setupX, "gridsetup_kernel_setupX",
			fvm2dc_grid, 2, iter_range,
			ops_arg_dat(xu_facex, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(x_cellx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(xdif_celldx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(xcv_facedx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(xcvs, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(xcvi, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(xcvip, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());

	ops_print_dat_to_txtfile(xu_facex, "xu_facex.dat");
	ops_print_dat_to_txtfile(x_cellx, "x_cellx.dat");
	ops_print_dat_to_txtfile(xdif_celldx, "xdif_celldx.dat");
	ops_print_dat_to_txtfile(xcv_facedx, "xcv_facedx.dat");
	ops_print_dat_to_txtfile(xcvs, "xcvs.dat");
	ops_print_dat_to_txtfile(xcvi, "xcvi.dat");
	ops_print_dat_to_txtfile(xcvip, "xcvip.dat");
//
//	//用一个kernel把所有的Y方向网格变量都设置好
//	iter_range[0] = 0;
//	iter_range[1] = xL1 + 1;
//	iter_range[2] = 0;
//	iter_range[3] = 1;
//	ops_par_loop(gridsetup_kernel_setupY, "gridsetup_kernel_setupY",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(yv_facey, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(ycv_facedy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(ycvs, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(ycvr, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(ycvrs, 1, S2D_00, "double", OPS_WRITE), ops_arg_idx());

	//
	//	ops_par_loop(gridsetup_kernel_facex, "gridsetup_kernel_facex", fvm2dc_grid,
	//			2, iter_range,
	//			ops_arg_dat(xu_facex, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_idx());
	//
	//	//YV，
	//	iter_range[0] = 0;
	//	iter_range[1] = 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = yM1 + 1;
	//	ops_par_loop(gridsetup_kernel_facey, "gridsetup_kernel_facey", fvm2dc_grid,
	//			2, iter_range,
	//			ops_arg_dat(yv_facey, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_idx());

	//******************************************************
	//ugrid部分结束
	//******************************************************

	//******************************************************
	//以下内容改自simpler95的setup1部分
	//*****************************************************

	//X,按照原始的fortran版本，是在setup1中根据xu的值算x的，我们仍然保留这样的算法
	//会用到当前点的facex和右边一点的facex，
	//所以我们用了S2D_00_P10。（在将来的版本中可能会改为更为迅捷的基于xlength和xcells的算法。）
	//	iter_range[0] = 0;
	//	iter_range[1] = xL1 + 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = 1;
	//	ops_par_loop(gridsetup_kernel_cellx, "gridsetup_kernel_cellx", fvm2dc_grid,
	//			2, iter_range, ops_arg_dat(x_cellx, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(xu_facex, 1, S2D_00_P10, "double", OPS_READ),
	//			ops_arg_idx());

	//Y,按照原始的fortran版本，是在setup1中根据yv的值算y的，我们仍然保留这样的算法
	//会用到当前点的facey和右边一点的facey，
	//	//所以我们用了S2D_00_P10。（在将来的版本中可能会改为更为迅捷的基于xlength和xcells的算法。）
	//	iter_range[0] = 0;
	//	iter_range[1] = 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = yM1 + 1;
	//	ops_par_loop(gridsetup_kernel_celly, "gridsetup_kernel_celly", fvm2dc_grid,
	//			2, iter_range, ops_arg_dat(y_celly, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(yv_facey, 1, S2D_00_0P1, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//XDIFF
	//	iter_range[0] = 0;
	//	iter_range[1] = xL1 + 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = 1;
	//	ops_par_loop(gridsetup_kernel_celldx, "gridsetup_kernel_celldx",
	//			fvm2dc_grid, 2, iter_range,
	//			ops_arg_dat(xdif_celldx, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(x_cellx, 1, S2D_00_M10, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//XCV，就是x方向主控制容积，根据facex计算出来
	//	iter_range[0] = 0;
	//	iter_range[1] = xL1 + 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = 1;
	//	ops_par_loop(gridsetup_kernel_facedx, "gridsetup_kernel_facedx",
	//			fvm2dc_grid, 2, iter_range,
	//			ops_arg_dat(xcv_facedx, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(xu_facex, 1, S2D_00_M10, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//xcvs
	//	iter_range[0] = 0;
	//	iter_range[1] = xL1 + 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = 1;
	//	ops_par_loop(gridsetup_kernel_xcvs, "gridsetup_kernel_xcvs", fvm2dc_grid, 2,
	//			iter_range, ops_arg_dat(xcvs, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(xdif_celldx, 1, S2D_00_P10_M10, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//xcvi
	//	iter_range[0] = 0;
	//	iter_range[1] = xL1 + 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = 1;
	//	ops_par_loop(gridsetup_kernel_xcvs, "gridsetup_kernel_xcvs", fvm2dc_grid, 2,
	//			iter_range, ops_arg_dat(xcvs, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(xdif_celldx, 1, S2D_00_P10_M10, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//xcvip
	//	iter_range[0] = 0;
	//	iter_range[1] = xL1 + 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = 1;
	//	ops_par_loop(gridsetup_kernel_xcvs, "gridsetup_kernel_xcvs", fvm2dc_grid, 2,
	//			iter_range, ops_arg_dat(xcvs, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(xdif_celldx, 1, S2D_00_P10_M10, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//YDIF
	//	iter_range[0] = 0;
	//	iter_range[1] = 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = yM1 + 1;
	//	ops_par_loop(gridsetup_kernel_celly, "gridsetup_kernel_celly", fvm2dc_grid,
	//			2, iter_range, ops_arg_dat(y_celly, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(yv_facey, 1, S2D_00_0P1, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//Ycv
	//	iter_range[0] = 0;
	//	iter_range[1] = 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = yM1 + 1;
	//	ops_par_loop(gridsetup_kernel_facedy, "gridsetup_kernel_facedy",
	//			fvm2dc_grid, 2, iter_range,
	//			ops_arg_dat(ycv_facedy, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(yv_facey, 1, S2D_00_0M1, "double", OPS_READ),
	//			ops_arg_idx());
	//
	//	//Ycvs
	//	iter_range[0] = 0;
	//	iter_range[1] = 1;
	//	iter_range[2] = 0;
	//	iter_range[3] = yM1 + 1;
	//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
	//			fvm2dc_grid, 2, iter_range,
	//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
	//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
	//			ops_arg_idx());

//	if (coordmode == 1) {
//
//		//rmn
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//r
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//sx
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//sxmn
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//ycvr
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//arx
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//ycvs
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//arxj
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//
//		//arxjp
//		iter_range[0] = 0;
//		iter_range[1] = 1;
//		iter_range[2] = 0;
//		iter_range[3] = yM1 + 1;
//		ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//				fvm2dc_grid, 2, iter_range,
//				ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//				ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//				ops_arg_idx());
//	}
//	//fv
//	iter_range[0] = 0;
//	iter_range[1] = 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());
//
//	//fvp
//	iter_range[0] = 0;
//	iter_range[1] = 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());
//
//	//fx
//	iter_range[0] = 0;
//	iter_range[1] = 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());
//
//	//fxm
//	iter_range[0] = 0;
//	iter_range[1] = 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());
//	//fy
//	iter_range[0] = 0;
//	iter_range[1] = 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());
//
//	//fym
//	iter_range[0] = 0;
//	iter_range[1] = 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());
	//******************************************************
	//simpler95的setup1部分结束，con,ap,u,v,rho,cp,pc的初始化，放到buildinitialfield中去
	//*****************************************************

	//con,ap,u,v,rho,cp,pc,p
//	iter_range[0] = 0;
//	iter_range[1] = xL1 + 1;
//	iter_range[2] = 0;
//	iter_range[3] = yM1 + 1;
//	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy",
//			fvm2dc_grid, 2, iter_range,
//			ops_arg_dat(ydif_celldy, 1, S2D_00, "double", OPS_WRITE),
//			ops_arg_dat(y_celly, 1, S2D_00_0M1, "double", OPS_READ),
//			ops_arg_idx());

}
