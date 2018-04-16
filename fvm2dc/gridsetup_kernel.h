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

void gridsetup_kernel_cellx(double *cellx, double *facex, int *idx) {
	cellx[OPS_ACC0(0, 0)] = (facex[OPS_ACC1(0, 0)] + facex[OPS_ACC1(1, 0)])
					/ 2.0;
}

void gridsetup_kernel_celldx(double *celldx, double *cellx, int *idx) {
	celldx[OPS_ACC0(0, 0)] = cellx[OPS_ACC1(0, 0)] - cellx[OPS_ACC1(-1, 0)];
}

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

#endif

