//
// auto-generated by ops.py
//
#include "./MPI_inline/fvm2dc_common.h"

int xdim0_gridsetup_kernel_setupX;
int xdim1_gridsetup_kernel_setupX;
int xdim2_gridsetup_kernel_setupX;
int xdim3_gridsetup_kernel_setupX;
int xdim4_gridsetup_kernel_setupX;
int xdim5_gridsetup_kernel_setupX;
int xdim6_gridsetup_kernel_setupX;

#define OPS_ACC0(x, y)                                                         \
  (n_x * 1 + n_y * xdim0_gridsetup_kernel_setupX * 1 + x +                     \
   xdim0_gridsetup_kernel_setupX * (y))
#define OPS_ACC1(x, y)                                                         \
  (n_x * 1 + n_y * xdim1_gridsetup_kernel_setupX * 1 + x +                     \
   xdim1_gridsetup_kernel_setupX * (y))
#define OPS_ACC2(x, y)                                                         \
  (n_x * 1 + n_y * xdim2_gridsetup_kernel_setupX * 1 + x +                     \
   xdim2_gridsetup_kernel_setupX * (y))
#define OPS_ACC3(x, y)                                                         \
  (n_x * 1 + n_y * xdim3_gridsetup_kernel_setupX * 1 + x +                     \
   xdim3_gridsetup_kernel_setupX * (y))
#define OPS_ACC4(x, y)                                                         \
  (n_x * 1 + n_y * xdim4_gridsetup_kernel_setupX * 1 + x +                     \
   xdim4_gridsetup_kernel_setupX * (y))
#define OPS_ACC5(x, y)                                                         \
  (n_x * 1 + n_y * xdim5_gridsetup_kernel_setupX * 1 + x +                     \
   xdim5_gridsetup_kernel_setupX * (y))
#define OPS_ACC6(x, y)                                                         \
  (n_x * 1 + n_y * xdim6_gridsetup_kernel_setupX * 1 + x +                     \
   xdim6_gridsetup_kernel_setupX * (y))

// user function

void gridsetup_kernel_setupX_c_wrapper(
    double *restrict xu_facex, double *restrict x_cellx,
    double *restrict xdif_celldx, double *restrict xcv_facedx,
    double *restrict xcvs, double *restrict xcvi, double *restrict xcvip,
    int *restrict idx, int arg_idx0, int arg_idx1, int x_size, int y_size) {
#pragma omp parallel for
  for (int n_y = 0; n_y < y_size; n_y++) {
    for (int n_x = 0; n_x < x_size; n_x++) {
      int idx[] = {arg_idx0 + n_x, arg_idx1 + n_y};

      double d_x;
      d_x = (xmax - xmin) / (double)xcells;

      if (idx[0] == 0) {
        xu_facex[OPS_ACC0(0, 0)] = xmin;
        x_cellx[OPS_ACC1(0, 0)] = xmin;
        xdif_celldx[OPS_ACC2(0, 0)] = 0.0;
        xcv_facedx[OPS_ACC3(0, 0)] = 0.0;
        xcvs[OPS_ACC4(0, 0)] = 0.0;
        xcvi[OPS_ACC5(0, 0)] = 0.0;
        xcvip[OPS_ACC6(0, 0)] = 0.0;
      } else if (idx[0] == 1) {
        xu_facex[OPS_ACC0(0, 0)] = xmin;
        x_cellx[OPS_ACC1(0, 0)] = xmin + d_x / 2.0;
        xdif_celldx[OPS_ACC2(0, 0)] = d_x / 2.0;
        xcv_facedx[OPS_ACC3(0, 0)] = d_x;
        xcvs[OPS_ACC4(0, 0)] = 0.0;
        xcvi[OPS_ACC5(0, 0)] = 0.0;
        xcvip[OPS_ACC6(0, 0)] = d_x;
      } else if (idx[0] == 2) {
        xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1.0);
        x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
        xdif_celldx[OPS_ACC2(0, 0)] = d_x;
        xcv_facedx[OPS_ACC3(0, 0)] = d_x;
        xcvs[OPS_ACC4(0, 0)] = d_x + d_x / 2.0;
        xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
        xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;

      } else if (idx[0] == xL3 - 1) {
        xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1.0);
        x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
        xdif_celldx[OPS_ACC2(0, 0)] = d_x;
        xcv_facedx[OPS_ACC3(0, 0)] = d_x;
        xcvs[OPS_ACC4(0, 0)] = d_x;
        xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
        xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;

      } else if (idx[0] == xL2 - 1) {
        xu_facex[OPS_ACC0(0, 0)] = xmax - d_x;
        x_cellx[OPS_ACC1(0, 0)] = xmax - d_x / 2.0;
        xdif_celldx[OPS_ACC2(0, 0)] = d_x;
        xcv_facedx[OPS_ACC3(0, 0)] = d_x;
        xcvs[OPS_ACC4(0, 0)] = d_x + d_x / 2.0;
        xcvi[OPS_ACC5(0, 0)] = d_x;
        xcvip[OPS_ACC6(0, 0)] = 0.0;
      } else if (idx[0] == xL1 - 1) {
        xu_facex[OPS_ACC0(0, 0)] = xmax;
        x_cellx[OPS_ACC1(0, 0)] = xmax;
        xdif_celldx[OPS_ACC2(0, 0)] = d_x / 2.0;
        xcv_facedx[OPS_ACC3(0, 0)] = 0.0;
        xcvs[OPS_ACC4(0, 0)] = 0.0;
        xcvi[OPS_ACC5(0, 0)] = 0.0;
        xcvip[OPS_ACC6(0, 0)] = 0.0;
      } else {
        xu_facex[OPS_ACC0(0, 0)] = d_x * (idx[0] - 1.0);
        x_cellx[OPS_ACC1(0, 0)] = d_x * idx[0] - d_x / 2.0;
        xdif_celldx[OPS_ACC2(0, 0)] = d_x;
        xcv_facedx[OPS_ACC3(0, 0)] = d_x;
        xcvs[OPS_ACC4(0, 0)] = d_x;
        xcvi[OPS_ACC5(0, 0)] = d_x / 2.0;
        xcvip[OPS_ACC6(0, 0)] = d_x / 2.0;
      }
    }
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6
