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

extern string title[NFX4]; //simper95.for变量title，不同变量的标题
extern int lsolve[NFX4]; //simper95.for变量lsolve，控制该变量是否要求解
extern int lprint[NFX4]; //simper95.for变量lprint，控制该变量是否打印
extern int lblk[NFX4]; //simper95.for变量lblk，控制该变量是否采用块修正技术
extern int lstop; //simper95.for变量lstop，全局控制是否停止程序

//ops block
extern ops_block fvm2dc_grid; //grid,网格，

//ops dats
extern ops_dat xu_facex; // simper95.for变量xu
extern ops_dat x_cellx; // simper95.for变量x
extern ops_dat xdif_celldx; // simper95.for变量xdif
extern ops_dat xcv_facedx; // simper95.for变量xcv
extern ops_dat xcvs; // simper95.for变量xcvs
extern ops_dat xcvi; // simper95.for变量xcvi
extern ops_dat xcvip; // simper95.for变量xcvip
extern ops_dat fx; //simper95.for变量fx
extern ops_dat fxm; //simper95.for变量fxm


extern ops_dat yv_facey; // simper95.for变量yv
extern ops_dat y_celly; // simper95.for变量y
extern ops_dat ydif_celldy; // simper95.for变量ydif
extern ops_dat ycv_facedy; // simper95.for变量ycv
extern ops_dat ycvs; // simper95.for变量ycvs
extern ops_dat ycvr; // simper95.for变量ycvr
extern ops_dat ycvrs; // simper95.for变量ycvrs
extern ops_dat fy; //simper95.for变量fy
extern ops_dat fym; //simper95.for变量fym

extern ops_dat radius; //simper95.for变量r
extern ops_dat sx; //simper95.for变量sx
extern ops_dat rmn; //simper95.for变量rmn
extern ops_dat sxmn; //simper95.for变量sxmn
extern ops_dat arx; //simper95.for变量arx
extern ops_dat arxj; //simper95.for变量arxj
extern ops_dat arxjp; //simper95.for变量arxjp
extern ops_dat fv; //simper95.for变量fv
extern ops_dat fvp; //simper95.for变量fvp

extern ops_dat pt; //simper95.for变量pt
extern ops_dat qt; //simper95.for变量qt

extern ops_dat u_xvel0; // simper95.for变量U
extern ops_dat v_yvel0; // simper95.for变量V
extern ops_dat pc_presscorr; // simper95.for变量PC
extern ops_dat t_temperature; // simper95.for变量T
extern ops_dat du_deltaxvel0; // simper95.for变量dU
extern ops_dat dv_deltayvel0; // simper95.for变量dV
extern ops_dat uhat_xvelhat; // simper95.for变量UHAT
extern ops_dat vhat_yvelhat; // simper95.for变量VHAT

extern ops_dat pressure; // simper95.for变量P
extern ops_dat density; // simper95.for变量RHO
extern ops_dat gam; // simper95.for变量GAM
extern ops_dat cp; // simper95.for变量cp

extern ops_dat con; // simper95.for变量con,cof1
extern ops_dat aip; // simper95.for变量aip,cof2
extern ops_dat aim; // simper95.for变量aim,cof3
extern ops_dat ajp; // simper95.for变量ajp,cof4
extern ops_dat ajm; // simper95.for变量ajm,cof5
extern ops_dat app; // simper95.for变量ap,cof6

extern ops_dat ucon; // simper95.for变量ucon,cofu1
extern ops_dat uaip; // simper95.for变量uaip,cofu2
extern ops_dat uaim; // simper95.for变量uaim,cofu3
extern ops_dat uajp; // simper95.for变量uajp,cofu4
extern ops_dat uajm; // simper95.for变量uajm,cofu5
extern ops_dat uapp; // simper95.for变量uap,cofu6

extern ops_dat vcon; // simper95.for变量vcon,cofv1
extern ops_dat vaip; // simper95.for变量vaip,cofv2
extern ops_dat vaim; // simper95.for变量vaim,cofv3
extern ops_dat vajp; // simper95.for变量vajp,cofv4
extern ops_dat vajm; // simper95.for变量vajm,cofv5
extern ops_dat vapp; // simper95.for变量vap,cofv6

extern ops_dat pcon; // simper95.for变量pcon,cof1
extern ops_dat paip; // simper95.for变量paip,cof2
extern ops_dat paim; // simper95.for变量paim,cof3
extern ops_dat pajp; // simper95.for变量pajp,cof4
extern ops_dat pajm; // simper95.for变量pajm,cof5
extern ops_dat papp; // simper95.for变量pap,cof6

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

extern double xlength; //simper95.for变量xl
extern double ylength; //simper95.for变量yl

extern double relax[NFX4]; //simper95.for变量relax，松弛因子
extern double ttime; //simper95.for变量time
extern double dt; //simper95.for变量dt
extern double rhocon; //simper95.for变量rhocon
extern double cpcon; //simper95.for变量cpcon

extern int xL1; //simper95.for变量L1
extern int xL2; //simper95.for变量L2
extern int xL3; //simper95.for变量L3
extern int yM1; //simper95.for变量M1
extern int yM2; //simper95.for变量M2
extern int yM3; //simper95.for变量M3
extern int iter; //simper95.for变量iter

extern double smax; //simper95.for变量smax
extern double ssum; //simper95.for变量ssum
extern double flow; //simper95.for变量flow
extern double diff; //simper95.for变量diff
extern double acof; //simper95.for变量acof

extern int nf; //simper95.for变量nf
extern int np; //simper95.for变量np
extern int nrho; //simper95.for变量nrho
extern int ngam; //simper95.for变量ngam
extern int ncp; //simper95.for变量ncp
extern int istart; //simper95.for变量istart
extern int jstart; //simper95.for变量jstart
extern int last; //simper95.for变量last
extern int ntimes[NFX4]; //simper95.for变量ntimes
extern int ipref; //simper95.for变量ipref
extern int jpref; //simper95.for变量jpref

extern int coordmode; //simper95.for变量mode

#endif /* FVM2DC_GLOBALVARS_H_ */
