#ifndef __FVM2D_KERNELS_H
#define __FVM2D_KERNELS_H

#include "globalvars.h"

void facesetup_kernel(double *val, int *idx)
{
    val[OPS_ACC0(0,0)] = 4+1.2;

}

void gridsetup_kernel_x(double *val, int *idx)
{

    double d_x;
    d_x=(xmax-xmin)/(double)xcells;

    val[OPS_ACC0(0,0)] = 1.0+d_x*idx[0];

}




#endif


