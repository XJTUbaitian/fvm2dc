#ifndef __FVM2D_KERNELS_H
#define __FVM2D_KERNELS_H

#include "globalvars.h"

void gridsetup_kernel_facex(double *val, int *idx)
{

    double d_x;
    if(idx[0]==0|idx[0]==1)
    {
    val[OPS_ACC0(0,0)]=0;
    }
    else
    {
    d_x=(xmax-xmin)/(double)xcells;

    val[OPS_ACC0(0,0)] = 0.0+d_x*idx[0];
    }
}
void gridsetup_kernel_facey(double *val, int *idx)
{

    double d_y;
    if(idx[1]==0|idx[1]==1)
    {
    val[OPS_ACC0(0,0)]=0;
    }
    else
    {
    d_y=(ymax-ymin)/(double)ycells;

    val[OPS_ACC0(0,0)] = 1.0+d_y*idx[1];
    }
}







#endif


