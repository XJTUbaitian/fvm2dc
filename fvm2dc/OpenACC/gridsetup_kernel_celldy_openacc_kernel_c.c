//
// auto-generated by ops.py
//
#include "./OpenACC/fvm2dc_common.h"

#define OPS_GPU

int xdim0_gridsetup_kernel_celldy;
int xdim1_gridsetup_kernel_celldy;

#undef OPS_ACC0
#undef OPS_ACC1

#define OPS_ACC0(x, y) (x + xdim0_gridsetup_kernel_celldy * (y))
#define OPS_ACC1(x, y) (x + xdim1_gridsetup_kernel_celldy * (y))

// user function
inline void gridsetup_kernel_celldy(double *celldy, double *celly, int *idx) {

  celldy[OPS_ACC0(0, 0)] = celly[OPS_ACC1(0, 0)] - celly[OPS_ACC1(0, -1)];
}

#undef OPS_ACC0
#undef OPS_ACC1

void gridsetup_kernel_celldy_c_wrapper(double *p_a0, double *p_a1, int *p_a2,
                                       int arg_idx0, int arg_idx1, int x_size,
                                       int y_size) {
#ifdef OPS_GPU
#pragma acc parallel deviceptr(p_a0, p_a1)
#pragma acc loop
#endif
  for (int n_y = 0; n_y < y_size; n_y++) {
#ifdef OPS_GPU
#pragma acc loop
#endif
    for (int n_x = 0; n_x < x_size; n_x++) {
      int arg_idx[] = {arg_idx0 + n_x, arg_idx1 + n_y};
      gridsetup_kernel_celldy(
          p_a0 + n_x * 1 * 1 + n_y * xdim0_gridsetup_kernel_celldy * 1 * 1,
          p_a1 + n_x * 1 * 1 + n_y * xdim1_gridsetup_kernel_celldy * 1 * 1,
          arg_idx);
    }
  }
}
