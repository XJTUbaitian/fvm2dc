/*
 * coeffients_uvp_kernel.h
 *
 *  Created on: 2018年4月17日
 *      Author: limingtao
 */

#ifndef COEFFIENTS_UVP_KERNEL_H_
#define COEFFIENTS_UVP_KERNEL_H_
#include "globalvars.h"

void coeffients_uvp_kernel_setupU(double *xu_facex, double *x_cellx,
		double *xdif_celldx, double *xcv_facedx, double *xcvs, double *xcvi,
		double *xcvip, double *fx, double *fxm, int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是
}

void coeffients_uvp_kernel_setupV(double *xu_facex, double *x_cellx,
		double *xdif_celldx, double *xcv_facedx, double *xcvs, double *xcvi,
		double *xcvip, double *fx, double *fxm, int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是
}

void coeffients_uvp_kernel_setupP(double *xu_facex, double *x_cellx,
		double *xdif_celldx, double *xcv_facedx, double *xcvs, double *xcvi,
		double *xcvip, double *fx, double *fxm, int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是
}
#endif /* COEFFIENTS_UVP_KERNEL_H_ */
