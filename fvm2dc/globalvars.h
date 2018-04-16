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

//**************************
//parameters in simpler95.for
//**************************
#define NI 100 //NI
#define NJ 200 //NJ
#define NIJ NI //NIJ
#define NFMAX 10 //NFMAX
#define NFX4 NFMAX+4 //NFX4

using namespace std;

extern string title[NFX4]; //原来的变量title，不同变量的标题
extern int lsolve[NFX4]; //原来的变量lsolve，控制该变量是否要求解
extern int lprint[NFX4]; //原来的变量lprint，控制该变量是否打印
extern int lblk[NFX4]; //原来的变量lblk，控制该变量是否采用块修正技术
extern int lstop; //原来的变量lstop，全局控制是否停止程序

//ops block
extern ops_block fvm2dc_grid; //grid,网格，

//ops dats
extern ops_dat facex; // 原来的变量xu
extern ops_dat facey; // 原来的变量yv
extern ops_dat cellx; // 原来的变量x
extern ops_dat celly; // 原来的变量y
extern ops_dat celldx; // 原来的变量xdif
extern ops_dat celldy; // 原来的变量ydif
extern ops_dat facedx; // 原来的变量xcv
extern ops_dat facedy; // 原来的变量ycv
extern ops_dat xcvs; // 原来的变量xcvs
extern ops_dat ycvs; // 原来的变量ycvs
extern ops_dat xcvi; // 原来的变量xcvi
extern ops_dat xcvip; // 原来的变量xcvip
extern ops_dat ycvr; // 原来的变量ycvr
extern ops_dat ycvrs; // 原来的变量ycvrs

extern ops_dat arx; //原来的变量arx
extern ops_dat arxj; //原来的变量arxj
extern ops_dat arxjp; //原来的变量arxjp

extern ops_dat radius; //原来的变量r
extern ops_dat rmn; //原来的变量rmn

extern ops_dat sx; //原来的变量sx
extern ops_dat sxmn; //原来的变量sxmn

extern ops_dat fv; //原来的变量fv
extern ops_dat fvp; //原来的变量fvp
extern ops_dat fx; //原来的变量fx
extern ops_dat fxm; //原来的变量fxm
extern ops_dat fy; //原来的变量fy
extern ops_dat fym; //原来的变量fym
extern ops_dat pt; //原来的变量pt
extern ops_dat qt; //原来的变量qt

extern ops_dat xvel0; // 原来的变量U
extern ops_dat yvel0; // 原来的变量V
extern ops_dat presscorr; // 原来的变量PC
extern ops_dat temperature; // 原来的变量T
extern ops_dat deltaxvel0; // 原来的变量dU
extern ops_dat deltayvel0; // 原来的变量dV
extern ops_dat xvelhat; // 原来的变量UHAT
extern ops_dat yvelhat; // 原来的变量VHAT

extern ops_dat pressure; // 原来的变量P
extern ops_dat density; // 原来的变量RHO
extern ops_dat gam; // 原来的变量GAM
extern ops_dat cp; // 原来的变量cp

extern ops_dat con; // 原来的变量con,cof1
extern ops_dat aip; // 原来的变量aip,cof2
extern ops_dat aim; // 原来的变量aim,cof3
extern ops_dat ajp; // 原来的变量ajp,cof4
extern ops_dat ajm; // 原来的变量ajm,cof5
extern ops_dat app; // 原来的变量ap,cof6

extern ops_dat ucon; // 原来的变量ucon,cofu1
extern ops_dat uaip; // 原来的变量uaip,cofu2
extern ops_dat uaim; // 原来的变量uaim,cofu3
extern ops_dat uajp; // 原来的变量uajp,cofu4
extern ops_dat uajm; // 原来的变量uajm,cofu5
extern ops_dat uapp; // 原来的变量uap,cofu6

extern ops_dat vcon; // 原来的变量vcon,cofv1
extern ops_dat vaip; // 原来的变量vaip,cofv2
extern ops_dat vaim; // 原来的变量vaim,cofv3
extern ops_dat vajp; // 原来的变量vajp,cofv4
extern ops_dat vajm; // 原来的变量vajm,cofv5
extern ops_dat vapp; // 原来的变量vap,cofv6

extern ops_dat pcon; // 原来的变量pcon,cof1
extern ops_dat paip; // 原来的变量paip,cof2
extern ops_dat paim; // 原来的变量paim,cof3
extern ops_dat pajp; // 原来的变量pajp,cof4
extern ops_dat pajm; // 原来的变量pajm,cof5
extern ops_dat papp; // 原来的变量pap,cof6

//commonly used stencils
extern ops_stencil S2D_00; // 00
extern ops_stencil S2D_00_P10; // 00:10
extern ops_stencil S2D_00_M10; // 00:-10
extern ops_stencil S2D_00_0P1; // 00:01
extern ops_stencil S2D_00_0M1; // 00:0-1
extern ops_stencil S2D_00_P10_M10; //00:10:-10
extern ops_stencil S2D_00_P10_M10_0P1_0M1; //00:10:-10:01:0-1

extern FILE *fp;

extern double xmin;
extern double ymin;
extern double xmax;
extern double ymax;
extern int xcells;
extern int ycells;

extern double xlength; //原来的变量xl
extern double ylength; //原来的变量yl

extern double relax[NFX4]; //原来的变量relax，松弛因子
extern double ttime; //原来的变量time
extern double dt; //原来的变量dt
extern double rhocon; //原来的变量rhocon
extern double cpcon; //原来的变量cpcon

extern int xL1; //原来的变量L1
extern int xL2; //原来的变量L2
extern int xL3; //原来的变量L3
extern int yM1; //原来的变量M1
extern int yM2; //原来的变量M2
extern int yM3; //原来的变量M3
extern int iter; //原来的变量iter

extern double smax; //原来的变量smax
extern double ssum; //原来的变量ssum
extern double flow; //原来的变量flow
extern double diff; //原来的变量diff
extern double acof; //原来的变量acof

extern int nf; //原来的变量nf
extern int np; //原来的变量np
extern int nrho; //原来的变量nrho
extern int ngam; //原来的变量ngam
extern int ncp; //原来的变量ncp
extern int istart; //原来的变量istart
extern int jstart; //原来的变量jstart
extern int last; //原来的变量last
extern int ntimes[NFX4]; //原来的变量ntimes
extern int ipref; //原来的变量ipref
extern int jpref; //原来的变量jpref

extern int coordmode; //原来的变量mode

#endif /* FVM2DC_GLOBALVARS_H_ */
