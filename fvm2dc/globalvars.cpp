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
ops_block fvm2dc_grid; //grid,网格

//ops dats
ops_dat xu_facex; // simper95.for变量xu
ops_dat x_cellx; // simper95.for变量x
ops_dat xdif_celldx; // simper95.for变量xdif
ops_dat xcv_facedx; // simper95.for变量xcv
ops_dat xcvs; // simper95.for变量xcvs
ops_dat xcvi; // simper95.for变量xcvi
ops_dat xcvip; // simper95.for变量xcvip

ops_dat yv_facey; // simper95.for变量yv
ops_dat y_celly; // simper95.for变量y
ops_dat ydif_celldy; // simper95.for变量ydif
ops_dat ycv_facedy; // simper95.for变量ycv
ops_dat ycvs; // simper95.for变量ycvs
ops_dat ycvr; // simper95.for变量ycvr
ops_dat ycvrs; // simper95.for变量ycvrs

ops_dat arx; //simper95.for变量arx
ops_dat arxj; //simper95.for变量arxj
ops_dat arxjp; //simper95.for变量arxjp

ops_dat radius; //simper95.for变量r
ops_dat rmn; //simper95.for变量rmn

ops_dat sx; //simper95.for变量sx
ops_dat sxmn; //simper95.for变量sxmn


ops_dat fv; //simper95.for变量fv
ops_dat fvp; //simper95.for变量fvp
ops_dat fx; //simper95.for变量fx
ops_dat fxm; //simper95.for变量fxm
ops_dat fy; //simper95.for变量fy
ops_dat fym; //simper95.for变量fym
ops_dat pt; //simper95.for变量pt
ops_dat qt; //simper95.for变量qt

ops_dat u_xvel0; // simper95.for变量U
ops_dat v_yvel0; // simper95.for变量V
ops_dat pc_presscorr; // simper95.for变量PC
ops_dat t_temperature; // simper95.for变量T
ops_dat du_deltaxvel0; // simper95.for变量dU
ops_dat dv_deltayvel0; // simper95.for变量dV
ops_dat uhat_xvelhat; // simper95.for变量UHAT
ops_dat vhat_yvelhat; // simper95.for变量VHAT

ops_dat pressure; // simper95.for变量P
ops_dat density; // simper95.for变量RHO
ops_dat gam; // simper95.for变量GAM
ops_dat cp; // simper95.for变量cp

ops_dat con; // simper95.for变量con
ops_dat aip; // simper95.for变量aip
ops_dat aim; // simper95.for变量aim
ops_dat ajp; // simper95.for变量ajp
ops_dat ajm; // simper95.for变量ajm
ops_dat app; // simper95.for变量ap

ops_dat ucon; // simper95.for变量ucon,cofu1
ops_dat uaip; // simper95.for变量uaip,cofu2
ops_dat uaim; // simper95.for变量uaim,cofu3
ops_dat uajp; // simper95.for变量uajp,cofu4
ops_dat uajm; // simper95.for变量uajm,cofu5
ops_dat uapp; // simper95.for变量uap,cofu6

ops_dat vcon; // simper95.for变量vcon,cofv1
ops_dat vaip; // simper95.for变量vaip,cofv2
ops_dat vaim; // simper95.for变量vaim,cofv3
ops_dat vajp; // simper95.for变量vajp,cofv4
ops_dat vajm; // simper95.for变量vajm,cofv5
ops_dat vapp; // simper95.for变量vap,cofv6

ops_dat pcon; // simper95.for变量pcon,cof1
ops_dat paip; // simper95.for变量paip,cof2
ops_dat paim; // simper95.for变量paim,cof3
ops_dat pajp; // simper95.for变量pajp,cof4
ops_dat pajm; // simper95.for变量pajm,cof5
ops_dat papp; // simper95.for变量pap,cof6


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
int xcells;
int ycells;
double xlength; //simper95.for变量xl
double ylength; //simper95.for变量yl


int xL1; //simper95.for变量L1
int xL2; //simper95.for变量L2
int xL3; //simper95.for变量L3
int yM1; //simper95.for变量M1
int yM2; //simper95.for变量M2
int yM3; //simper95.for变量M3
int iter; //simper95.for变量iter

double smax; //simper95.for变量smax
double ssum; //simper95.for变量ssum
double flow; //simper95.for变量flow
double diff; //simper95.for变量diff
double acof; //simper95.for变量acof

int nf; //simper95.for变量nf
int np; //simper95.for变量np
int nrho; //simper95.for变量nrho
int ngam; //simper95.for变量ngam
int ncp; //simper95.for变量ncp
int istart; //simper95.for变量istart
int jstart; //simper95.for变量jstart
int last; //simper95.for变量last
int ntimes[NFX4]; //simper95.for变量ntimes
int ipref; //simper95.for变量ipref
int jpref; //simper95.for变量jpref

int coordmode; //simper95.for变量mode
