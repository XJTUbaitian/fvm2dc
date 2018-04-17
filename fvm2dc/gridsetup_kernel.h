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

#ifndef FVM2DC_GRIDSETUP_KERNEL_H_
#define FVM2DC_GRIDSETUP_KERNEL_H_

#include "globalvars.h"

void gridsetup_kernel_setupX(double *xu_facex, double *x_cellx,
		double *xdif_celldx, double *xcv_facedx, double *xcvs, double *xcvi,
		double *xcvip, double *fx, double *fxm, int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是

	if (idx[0] == 1) {
		xu_facex[OPS_ACC0(0, 0)] = xmin;//simpler.f90中xu(2)=0,没管xu(1),我们这里给它一个xmin，
		x_cellx[OPS_ACC1(0, 0)] = xmin;//同上，x(1)是边界点
		xdif_celldx[OPS_ACC2(0, 0)] = 0.0;
		xcv_facedx[OPS_ACC3(0, 0)] = 0.0;
		xcvs[OPS_ACC4(0, 0)] = 0.0;
		xcvi[OPS_ACC5(0, 0)] = 0.0;
		xcvip[OPS_ACC6(0, 0)] = 0.0;
		fx[OPS_ACC7(0, 0)] = 0.0;
		fxm[OPS_ACC8(0, 0)] = 0.0;
	} else if (idx[0] == 2) {
		xu_facex[OPS_ACC0(0, 0)] = xmin; //simpler.f90中xu(2)=0,没管xu(1),
		x_cellx[OPS_ACC1(0, 0)] = xmin + d_x / 2.0;//x(2)就是内点了，
		xdif_celldx[OPS_ACC2(0, 0)] = d_x / 2.0;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = 0.0;
		xcvi[OPS_ACC5(0, 0)] = 0.0;
		xcvip[OPS_ACC6(0, 0)] = d_x;
		fx[OPS_ACC7(0, 0)] = 0.0;
		fxm[OPS_ACC8(0, 0)] = 1.0;
	} else if (idx[0] == 3) {
		xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 2.0);
		x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0; //simpler.f90的处理方式x(i)依赖于x(i-1),递推，不易并行
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x + d_x / 2.0;
		xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
		xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
		fx[OPS_ACC7(0, 0)] = 0.5;
		fxm[OPS_ACC8(0, 0)] = 0.5;
	} else if (idx[0] == xL3) {
		xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 2.0);
		x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x;
		xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
		xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
		fx[OPS_ACC7(0, 0)] = 0.5;
		fxm[OPS_ACC8(0, 0)] = 0.5;
	} else if (idx[0] == xL2) {
		xu_facex[OPS_ACC0(0, 0)] = xmax - d_x;
		x_cellx[OPS_ACC1(0, 0)] = xmax - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x + d_x / 2.0;
		xcvi[OPS_ACC5(0, 0)] = d_x;
		xcvip[OPS_ACC6(0, 0)] = 0.0;
		fx[OPS_ACC7(0, 0)] = 0.5;
		fxm[OPS_ACC8(0, 0)] = 0.5;
	} else if (idx[0] == xL1) {
		xu_facex[OPS_ACC0(0, 0)] = xmax;
		x_cellx[OPS_ACC1(0, 0)] = xmax;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x / 2.0;
		xcv_facedx[OPS_ACC3(0, 0)] = 0.0;
		xcvs[OPS_ACC4(0, 0)] = 0.0;
		xcvi[OPS_ACC5(0, 0)] = 0.0;
		xcvip[OPS_ACC6(0, 0)] = 0.0;
		fx[OPS_ACC7(0, 0)] = 1.0;
		fxm[OPS_ACC8(0, 0)] = 0.0;
	} else {
		xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 2.0);
		x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x;
		xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
		xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
		fx[OPS_ACC7(0, 0)] = 0.5;
		fxm[OPS_ACC8(0, 0)] = 0.5;
	}

}

void gridsetup_kernel_setupY_Common(double *yv_facey, double *y_celly,
		double *ydif_celldy, double *ycv_facedy, double *ycvs, double *fy,
		double *fym, int *idx) {

	double d_y;
	d_y = (ymax - ymin) / (double) ycells;
	if (idx[1] == 1) {
		yv_facey[OPS_ACC0(0, 0)] = ymin;
		y_celly[OPS_ACC1(0, 0)] = ymin;
		ydif_celldy[OPS_ACC2(0, 0)] = 0.0;
		ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;

	} else if (idx[1] == 2) {
		yv_facey[OPS_ACC0(0, 0)] = ymin;
		y_celly[OPS_ACC1(0, 0)] = ymin + d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y / 2.0;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == 3) {
		yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
		y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y + d_y / 2.0;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == yM3) {
		yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
		y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == yM2) {
		yv_facey[OPS_ACC0(0, 0)] = ymax - d_y;
		y_celly[OPS_ACC1(0, 0)] = ymax - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y + d_y / 2.0;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == yM1) {
		yv_facey[OPS_ACC0(0, 0)] = ymax;
		y_celly[OPS_ACC1(0, 0)] = ymax;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y / 2.0;
		ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;
	} else {
		yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
		y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y;
		fy[OPS_ACC5(0, 0)] = 0.0;
		fym[OPS_ACC6(0, 0)] = 0.0;
	}

}

void gridsetup_kernel_setupY_Cartesian(double *radius, double *sx, double *rmn,
		double *sxmn, double *ycvr, double *ycvrs, double *arx, double *arxj,
		double *arxjp, double *fv, double *fvp, int *idx) {

	double d_y;
	d_y = (ymax - ymin) / (double) ycells;

	if (idx[1] == 1) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = 0.0;
		ycvrs[OPS_ACC5(0, 0)] = 0.0;
		arx[OPS_ACC6(0, 0)] = 0.0;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;

	} else if (idx[1] == 2) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC50(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = d_y;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == 3) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y + d_y / 2.0;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM3) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM2) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y + d_y / 2.0;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM1) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = 0.0;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	}

}

void gridsetup_kernel_setupY_Cylindrical(double *radius, double *sx,
		double *rmn, double *sxmn, double *ycvr, double *ycvrs, double *arx,
		double *arxj, double *arxjp, double *fv, double *fvp, int *idx) {

	double d_y;
	d_y = (ymax - ymin) / (double) ycells;

	if (idx[1] == 1) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = 0.0;
		ycvrs[OPS_ACC5(0, 0)] = 0.0;
		arx[OPS_ACC6(0, 0)] = 0.0;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;

	} else if (idx[1] == 2) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC50(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = d_y;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == 3) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y + d_y / 2.0;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM3) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM2) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y + d_y / 2.0;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM1) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = 0.0;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	}
}

void gridsetup_kernel_setupY_Polar(double *radius, double *sx, double *rmn,
		double *sxmn, double *ycvr, double *ycvrs, double *arx, double *arxj,
		double *arxjp, double *fv, double *fvp, int *idx) {

	double d_y;
	d_y = (ymax - ymin) / (double) ycells;

	if (idx[1] == 1) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = 0.0;
		ycvrs[OPS_ACC5(0, 0)] = 0.0;
		arx[OPS_ACC6(0, 0)] = 0.0;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;

	} else if (idx[1] == 2) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC50(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = d_y;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == 3) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y + d_y / 2.0;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM3) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM2) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y + d_y / 2.0;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else if (idx[1] == yM1) {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = 0.0;
		arxj[OPS_ACC7(0, 0)] = 0.0;
		arxjp[OPS_ACC8(0, 0)] = 0.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	} else {
		radius[OPS_ACC0(0, 0)] = 1.0;
		sx[OPS_ACC1(0, 0)] = 1.0;
		rmn[OPS_ACC2(0, 0)] = 1.0;
		sxmn[OPS_ACC3(0, 0)] = 1.0;
		ycvr[OPS_ACC4(0, 0)] = d_y;
		ycvrs[OPS_ACC5(0, 0)] = d_y;
		arx[OPS_ACC6(0, 0)] = d_y;
		arxj[OPS_ACC7(0, 0)] = d_y / 2.0;
		arxjp[OPS_ACC8(0, 0)] = d_y / 2.0;
		fv[OPS_ACC9(0, 0)] = 0.0;
		fvp[OPS_ACC10(0, 0)] = 0.0;
	}

}

#endif /* FVM2DC_GRIDSETUP_KERNEL_H_ */

