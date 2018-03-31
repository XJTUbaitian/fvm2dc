#ifndef __FVM2D_KERNELS_H
#define __FVM2D_KERNELS_H


void facesetup_kernel(double *val, int *idx)
{
    val[OPS_ACC0(0,0)] = 4+1.2;

}


#endif


