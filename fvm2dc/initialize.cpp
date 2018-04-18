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
	int base[2] = { 0, 0 };

	//fortran的base从1,1，但是c从0,0开始，这里本也可从1,1开始，
	//但由于stride_stencil好像不支持，所以还是从0,0开始吧

	int size[2] = { 0, 0 };
	double *temp = NULL;

	//********************************************************
	//网格相关的几何变量开始
	//********************************************************

	size[0] = xL1;
	size[1] = 1;
	xu = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xu");
	xx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xx");
	xdif = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xdif");
	xcv = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcv");
	xcvs = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvs");
	xcvi = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvi");
	xcvip = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvip");
	fx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"fx");
	fxm = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"fxm");

	size[0] = 1;
	size[1] = yM1;
	yv = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"yv");
	yy = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"yy");
	ydif = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ydif");
	ycv = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ycv");
	ycvs = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ycvs");
	fy = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"fy");
	fym = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"fym");
	rr = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"rr");
	sx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"sx");
	rmn = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"rmn");
	sxmn = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"sxmn");
	arx = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"arx");
	arxj = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"arxj");
	arxjp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"arxjp");
	ycvr = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ycvr");
	ycvrs = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ycvrs");
	fv = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"fv");
	fvp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"fvp");

	//********************************************************
	//网格相关的几何变量结束
	//********************************************************


	//********************************************************
	//网格上的节点变量开始
	//********************************************************

	size[0] = xL1;
	size[1] = yM1;
	uxvel = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uxvel");
	vyvel = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vyvel");
	pc_presscorr = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "pc_presscorr");
	rho = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"rho");
	t_temperature = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "t_temperature");
	uhat_xvelhat = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "uhat_xvelhat");
	vhat_yvelhat = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "vhat_yvelhat");

	pt = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"pt");

	qt = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"qt");

	pressure = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp,
			"double", "pressure");

	gam = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"gam");
	cp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"cp");
	//********************************************************
	//变量的系数开始
	//********************************************************
	//一般方程的系数

	con = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"con");
	aip = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"aip");
	aim = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"aim");
	ajp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ajp");
	ajm = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ajm");
	app = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"app");
	//U方程的系数
	ucon = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"ucon");
	uaip = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uaip");
	uaim = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uaim");
	uajp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uajp");
	uajm = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uajm");
	uapp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uapp");

	//V方程的系数
	vcon = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vcon");
	vaip = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vaip");
	vaim = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vaim");
	vajp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vajp");
	vajm = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vajm");
	vapp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"vapp");
	//P方程的系数
	pcon = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"pcon");
	paip = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"paip");
	paim = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"uaim");
	pajp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"pajp");
	pajm = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"pajm");
	papp = ops_decl_dat(fvm2dc_grid, 1, size, base, d_m, d_p, temp, "double",
			"papp");
	//********************************************************
	//变量的系数结束
	//********************************************************

	//********************************************************
	//常数开始
	//********************************************************


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
	ops_decl_const("rhocon", 1, "double", &rhocon);
	ops_decl_const("cpcon", 1, "double", &cpcon);

	//ops_diagnostic_output();

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

	int s2D_00_P10_M10[] = { 0, 0, 1, 0, -1, 0 }; //00:10:-10
	S2D_00_P10_M10 = ops_decl_stencil(2, 3, s2D_00_P10_M10, "00:10:-10");

	int s2D_00_0P1_0M1[] = { 0, 0, 0, 1, 0, -1 }; //00:01:0-1
	S2D_00_0P1_0M1 = ops_decl_stencil(2, 3, s2D_00_0P1_0M1, "00:01:0-1");

	int s2D_00_P10_M10_0P1_0M1[] = { 0, 0, 1, 0, -1, 0, 0, 1, 0, -1 };
	S2D_00_P10_M10_0P1_0M1 = ops_decl_stencil(2, 5, s2D_00_P10_M10_0P1_0M1,
			"00:10:-10:01:0-1");

	int stride2D_x[] = { 1, 0 };
	int stride2D_y[] = { 0, 1 };

	S2D_00_STRID2D_X = ops_decl_strided_stencil(2, 1, s2D_00, stride2D_x,
			"s2D_00_stride2D_x");

	S2D_00_P10_STRID2D_X = ops_decl_strided_stencil(2, 2, s2D_00_P10,
			stride2D_x, "s2D_00_P10_stride2D_x");

	S2D_00_M10_STRID2D_X = ops_decl_strided_stencil(2, 2, s2D_00_M10,
			stride2D_x, "s2D_00_M10_stride2D_x");

	S2D_00_P10_M10_STRID2D_X = ops_decl_strided_stencil(2, 3, s2D_00_P10_M10,
			stride2D_y, "s2D_00_P10_M10_stride2D_x");

	S2D_00_STRID2D_Y = ops_decl_strided_stencil(2, 1, s2D_00, stride2D_y,
			"s2D_00_stride2D_y");

	S2D_00_0P1_STRID2D_Y = ops_decl_strided_stencil(2, 2, s2D_00_0P1,
			stride2D_y, "s2D_00_0P1_stride2D_y");

	S2D_00_0M1_STRID2D_Y = ops_decl_strided_stencil(2, 2, s2D_00_0M1,
			stride2D_y, "s2D_00_0M1_stride2D_y");

	S2D_00_0P1_0M1_STRID2D_Y = ops_decl_strided_stencil(2, 3, s2D_00_0P1_0M1,
			stride2D_y, "s2D_00_0P1_0M1_stride2D_y");

	//ops_diagnostic_output();
}

