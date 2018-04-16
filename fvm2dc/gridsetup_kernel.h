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
		double *xcvip, int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是

	if (idx[0] == 0) {
		xu_facex[OPS_ACC0(0, 0)] = xmin;
		x_cellx[OPS_ACC1(0, 0)] = xmin;
		xdif_celldx[OPS_ACC2(0, 0)] = 0.0;
		xcv_facedx[OPS_ACC3(0, 0)] = 0.0;
		xcvs[OPS_ACC4(0, 0)] = 0.0;
		xcvi[OPS_ACC5(0, 0)] = 0.0;
		xcvip[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[0] == 1) {
		xu_facex[OPS_ACC0(0, 0)] = xmin;
		x_cellx[OPS_ACC1(0, 0)] = xmin + d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x / 2.0;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = 0.0;
		xcvi[OPS_ACC5(0, 0)] = 0.0;
		xcvip[OPS_ACC6(0, 0)] = d_x;
	} else if (idx[0] == 2) {
		xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1.0);
		x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x + d_x / 2.0;
		xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
		xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
	} else if (idx[0] == xL3 - 1) {
		xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1.0);
		x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x;
		xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
		xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
	} else if (idx[0] == xL2 - 1) {
		xu_facex[OPS_ACC0(0, 0)] = xmax - d_x;
		x_cellx[OPS_ACC1(0, 0)] = xmax - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x + d_x / 2.0;
		xcvi[OPS_ACC5(0, 0)] = d_x;
		xcvip[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[0] == xL1 - 1) {
		xu_facex[OPS_ACC0(0, 0)] = xmax;
		x_cellx[OPS_ACC1(0, 0)] = xmax;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x / 2.0;
		xcv_facedx[OPS_ACC3(0, 0)] = 0.0;
		xcvs[OPS_ACC4(0, 0)] = 0.0;
		xcvi[OPS_ACC5(0, 0)] = 0.0;
		xcvip[OPS_ACC6(0, 0)] = 0.0;
	} else {
		xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1.0);
		x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
		xdif_celldx[OPS_ACC2(0, 0)] = d_x;
		xcv_facedx[OPS_ACC3(0, 0)] = d_x;
		xcvs[OPS_ACC4(0, 0)] = d_x;
		xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
		xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
	}

}

void gridsetup_kernel_setupY_Cartesian(double *yv_facey, double *y_celly,
		double *ydif_celldy, double *ycv_facedy, double *ycvs, double *ycvr,
		double *ycvrs, int *idx) {
	double d_y;
	d_y = (ymax - ymin) / (double) ycells;

	if (idx[1] == 0) {
		yv_facey[OPS_ACC0(0, 0)] = ymin;
		y_celly[OPS_ACC1(0, 0)] = ymin;
		ydif_celldy[OPS_ACC2(0, 0)] = 0.0;
		ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		ycvr[OPS_ACC5(0, 0)] = 0.0;
		ycvrs[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == 1) {
		yv_facey[OPS_ACC0(0, 0)] = ymin;
		y_celly[OPS_ACC1(0, 0)] = ymin + d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y / 2.0;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		ycvr[OPS_ACC5(0, 0)] = 0.0;
		ycvrs[OPS_ACC6(0, 0)] = d_y;
	} else if (idx[1] == 2) {

		yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
		y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y + d_y / 2.0;
		ycvr[OPS_ACC5(0, 0)] = d_y / 2.0;
		ycvrs[OPS_ACC6(0, 0)] = d_y / 2.0;

	} else if (idx[1] == yM3 - 1) {
		yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
		y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y;
		ycvr[OPS_ACC5(0, 0)] = d_y / 2.0;
		ycvrs[OPS_ACC6(0, 0)] = d_y / 2.0;

	} else if (idx[1] == yM2 - 1) {
		yv_facey[OPS_ACC0(0, 0)] = ymax - d_y;
		y_celly[OPS_ACC1(0, 0)] = ymax - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y + d_y / 2.0;
		ycvr[OPS_ACC5(0, 0)] = d_y;
		ycvrs[OPS_ACC6(0, 0)] = 0.0;

	} else if (idx[1] == yM1 - 1) {
		yv_facey[OPS_ACC0(0, 0)] = ymax;
		y_celly[OPS_ACC1(0, 0)] = ymax;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y / 2.0;
		ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		ycvr[OPS_ACC5(0, 0)] = 0.0;
		ycvrs[OPS_ACC6(0, 0)] = 0.0;

	} else {
		yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
		y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
		ydif_celldy[OPS_ACC2(0, 0)] = d_y;
		ycv_facedy[OPS_ACC3(0, 0)] = d_y;
		ycvs[OPS_ACC4(0, 0)] = d_y;
		ycvr[OPS_ACC5(0, 0)] = d_y / 2.0;
		ycvrs[OPS_ACC6(0, 0)] = d_y / 2.0;

	}

}

void gridsetup_kernel_setupY_Cylindrical(double *yv_facey, double *y_celly,
		double *ydif_celldy, double *ycv_facedy, double *ycvs, double *ycvr,
		double *ycvrs, int *idx) {
	double d_y;
	d_y = (ymax - ymin) / (double) ycells;

	if (idx[1] == 0) {
		yv_facey[OPS_ACC0(0, 0)] = ymin;
		y_celly[OPS_ACC1(0, 0)] = ymin;
		ydif_celldy[OPS_ACC2(0, 0)] = 0.0;
		ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		ycvr[OPS_ACC5(0, 0)] = 0.0;
		ycvrs[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == 1) {

	} else if (idx[1] == 2) {

	} else if (idx[1] == yM3 - 1) {

	} else if (idx[1] == yM2 - 1) {

	} else if (idx[1] == yM1 - 1) {

	} else {

	}

}

void gridsetup_kernel_setupY_Polar(double *yv_facey, double *y_celly,
		double *ydif_celldy, double *ycv_facedy, double *ycvs, double *ycvr,
		double *ycvrs, int *idx) {
	double d_y;
	d_y = (ymax - ymin) / (double) ycells;

	if (idx[1] == 0) {
		yv_facey[OPS_ACC0(0, 0)] = ymin;
		y_celly[OPS_ACC1(0, 0)] = ymin;
		ydif_celldy[OPS_ACC2(0, 0)] = 0.0;
		ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
		ycvs[OPS_ACC4(0, 0)] = 0.0;
		ycvr[OPS_ACC5(0, 0)] = 0.0;
		ycvrs[OPS_ACC6(0, 0)] = 0.0;
	} else if (idx[1] == 1) {

	} else if (idx[1] == 2) {

	} else if (idx[1] == yM3 - 1) {

	} else if (idx[1] == yM2 - 1) {

	} else if (idx[1] == yM1 - 1) {

	} else {

	}

}

//XU的计算，这种写法是并行的写法

void gridsetup_kernel_facex(double *facex, int *idx) {

	double d_x;
	if (idx[0] == 0) {
		facex[OPS_ACC0(0, 0)] = 0;
	} else if (idx[0] == xL1) {
		facex[OPS_ACC0(0, 0)] = xmax;
	} else {
		d_x = (xmax - xmin) / (double) xcells;

		facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1);
	}
}

void gridsetup_kernel_facey(double *val, int *idx) {

	double d_y;
	if (idx[1] == 0) {
		val[OPS_ACC0(0, 0)] = 0;
	} else if (idx[1] == yM1) {
		val[OPS_ACC0(0, 0)] = ymax;
	} else {
		d_y = (ymax - ymin) / (double) ycells;

		val[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1);
	}
}

//void gridsetup_kernel_cellx(double *cellx, double *facex, int *idx) {
//	cellx[OPS_ACC0(0, 0)] = (facex[OPS_ACC1(0, 0)] + facex[OPS_ACC1(1, 0)])
//					/ 2.0;
//}

//void gridsetup_kernel_celldx(double *celldx, double *cellx, int *idx) {
//	celldx[OPS_ACC0(0, 0)] = cellx[OPS_ACC1(0, 0)] - cellx[OPS_ACC1(-1, 0)];
//}

void gridsetup_kernel_facedx(double *facedx, double *facex, int *idx) {
	facedx[OPS_ACC0(0, 0)] = facex[OPS_ACC1(0, 0)] - facex[OPS_ACC1(-1, 0)];
}

void gridsetup_kernel_xcvs(double *xcvs, double *celldx, int *idx) {

	if (idx[0] == 0) {
	} else if (idx[0] == xL1) {
	} else {

		xcvs[OPS_ACC0(0, 0)] = celldx[OPS_ACC1(0, 0)];
	}

}

void gridsetup_kernel_celly(double *celly, double *facey, int *idx) {

	celly[OPS_ACC0(0, 0)] = (facey[OPS_ACC1(0, 0)] + facey[OPS_ACC1(0, 1)])
					/ 2.0;

}

void gridsetup_kernel_celldy(double *celldy, double *celly, int *idx) {

	celldy[OPS_ACC0(0, 0)] = celly[OPS_ACC1(0, 0)] - celly[OPS_ACC1(0, -1)];

}

void gridsetup_kernel_facedy(double *facedy, double *facey, int *idx) {

	facedy[OPS_ACC0(0, 0)] = facey[OPS_ACC1(0, 0)] - facey[OPS_ACC1(0, -1)];

}

#endif /* FVM2DC_GRIDSETUP_KERNEL_H_ */

