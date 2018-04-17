/*
 * coeffients_uvp_kernel.h
 *
 *  Created on: 2018年4月17日
 *      Author: limingtao
 */

#ifndef COEFFIENTS_UVP_KERNEL_H_
#define COEFFIENTS_UVP_KERNEL_H_
#include "globalvars.h"

//原始版本diflow是一个函数，可是我们的并行使用kernel进行，kernel要使用到diflow这有一定的麻烦，我们可以把diflow写成一个宏，
//编译时实际上进行宏展开,

void coeffients_uvp_kernel_setupU(double *ucon, double *uaip, double *uaim,
		double *uajp, double *uajm, double *uapp, double *xcv_facedx,
		double *ycv_facedy, double *fx, double *fxm, double *xcvi,
		double *xcvip, double *sx, double *arx, double *radius, double *u_xvel0,
		double *v_yvel0, double *density, double *gam, int *idx) {
	double f_l; //simpler.f90的fl
	double f_l_m; //simpler.f90的flm
	double flow;
	double diff;
	//f_l=xcvi(0,1)*

}

void coeffients_uvp_kernel_setupV(double *radius, double *sx, double *rmn,
		int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是
}
void coeffients_uvp_kernel_setupP(double *radius, double *sx, double *rmn,
		int *idx) {
	double d_x;
	d_x = (xmax - xmin) / (double) xcells; //xmax,xmin,xcells是ops常量，所以可以直接使用，xL1,xL2,xL3也是
}
#endif /* COEFFIENTS_UVP_KERNEL_H_ */
