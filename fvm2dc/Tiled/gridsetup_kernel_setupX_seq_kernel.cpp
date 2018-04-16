//
// auto-generated by ops.py
//
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

// host stub function
void ops_par_loop_gridsetup_kernel_setupX_execute(ops_kernel_descriptor *desc) {
  ops_block block = desc->block;
  int dim = desc->dim;
  int *range = desc->range;
  ops_arg arg0 = desc->args[0];
  ops_arg arg1 = desc->args[1];
  ops_arg arg2 = desc->args[2];
  ops_arg arg3 = desc->args[3];
  ops_arg arg4 = desc->args[4];
  ops_arg arg5 = desc->args[5];
  ops_arg arg6 = desc->args[6];
  ops_arg arg7 = desc->args[7];

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[8] = {arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 8, range, 0))
    return;
#endif

  if (OPS_diags > 1) {
    OPS_kernels[0].count++;
    ops_timers_core(&c2, &t2);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];

  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }

#ifdef OPS_DEBUG
  ops_register_args(args, "gridsetup_kernel_setupX");
#endif

  int arg_idx[2];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  arg_idx[0] = sb->decomp_disp[0];
  arg_idx[1] = sb->decomp_disp[1];
#else  // OPS_MPI
  arg_idx[0] = 0;
  arg_idx[1] = 0;
#endif // OPS_MPI

  // set up initial pointers and exchange halos if necessary
  int base0 = args[0].dat->base_offset;
  double *__restrict__ xu_facex = (double *)(args[0].data + base0);

  int base1 = args[1].dat->base_offset;
  double *__restrict__ x_cellx = (double *)(args[1].data + base1);

  int base2 = args[2].dat->base_offset;
  double *__restrict__ xdif_celldx = (double *)(args[2].data + base2);

  int base3 = args[3].dat->base_offset;
  double *__restrict__ xcv_facedx = (double *)(args[3].data + base3);

  int base4 = args[4].dat->base_offset;
  double *__restrict__ xcvs = (double *)(args[4].data + base4);

  int base5 = args[5].dat->base_offset;
  double *__restrict__ xcvi = (double *)(args[5].data + base5);

  int base6 = args[6].dat->base_offset;
  double *__restrict__ xcvip = (double *)(args[6].data + base6);

  // initialize global variable with the dimension of dats
  int xdim0_gridsetup_kernel_setupX = args[0].dat->size[0];
  int xdim1_gridsetup_kernel_setupX = args[1].dat->size[0];
  int xdim2_gridsetup_kernel_setupX = args[2].dat->size[0];
  int xdim3_gridsetup_kernel_setupX = args[3].dat->size[0];
  int xdim4_gridsetup_kernel_setupX = args[4].dat->size[0];
  int xdim5_gridsetup_kernel_setupX = args[5].dat->size[0];
  int xdim6_gridsetup_kernel_setupX = args[6].dat->size[0];

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[0].mpi_time += t1 - t2;
  }

#pragma omp parallel for
  for (int n_y = start[1]; n_y < end[1]; n_y++) {
#ifdef intel
#pragma loop_count(10000)
#pragma omp simd aligned(xu_facex, x_cellx, xdif_celldx, xcv_facedx, xcvs,     \
                         xcvi, xcvip)
#else
#pragma simd
#endif
    for (int n_x = start[0]; n_x < end[0]; n_x++) {
      int idx[] = {arg_idx[0] + n_x, arg_idx[1] + n_y};

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
  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[0].time += t2 - t1;
  }

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c1, &t1);
    OPS_kernels[0].mpi_time += t1 - t2;
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg0);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg1);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg2);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg3);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg4);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg5);
    OPS_kernels[0].transfer += ops_compute_transfer(dim, start, end, &arg6);
  }
}
#undef OPS_ACC0
#undef OPS_ACC1
#undef OPS_ACC2
#undef OPS_ACC3
#undef OPS_ACC4
#undef OPS_ACC5
#undef OPS_ACC6

void ops_par_loop_gridsetup_kernel_setupX(char const *name, ops_block block,
                                          int dim, int *range, ops_arg arg0,
                                          ops_arg arg1, ops_arg arg2,
                                          ops_arg arg3, ops_arg arg4,
                                          ops_arg arg5, ops_arg arg6,
                                          ops_arg arg7) {
  ops_kernel_descriptor *desc =
      (ops_kernel_descriptor *)malloc(sizeof(ops_kernel_descriptor));
  desc->name = name;
  desc->block = block;
  desc->dim = dim;
  desc->device = 1;
  desc->index = 0;
  desc->hash = 5381;
  desc->hash = ((desc->hash << 5) + desc->hash) + 0;
  for (int i = 0; i < 4; i++) {
    desc->range[i] = range[i];
    desc->orig_range[i] = range[i];
    desc->hash = ((desc->hash << 5) + desc->hash) + range[i];
  }
  desc->nargs = 8;
  desc->args = (ops_arg *)malloc(8 * sizeof(ops_arg));
  desc->args[0] = arg0;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg0.dat->index;
  desc->args[1] = arg1;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg1.dat->index;
  desc->args[2] = arg2;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg2.dat->index;
  desc->args[3] = arg3;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg3.dat->index;
  desc->args[4] = arg4;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg4.dat->index;
  desc->args[5] = arg5;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg5.dat->index;
  desc->args[6] = arg6;
  desc->hash = ((desc->hash << 5) + desc->hash) + arg6.dat->index;
  desc->args[7] = arg7;
  desc->function = ops_par_loop_gridsetup_kernel_setupX_execute;
  if (OPS_diags > 1) {
    ops_timing_realloc(0, "gridsetup_kernel_setupX");
  }
  ops_enqueue_kernel(desc);
}
