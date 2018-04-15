//
// auto-generated by ops.py
//
#include "./MPI_inline/fvm2dc_common.h"

int xdim0_gridsetup_kernel_celly;
int xdim1_gridsetup_kernel_celly;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + n_y * xdim0_gridsetup_kernel_celly * 1 + x +                      \
   xdim0_gridsetup_kernel_celly * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + n_y * xdim1_gridsetup_kernel_celly * 1 + x +                      \
   xdim1_gridsetup_kernel_celly * (y))

// user function

void gridsetup_kernel_celly_c_wrapper(double *restrict celly,
                                      const double *restrict facey,
                                      int *restrict idx, int arg_idx0,
                                      int arg_idx1, int x_size, int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {
      int idx[] = {arg_idx0 + n_x, arg_idx1 + n_y};

      celly[OPS_ACC0(0, 0)] =
          (facey[OPS_ACC1(0, 0)] + facey[OPS_ACC1(0, 1)]) / 2.0;
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1