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
 * globalvars.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Mingtao Li
 */

#include "globalvars.h"

//ops block
ops_block fvm2d_grid; //grid

//ops dats
ops_dat facex; // xu
ops_dat facey; // yv
ops_dat cellx; // x
ops_dat celly; // y
ops_dat celldx; // xdif
ops_dat celldy; // ydif
ops_dat facedx; // xcv
ops_dat facedy; // ycv
ops_dat xcvs; // xcvs
ops_dat ycvs; // ycvs

ops_dat xcvi; // xcvi
ops_dat xcvip; // xcvip

ops_dat ycvr; // ycvr
ops_dat ycvrs; // ycvrs

ops_dat arx;
ops_dat arxj;
ops_dat arxjp;
ops_dat radius;
ops_dat rmn;

ops_dat sx;
ops_dat sxmn;

ops_dat xvel0; // U
ops_dat yvel0; // V
ops_dat presscorr; // P
ops_dat density; // RHO
ops_dat temperature; // T
ops_dat xvelhat; // UHAT
ops_dat yvelhat; // VHAT

//commonly used stencils
ops_stencil S2D_00; // 00
ops_stencil S2D_00_P10; // 00:10
ops_stencil S2D_00_M10; // 00:-10
ops_stencil S2D_00_0P1; // 00:01
ops_stencil S2D_00_0M1; // 00:0-1
ops_stencil S2D_00_P10_M10; //00:10:-10
ops_stencil S2D_00_P10_M10_0P1_0M1;

FILE *fp;

double xmin;
double ymin;
double xmax;
double ymax;
double xlength;
double ylength;
int xcells;
int ycells;
int xL1;
int xL2;
int xL3;
int yM1;
int yM2;
int yM3;
int iter;
bool lsolve[14];
bool lprint[14];
bool lblk[14];
bool lstop;
string title[14];
int coordmode=1;
