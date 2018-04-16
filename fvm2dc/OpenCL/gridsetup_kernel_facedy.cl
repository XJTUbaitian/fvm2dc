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

#define OPS_ACC0(x, y) (x + xdim0_gridsetup_kernel_facedy * (y))
#define OPS_ACC1(x, y) (x + xdim1_gridsetup_kernel_facedy * (y))

// user function
void gridsetup_kernel_facedy(__global double *restrict facedy,
                             __global double *restrict facey, int *restrict idx)

{

  facedy[OPS_ACC0(0, 0)] = facey[OPS_ACC1(0, 0)] - facey[OPS_ACC1(0, -1)];
}

__kernel void ops_gridsetup_kernel_facedy(__global double *restrict arg0,
                                          __global const double *restrict arg1,
                                          const int base0, const int base1,
                                          int arg_idx0, int arg_idx1,
                                          const int size0, const int size1) {

  int idx_y = get_global_id(1);
  int idx_x = get_global_id(0);

  int arg_idx[2];
  arg_idx[0] = arg_idx0 + idx_x;
  arg_idx[1] = arg_idx1 + idx_y;
  if (idx_x < size0 && idx_y < size1) {
    gridsetup_kernel_facedy(
        &arg0[base0 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim0_gridsetup_kernel_facedy],
        &arg1[base1 + idx_x * 1 * 1 +
              idx_y * 1 * 1 * xdim1_gridsetup_kernel_facedy],
        arg_idx);
  }
}
