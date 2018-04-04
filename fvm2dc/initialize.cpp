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

	fvm2d_grid = ops_decl_block(2, "fvm2d_grid");

	int d_p[2] = { 0, 0 };
	int d_m[2] = { 0, 0 };
	int base[2] = { 0, 0 };
	int size[2] = { xL1 + 1, yM1 + 1 };
	double *temp = NULL;

	//XU
	size[0] = xL1 + 1;
	size[1] = 1;
	facex = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "facex");

	//YV
	size[0] = 1;
	size[1] = yM1 + 1;
	facey = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "facey");
	//X
	size[0] = xL1;
	size[1] = 1;
	cellx = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"cellx");

	//Y
	size[0] = 1;
	size[1] = yM1;
	celly = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"celly");

	//XDIF
	size[0] = xL1;
	size[1] = 1;
	celldx = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"celldx");

	//YDIF
	size[0] = 1;
	size[1] = yM1;
	celldy = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"celldy");

	//XCV
	size[0] = xL1;
	size[1] = 1;
	facedx = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"facedx");
	xcvi = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvi");
	xcvip = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"xcvip");

	//YCV
	size[0] = 1;
	size[1] = yM1;
	facedy = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"facedy");

	size[0] = xL1;
	size[1] = yM1;
	xvel0 = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"xvel0");
	yvel0 = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"yvel0");
	presscorr = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp,
			"double", "presscorr");
	density = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"density");
	temperature = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp,
			"double", "temperature");
	xvelhat = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"xvelhat");
	yvelhat = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double",
			"yvelhat");

	ops_decl_const("xmin", 1, "double", &xmin);
	ops_decl_const("xmax", 1, "double", &xmax);
	ops_decl_const("xcells", 1, "int", &xcells);
	ops_decl_const("ymin", 1, "double", &ymin);
	ops_decl_const("ymax", 1, "double", &ymax);
	ops_decl_const("ycells", 1, "int", &ycells);
	ops_decl_const("xL1", 1, "int", &xL1);
	ops_decl_const("yM1", 1, "int", &yM1);

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

