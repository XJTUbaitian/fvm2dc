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
 * initialize.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: Mintao Li
 */

// standard headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// OPS header file
#define  OPS_2D
#include "ops_lib_cpp.h"

#include "globalvars.h"

void initialize()

{

	fvm2dc_grid = ops_decl_block(2, "fvm2dc_grid");

	int d_p[2] = { 0, 0 };
	int d_m[2] = { 0, 0 };
	int base[2] = { 1, 1 }; //改成从1,1开始，便于与simpler.f90的进行比较
	int size[2] = { xL1 , yM1 };
	double *temp = NULL;

	size[0] = xL1;
	size[1] = 1;

	//XU
	xu_facex = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "xu_facex");
	//X
	x_cellx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"x_cellx");
	//XDIF
	xdif_celldx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "xdif_celldx");
	//XCV
	xcv_facedx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "xcv_facedx");
	//xcvs
	xcvs = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvs");
	//xcvi
	xcvi = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvi");
	//xcvip
	xcvip = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvip");

	//YV
	size[0] = 1;
	size[1] = yM1 + 1;
	yv_facey = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "yv_facey");

	//Y
	size[0] = 1;
	size[1] = yM1;
	y_celly = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"y_celly");

	//YDIF
	size[0] = 1;
	size[1] = yM1;
	ydif_celldy = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "ydif_celldy");

	//YCV
	size[0] = 1;
	size[1] = yM1;
	ycv_facedy = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "ycv_facedy");

	size[0] = xL1;
	size[1] = yM1;
	u_xvel0 = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"u_xvel0");
	v_yvel0 = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"v_yvel0");
	pc_presscorr = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "pc_presscorr");
	density = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"density");
	t_temperature = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "t_temperature");
	uhat_xvelhat = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "uhat_xvelhat");
	vhat_yvelhat = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "vhat_yvelhat");

	ops_decl_const("xmin", 1, "double", &xmin);
	ops_decl_const("xmax", 1, "double", &xmax);
	ops_decl_const("xcells", 1, "int", &xcells);
	ops_decl_const("ymin", 1, "double", &ymin);
	ops_decl_const("ymax", 1, "double", &ymax);
	ops_decl_const("ycells", 1, "int", &ycells);
	ops_decl_const("xL1", 1, "int", &xL1);
	ops_decl_const("xL2", 1, "int", &xL2);
	ops_decl_const("xL3", 1, "int", &xL3);
	ops_decl_const("yM1", 1, "int", &yM1);
	ops_decl_const("yM2", 1, "int", &yM2);
	ops_decl_const("yM3", 1, "int", &yM3);

	ops_diagnostic_output();

	int s2D_00[] = { 0, 0 };
	S2D_00 = ops_decl_stencil(2, 1, s2D_00, "00");

	int s2D_00_P10[] = { 0, 0, 1, 0 };
	S2D_00_P10 = ops_decl_stencil(2, 2, s2D_00_P10, "00:10");

	int s2D_00_M10[] = { 0, 0, -1, 0 };
	S2D_00_M10 = ops_decl_stencil(2, 2, s2D_00_M10, "00:-10");

	int s2D_00_0P1[] = { 0, 0, 0, 1 };
	S2D_00_0P1 = ops_decl_stencil(2, 2, s2D_00_0P1, "00:01");

	int s2D_00_0M1[] = { 0, 0, 0, -1 };
	S2D_00_0M1 = ops_decl_stencil(2, 2, s2D_00_0M1, "00:0-1");

	int s2D_00_P1_M10[] = { 0, 0, 1, 0, -1, 0 }; //00:10:-10
	S2D_00_P10_M10 = ops_decl_stencil(2, 3, s2D_00_P1_M10, "00:10:-10");

	int s2D_00_P10_M10_0P1_0M1[] = { 0, 0, 1, 0, -1, 0, 0, 1, 0, -1 };
	S2D_00_P10_M10_0P1_0M1 = ops_decl_stencil(2, 5, s2D_00_P10_M10_0P1_0M1,
			"00:10:-10:01:0-1");

	//ops_diagnostic_output();
}

