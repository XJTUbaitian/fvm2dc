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
 * buildinitialfield.cpp
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

#include "buildinitialfield_kernel.h"

void buildinitialfield() {

	int iter_range[] = { 0, 1, 0, 1 }; //局部变量
	iter_range[0] = 1;
	iter_range[1] = xL1+1;
	iter_range[2] = 1;
	iter_range[3] = yM1+1;

	ops_par_loop(buildinitialfield_kernel_setupinitialfield,
			"buildinitialfield_kernel_setupinitialfield", fvm2dc_grid, 2,
			iter_range,
			ops_arg_dat(pc_presscorr, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(u_xvel0, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(v_yvel0, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(con, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(app, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(density, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(cp, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(pressure, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_idx());

	//********************************
	//simpler.f90的start在此
	//********************************

	iter_range[0] = 1;
	iter_range[1] = xL1+1;
	iter_range[2] = 1;
	iter_range[3] = yM1+1;

	ops_par_loop(buildinitialfield_kernel_start,
			"buildinitialfield_kernel_start", fvm2dc_grid, 2, iter_range,
			ops_arg_dat(t_temperature, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(x_cellx, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(y_celly, 1, S2D_00, "double", OPS_READ), ops_arg_idx());
	//********************************
	//simpler.f90的start结束
	//********************************
}
