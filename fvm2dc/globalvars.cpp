/*

 Open source copyright declaration based on BSD open source template:
 https://opensource.org/licenses/BSD-3-Clause

 This file is part of the fvm2dc distribution.


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

string title[NFX4];
int lsolve[NFX4];
int lprint[NFX4];
int lblk[NFX4];
int lstop;

//ops block
ops_block fvm2dc_grid; //grid

//ops dats
ops_dat facex; // 原来的变量xu
ops_dat facey; // 原来的变量yv
ops_dat cellx; // 原来的变量x
ops_dat celly; // 原来的变量y
ops_dat celldx; // 原来的变量xdif
ops_dat celldy; // 原来的变量ydif
ops_dat facedx; // 原来的变量xcv
ops_dat facedy; // 原来的变量ycv
ops_dat xcvs; // 原来的变量xcvs
ops_dat ycvs; // 原来的变量ycvs
ops_dat xcvi; // 原来的变量xcvi
ops_dat xcvip; // 原来的变量xcvip
ops_dat ycvr; // 原来的变量ycvr
ops_dat ycvrs; // 原来的变量ycvrs

ops_dat arx; //原来的变量arx
ops_dat arxj; //原来的变量arxj
ops_dat arxjp; //原来的变量arxjp

ops_dat radius; //原来的变量r
ops_dat rmn; //原来的变量rmn

ops_dat sx; //原来的变量sx
ops_dat sxmn; //原来的变量sxmn

ops_dat xvel0; // 原来的变量U
ops_dat yvel0; // 原来的变量V
ops_dat presscorr; // 原来的变量PC
ops_dat temperature; // 原来的变量T
ops_dat deltaxvel0; // 原来的变量dU
ops_dat deltayvel0; // 原来的变量dV
ops_dat xvelhat; // 原来的变量UHAT
ops_dat yvelhat; // 原来的变量VHAT

ops_dat pressure; // 原来的变量P
ops_dat density; // 原来的变量RHO
ops_dat gam; // 原来的变量GAM
ops_dat cp; // 原来的变量cp

ops_dat con; // 原来的变量con

ops_dat aip; // 原来的变量aip
ops_dat aim; // 原来的变量aim

ops_dat ajp; // 原来的变量ajp
ops_dat ajm; // 原来的变量ajm

ops_dat app; // 原来的变量ap

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
double xlength; //原来的变量xl
double ylength; //原来的变量yl

int xcells;
int ycells;
int xL1; //原来的变量L1
int xL2; //原来的变量L2
int xL3; //原来的变量L3
int yM1; //原来的变量M1
int yM2; //原来的变量M2
int yM3; //原来的变量M3
int iter; //原来的变量iter

double smax; //原来的变量smax
double ssum; //原来的变量ssum
double flow; //原来的变量flow
double diff; //原来的变量diff
double acof; //原来的变量acof

int coordmode; //原来的变量mode





int coordmode=1;
