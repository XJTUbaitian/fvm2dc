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
#undef OPS_ACC7
#undef OPS_ACC8
#undef OPS_ACC9
#undef OPS_ACC10

#define OPS_ACC0(x, y) (x + xdim0_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC1(x, y) (x + xdim1_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC2(x, y) (x + xdim2_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC3(x, y) (x + xdim3_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC4(x, y) (x + xdim4_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC5(x, y) (x + xdim5_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC6(x, y) (x + xdim6_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC7(x, y) (x + xdim7_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC8(x, y) (x + xdim8_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC9(x, y) (x + xdim9_gridsetup_kernel_setupY_Cylindrical * (y))
#define OPS_ACC10(x, y) (x + xdim10_gridsetup_kernel_setupY_Cylindrical * (y))

// user function
void gridsetup_kernel_setupY_Cylindrical(
    __global double *restrict radius, __global double *restrict sx,
    __global double *restrict rmn, __global double *restrict sxmn,
    __global double *restrict ycvr, __global double *restrict ycvrs,
    __global double *restrict arx, __global double *restrict arxj,
    __global double *restrict arxjp, __global double *restrict fv,
    __global double *restrict fvp, int *restrict idx, const double ymin,
    const double ymax, const int ycells, const int yM1, const int yM2,
    const int yM3)

{

  double d_y;
  d_y = (ymax - ymin) / (double)ycells;

  if (idx[1] == 0) {
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

  } else if (idx[1] == 1) {
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
  } else if (idx[1] == 2) {
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
  } else if (idx[1] == yM3 - 1) {
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
  } else if (idx[1] == yM2 - 1) {
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
  } else if (idx[1] == yM1 - 1) {
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

__kernel void ops_gridsetup_kernel_setupY_Cylindrical(
    __global double *restrict arg0, __global double *restrict arg1,
    __global double *restrict arg2, __global double *restrict arg3,
    __global double *restrict arg4, __global double *restrict arg5,
    __global double *restrict arg6, __global double *restrict arg7,
    __global double *restrict arg8, __global double *restrict arg9,
    __global double *restrict arg10, const double ymin, const double ymax,
    const int ycells, const int yM1, const int yM2, const int yM3,
    const int base0, const int base1, const int base2, const int base3,
    const int base4, const int base5, const int base6, const int base7,
    const int base8, const int base9, const int base10, int arg_idx0,
    int arg_idx1, const int size0, const int size1) {

  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  int arg_idx[2];
  arg_idx[0] = arg_idx0 + idx_x;
  arg_idx[1] = arg_idx1 + idx_y;
  if (idx_x < size0 && idx_y < size1) {
    gridsetup_kernel_setupY_Cylindrical(
        &arg0[base0 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim0_gridsetup_kernel_setupY_Cylindrical],
        &arg1[base1 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim1_gridsetup_kernel_setupY_Cylindrical],
        &arg2[base2 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim2_gridsetup_kernel_setupY_Cylindrical],
        &arg3[base3 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim3_gridsetup_kernel_setupY_Cylindrical],
        &arg4[base4 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim4_gridsetup_kernel_setupY_Cylindrical],
        &arg5[base5 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim5_gridsetup_kernel_setupY_Cylindrical],
        &arg6[base6 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim6_gridsetup_kernel_setupY_Cylindrical],
        &arg7[base7 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim7_gridsetup_kernel_setupY_Cylindrical],
        &arg8[base8 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim8_gridsetup_kernel_setupY_Cylindrical],
        &arg9[base9 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim9_gridsetup_kernel_setupY_Cylindrical],
        &arg10[base10 + idx_x * 1 * 1 +
               idx_y * 1 * 1 * xdim10_gridsetup_kernel_setupY_Cylindrical],
        arg_idx, ymin, ymax, ycells, yM1, yM2, yM3);
  }
}
