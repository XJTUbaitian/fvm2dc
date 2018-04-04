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
 * globalvars.h
 *
 *  Created on: Mar 31, 2018
 *      Author: Mingtao Li
 */

#ifndef FVM2DC_GLOBALVARS_H_
#define FVM2DC_GLOBALVARS_H_

// standard headers
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

// OPS header file
#define  OPS_2D
#include "ops_lib_cpp.h"

using namespace std;

//ops block
extern ops_block fvm2d_grid; //grid

//ops dats
extern ops_dat facex; // xu
extern ops_dat facey; // yv
extern ops_dat cellx; // x
extern ops_dat celly; // y
extern ops_dat celldx; // xdif
extern ops_dat celldy; // ydif
extern ops_dat facedx; // xcv
extern ops_dat facedy; // ycv
extern ops_dat xcvs; // xcvs
extern ops_dat ycvs; // ycvs
extern ops_dat xcvi; // xcvi
extern ops_dat xcvip; // xcvip
extern ops_dat ycvr; // ycvr
extern ops_dat ycvrs; // ycvrs

extern ops_dat arx;
extern ops_dat arxj;
extern ops_dat arxjp;
extern ops_dat radius;
extern ops_dat rmn;

extern ops_dat sx;
extern ops_dat sxmn;


extern ops_dat xvel0; // U
extern ops_dat yvel0; // V
extern ops_dat presscorr; // PC
extern ops_dat density; // RHO
extern ops_dat temperature; // T
extern ops_dat xvelhat; // UHAT
extern ops_dat yvelhat; // VHAT

//commonly used stencils
extern ops_stencil S2D_00; // 00
extern ops_stencil S2D_00_P10; // 00:10
extern ops_stencil S2D_00_M10; // 00:-10
extern ops_stencil S2D_00_0P1; // 00:01
extern ops_stencil S2D_00_0M1; // 00:0-1
extern ops_stencil S2D_00_P10_M10; //00:10:-10
extern ops_stencil S2D_00_P10_M10_0P1_0M1;

extern FILE *fp;

//extern string title();
//extern bool lsolve(),lprint(),lblk(),lstop;

extern double xmin;
extern double ymin;
extern double xmax;
extern double ymax;
extern double xlength;
extern double ylength;
extern int xcells;
extern int ycells;
extern int xL1;
extern int xL2;
extern int xL3;
extern int yM1;
extern int yM2;
extern int yM3;
extern int iter;
extern bool lsolve[14];
extern bool lprint[14];
extern bool lblk[14];
extern bool lstop;
extern string title[14];

extern int coordmode;


#endif /* FVM2DC_GLOBALVARS_H_ */
