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
//parameters in simpler95
//**************************
#define NI 100 //NI
#define NJ 200 //NJ
#define NIJ NI //NIJ
#define NFMAX 10 //NFMAX
#define NFX4 NFMAX+4 //NFX4

using namespace std;

extern string title[NFX4]; //simper95变量title，不同变量的标题
extern int lsolve[NFX4]; //simper95变量lsolve，控制该变量是否要求解
extern int lprint[NFX4]; //simper95变量lprint，控制该变量是否打印
extern int lblk[NFX4]; //simper95变量lblk，控制该变量是否采用块修正技术
extern int lstop; //simper95变量lstop，全局控制是否停止程序
extern double relax[NFX4]; //simper95变量relax，松弛因子

//********************************************************
//网格相关的几何变量
//********************************************************

//ops block
extern ops_block fvm2dc_grid; //grid,网格handle

//ops dats
extern ops_dat xu; // simper95变量xu
extern ops_dat xx; // simper95变量x
extern ops_dat xdif; // simper95变量xdif
extern ops_dat xcv; // simper95变量xcv
extern ops_dat xcvs; // simper95变量xcvs
extern ops_dat xcvi; // simper95变量xcvi
extern ops_dat xcvip; // simper95变量xcvip
extern ops_dat fx; //simper95变量fx
extern ops_dat fxm; //simper95变量fxm

extern ops_dat yv; // simper95变量yv
extern ops_dat yy; // simper95变量y
extern ops_dat ydif; // simper95变量ydif
extern ops_dat ycv; // simper95变量ycv
extern ops_dat ycvs; // simper95变量ycvs
extern ops_dat fy; //simper95变量fy
extern ops_dat fym; //simper95变量fym

extern ops_dat rr; //simper95变量r
extern ops_dat sx; //simper95变量sx

extern ops_dat rmn; //simper95变量rmn
extern ops_dat sxmn; //simper95变量sxmn

extern ops_dat arx; //simper95变量arx
extern ops_dat arxj; //simper95变量arxj
extern ops_dat arxjp; //simper95变量arxjp

extern ops_dat ycvr; // simper95变量ycvr
extern ops_dat ycvrs; // simper95变量ycvrs

extern ops_dat fv; //simper95变量fv
extern ops_dat fvp; //simper95变量fvp

//********************************************************
//网格相关的几何变量结束
//********************************************************

extern ops_dat pt; //simper95变量pt
extern ops_dat qt; //simper95变量qt

extern ops_dat uxvel; // simper95变量U
extern ops_dat vyvel; // simper95变量V
extern ops_dat pc_presscorr; // simper95变量PC
extern ops_dat t_temperature; // simper95变量T
extern ops_dat du_deltauxvel; // simper95变量dU
extern ops_dat dv_deltavyvel; // simper95变量dV
extern ops_dat uhat_xvelhat; // simper95变量UHAT
extern ops_dat vhat_yvelhat; // simper95变量VHAT

extern ops_dat pressure; // simper95变量P
extern ops_dat rho; // simper95变量RHO
extern ops_dat gam; // simper95变量GAM
extern ops_dat cp; // simper95变量cp

extern ops_dat con; // simper95变量con,cof1
extern ops_dat aip; // simper95变量aip,cof2
extern ops_dat aim; // simper95变量aim,cof3
extern ops_dat ajp; // simper95变量ajp,cof4
extern ops_dat ajm; // simper95变量ajm,cof5
extern ops_dat app; // simper95变量ap,cof6

extern ops_dat ucon; // simper95变量ucon,cofu1
extern ops_dat uaip; // simper95变量uaip,cofu2
extern ops_dat uaim; // simper95变量uaim,cofu3
extern ops_dat uajp; // simper95变量uajp,cofu4
extern ops_dat uajm; // simper95变量uajm,cofu5
extern ops_dat uapp; // simper95变量uap,cofu6

extern ops_dat vcon; // simper95变量vcon,cofv1
extern ops_dat vaip; // simper95变量vaip,cofv2
extern ops_dat vaim; // simper95变量vaim,cofv3
extern ops_dat vajp; // simper95变量vajp,cofv4
extern ops_dat vajm; // simper95变量vajm,cofv5
extern ops_dat vapp; // simper95变量vap,cofv6

extern ops_dat pcon; // simper95变量pcon,cof1
extern ops_dat paip; // simper95变量paip,cof2
extern ops_dat paim; // simper95变量paim,cof3
extern ops_dat pajp; // simper95变量pajp,cof4
extern ops_dat pajm; // simper95变量pajm,cof5
extern ops_dat papp; // simper95变量pap,cof6

//commonly used stencils
extern ops_stencil S2D_00; // 00
extern ops_stencil S2D_00_P10; // 00:10
extern ops_stencil S2D_00_M10; // 00:-10
extern ops_stencil S2D_00_0P1; // 00:01
extern ops_stencil S2D_00_0M1; // 00:0-1
extern ops_stencil S2D_00_P10_M10; //00:10:-10
extern ops_stencil S2D_00_0P1_0M1; //00:01:0-1
extern ops_stencil S2D_00_P10_M10_0P1_0M1; //00:10:-10:01:0-1

extern ops_stencil S2D_00_STRID2D_X; // 00
extern ops_stencil S2D_00_P10_STRID2D_X; // 00:10
extern ops_stencil S2D_00_M10_STRID2D_X; // 00:-10
extern ops_stencil S2D_00_P10_M10_STRID2D_X; //00:10:-10

extern ops_stencil S2D_00_STRID2D_Y; // 00
extern ops_stencil S2D_00_0P1_STRID2D_Y; // 00:01
extern ops_stencil S2D_00_0M1_STRID2D_Y; // 00:0-1
extern ops_stencil S2D_00_0P1_0M1_STRID2D_Y; //00:01:0-1

extern FILE *fp;

extern double xmin;
extern double ymin;
extern double xmax;
extern double ymax;
extern int xcells;
extern int ycells;

extern double xlength; //simper95变量xl
extern double ylength; //simper95变量yl

extern double ttime; //simper95变量time
extern double dt; //simper95变量dt
extern double rhocon; //simper95变量rhocon
extern double cpcon; //simper95变量cpcon

extern int xL1; //simper95变量L1
extern int xL2; //simper95变量L2
extern int xL3; //simper95变量L3
extern int yM1; //simper95变量M1
extern int yM2; //simper95变量M2
extern int yM3; //simper95变量M3
extern int iter; //simper95变量iter

extern double smax; //simper95变量smax
extern double ssum; //simper95变量ssum
extern double flow; //simper95变量flow
extern double diff; //simper95变量diff
extern double acof; //simper95变量acof

extern int nf; //simper95变量nf
extern int np; //simper95变量np
extern int nrho; //simper95变量nrho
extern int ngam; //simper95变量ngam
extern int ncp; //simper95变量ncp
extern int istart; //simper95变量istart
extern int jstart; //simper95变量jstart
extern int last; //simper95变量last
extern int ntimes[NFX4]; //simper95变量ntimes
extern int ipref; //simper95变量ipref
extern int jpref; //simper95变量jpref

extern int coordmode; //simper95变量mode

#endif /* FVM2DC_GLOBALVARS_H_ */
