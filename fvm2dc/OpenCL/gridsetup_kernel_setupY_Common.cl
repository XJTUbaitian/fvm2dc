//
// auto-generated by ops.py
//

#ifdef OCL_FMA
#pragma OPENCL FP_CONTRACT ON
#else
#pragma OPENCL FP_CONTRACT OFF
#endif
#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#include "ops_opencl_reduction.h"

#ifndef MIN
#define MIN(a, b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a > b) ? (a) : (b))
#endif
#ifndef SIGN
#define SIGN(a, b) ((b < 0.0) ? (a * (-1)) : (a))
#endif
#define OPS_READ 0
#define OPS_WRITE 1
#define OPS_RW 2
#define OPS_INC 3
#define OPS_MIN 4
#define OPS_MAX 5
#define ZERO_double 0.0;
#define INFINITY_double INFINITY;
#define ZERO_float 0.0f;
#define INFINITY_float INFINITY;
#define ZERO_int 0;
#define INFINITY_int INFINITY;
#define ZERO_uint 0;
#define INFINITY_uint INFINITY;
#define ZERO_ll 0;
#define INFINITY_ll INFINITY;
#define ZERO_ull 0;
#define INFINITY_ull INFINITY;
#define ZERO_bool 0;

#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

#define OPS_ACC0(x, y) (x + xdim0_gridsetup_kernel_setupY_Common * (y))
#define OPS_ACC1(x, y) (x + xdim1_gridsetup_kernel_setupY_Common * (y))
#define OPS_ACC2(x, y) (x + xdim2_gridsetup_kernel_setupY_Common * (y))
#define OPS_ACC3(x, y) (x + xdim3_gridsetup_kernel_setupY_Common * (y))
#define OPS_ACC4(x, y) (x + xdim4_gridsetup_kernel_setupY_Common * (y))
#define OPS_ACC5(x, y) (x + xdim5_gridsetup_kernel_setupY_Common * (y))
#define OPS_ACC6(x, y) (x + xdim6_gridsetup_kernel_setupY_Common * (y))

// user function
void gridsetup_kernel_setupY_Common(
    __global double *restrict yv_facey, __global double *restrict y_celly,
    __global double *restrict ydif_celldy, __global double *restrict ycv_facedy,
    __global double *restrict ycvs, __global double *restrict fy,
    __global double *restrict fym, int *restrict idx, const double ymin,
    const double ymax, const int ycells, const int yM1, const int yM2,
    const int yM3)

{

  double d_y;
  d_y = (ymax - ymin) / (double)ycells;
  if (idx[1] == 0) {
    yv_facey[OPS_ACC0(0, 0)] = ymin;
    y_celly[OPS_ACC1(0, 0)] = ymin;
    ydif_celldy[OPS_ACC2(0, 0)] = 0.0;
    ycv_facedy[OPS_ACC3(0, 0)] = 0.0;
    ycvs[OPS_ACC4(0, 0)] = 0.0;
    fy[OPS_ACC5(0, 0)] = 0.0;
    fym[OPS_ACC6(0, 0)] = 0.0;

  } else if (idx[1] == 1) {
    yv_facey[OPS_ACC0(0, 0)] = ymin;
    y_celly[OPS_ACC1(0, 0)] = ymin + d_y / 2.0;
    ydif_celldy[OPS_ACC2(0, 0)] = d_y / 2.0;
    ycv_facedy[OPS_ACC3(0, 0)] = d_y;
    ycvs[OPS_ACC4(0, 0)] = 0.0;
    fy[OPS_ACC5(0, 0)] = 0.0;
    fym[OPS_ACC6(0, 0)] = 0.0;
  } else if (idx[1] == 2) {
    yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
    y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
    ydif_celldy[OPS_ACC2(0, 0)] = d_y;
    ycv_facedy[OPS_ACC3(0, 0)] = d_y;
    ycvs[OPS_ACC4(0, 0)] = d_y + d_y / 2.0;
    fy[OPS_ACC5(0, 0)] = 0.0;
    fym[OPS_ACC6(0, 0)] = 0.0;
  } else if (idx[1] == yM3 - 1) {
    yv_facey[OPS_ACC0(0, 0)] = d_y * (idx[1] - 1.0);
    y_celly[OPS_ACC1(0, 0)] = d_y * idx[1] - d_y / 2.0;
    ydif_celldy[OPS_ACC2(0, 0)] = d_y;
    ycv_facedy[OPS_ACC3(0, 0)] = d_y;
    ycvs[OPS_ACC4(0, 0)] = d_y;
    fy[OPS_ACC5(0, 0)] = 0.0;
    fym[OPS_ACC6(0, 0)] = 0.0;
  } else if (idx[1] == yM2 - 1) {
    yv_facey[OPS_ACC0(0, 0)] = ymax - d_y;
    y_celly[OPS_ACC1(0, 0)] = ymax - d_y / 2.0;
    ydif_celldy[OPS_ACC2(0, 0)] = d_y;
    ycv_facedy[OPS_ACC3(0, 0)] = d_y;
    ycvs[OPS_ACC4(0, 0)] = d_y + d_y / 2.0;
    fy[OPS_ACC5(0, 0)] = 0.0;
    fym[OPS_ACC6(0, 0)] = 0.0;
  } else if (idx[1] == yM1 - 1) {
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

__kernel void ops_gridsetup_kernel_setupY_Common(
    __global double *restrict arg0, __global double *restrict arg1,
    __global double *restrict arg2, __global double *restrict arg3,
    __global double *restrict arg4, __global double *restrict arg5,
    __global double *restrict arg6, const double ymin, const double ymax,
    const int ycells, const int yM1, const int yM2, const int yM3,
    const int base0, const int base1, const int base2, const int base3,
    const int base4, const int base5, const int base6, int arg_idx0,
    int arg_idx1, const int size0, const int size1) {

  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  int arg_idx[2];
  arg_idx[0] = arg_idx0 + idx_x;
  arg_idx[1] = arg_idx1 + idx_y;
  if (idx_x < size0 && idx_y < size1) {
    gridsetup_kernel_setupY_Common(
        &arg0[base0 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim0_gridsetup_kernel_setupY_Common],
        &arg1[base1 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim1_gridsetup_kernel_setupY_Common],
        &arg2[base2 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim2_gridsetup_kernel_setupY_Common],
        &arg3[base3 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim3_gridsetup_kernel_setupY_Common],
        &arg4[base4 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim4_gridsetup_kernel_setupY_Common],
        &arg5[base5 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim5_gridsetup_kernel_setupY_Common],
        &arg6[base6 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim6_gridsetup_kernel_setupY_Common],
        arg_idx, ymin, ymax, ycells, yM1, yM2, yM3);
  }
}
