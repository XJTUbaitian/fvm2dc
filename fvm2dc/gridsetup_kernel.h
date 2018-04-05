#ifndef __FVM2D_KERNELS_H
#define __FVM2D_KERNELS_H

#include "globalvars.h"

void gridsetup_kernel_facex(double *val, int *idx) {

	double d_x;
	if (idx[0] == 0) {
		val[OPS_ACC0(0,0)]=0;
	} else if (idx[0] == xL1) {
		val[OPS_ACC0(0,0)]=xmax;
	} else {
		d_x = (xmax - xmin) / (double) xcells;

		val[OPS_ACC0(0,0)] = d_x*(idx[0]-1);
	}
}
void gridsetup_kernel_facey(double *val, int *idx) {

	double d_y;
	if (idx[1] == 0) {
		val[OPS_ACC0(0,0)]=0;
	} else if (idx[1] == yM1) {
		val[OPS_ACC0(0,0)]=ymax;
	} else {
		d_y = (ymax - ymin) / (double) ycells;

		val[OPS_ACC0(0,0)] = d_y*(idx[1]-1);
	}
}

void gridsetup_kernel_cellx(double *cellx, double *facex, int *idx) {

cellx[OPS_ACC0(0,0)]=(facex[OPS_ACC1(0,0)]+facex[OPS_ACC1(1,0)])/2.0;

}

void gridsetup_kernel_celldx(double *celldx, double *cellx, int *idx) {

celldx[OPS_ACC0(0,0)]=cellx[OPS_ACC1(0,0)]-cellx[OPS_ACC1(-1,0)];

}

void gridsetup_kernel_facedx(double *facedx, double *facex, int *idx) {

	facedx[OPS_ACC0(0,0)]=facex[OPS_ACC1(0,0)]-facex[OPS_ACC1(-1,0)];

}
void gridsetup_kernel_xcvs(double *xcvs, double *celldx, int *idx) {

	if (idx[0] == 0) {
	} else if (idx[0] == xL1) {
	} else {

		xcvs[OPS_ACC0(0,0)]=celldx[OPS_ACC1(0,0)];}

}


void gridsetup_kernel_celly(double *celly, double *facey, int *idx) {

celly[OPS_ACC0(0,0)]=(facey[OPS_ACC1(0,0)]+facey[OPS_ACC1(0,1)])/2.0;

}

void gridsetup_kernel_celldy(double *celldy, double *celly, int *idx) {

	celldy[OPS_ACC0(0,0)]=celly[OPS_ACC1(0,0)]-celly[OPS_ACC1(0,-1)];

}


void gridsetup_kernel_facedy(double *facedy, double *facey, int *idx) {

	facedy[OPS_ACC0(0,0)]=facey[OPS_ACC1(0,0)]-facey[OPS_ACC1(0,-1)];

}

#endif

