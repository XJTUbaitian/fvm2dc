//
// auto-generated by ops.py
//

#ifdef OCL_FMA_SWITCH_ON
#define OCL_FMA 1
#else
#define OCL_FMA 0
#endif

static bool isbuilt_gridsetup_kernel_facey = false;

void buildOpenCLKernels_gridsetup_kernel_facey(int xdim0) {

  // int ocl_fma = OCL_FMA;
  if (!isbuilt_gridsetup_kernel_facey) {
    buildOpenCLKernels();
    // clSafeCall( clUnloadCompiler() );
    cl_int ret;
    char *source_filename[1] = {(char *)"./OpenCL/gridsetup_kernel_facey.cl"};

    // Load the kernel source code into the array source_str
    FILE *fid;
    char *source_str[1];
    size_t source_size[1];

    for (int i = 0; i < 1; i++) {
      fid = fopen(source_filename[i], "r");
      if (!fid) {
        fprintf(stderr, "Can't open the kernel source file!\n");
        exit(1);
      }

      source_str[i] = (char *)malloc(4 * 0x1000000);
      source_size[i] = fread(source_str[i], 1, 4 * 0x1000000, fid);
      if (source_size[i] != 4 * 0x1000000) {
        if (ferror(fid)) {
          printf("Error while reading kernel source file %s\n",
                 source_filename[i]);
          exit(-1);
        }
        if (feof(fid))
          printf("Kernel source file %s succesfuly read.\n",
                 source_filename[i]);
        // printf("%s\n",source_str[i]);
      }
      fclose(fid);
    }

    printf("Compiling gridsetup_kernel_facey %d source -- start \n", OCL_FMA);

    // Create a program from the source
    OPS_opencl_core.program = clCreateProgramWithSource(
        OPS_opencl_core.context, 1, (const char **)&source_str,
        (const size_t *)&source_size, &ret);
    clSafeCall(ret);

    // Build the program
    char buildOpts[255 * 2];
    char *pPath = NULL;
    pPath = getenv("OPS_INSTALL_PATH");
    if (pPath != NULL)
      if (OCL_FMA)
        sprintf(buildOpts, "-cl-mad-enable -DOCL_FMA -I%s/c/include "
                           "-DOPS_WARPSIZE=%d  "
                           "-Dxdim0_gridsetup_kernel_facey=%d ",
                pPath, 32, xdim0);
      else
        sprintf(buildOpts, "-cl-mad-enable -I%s/c/include -DOPS_WARPSIZE=%d  "
                           "-Dxdim0_gridsetup_kernel_facey=%d ",
                pPath, 32, xdim0);
    else {
      sprintf((char *)"Incorrect OPS_INSTALL_PATH %s\n", pPath);
      exit(EXIT_FAILURE);
    }

    ret = clBuildProgram(OPS_opencl_core.program, 1, &OPS_opencl_core.device_id,
                         buildOpts, NULL, NULL);

    if (ret != CL_SUCCESS) {
      char *build_log;
      size_t log_size;
      clSafeCall(clGetProgramBuildInfo(
          OPS_opencl_core.program, OPS_opencl_core.device_id,
          CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size));
      build_log = (char *)malloc(log_size + 1);
      clSafeCall(clGetProgramBuildInfo(
          OPS_opencl_core.program, OPS_opencl_core.device_id,
          CL_PROGRAM_BUILD_LOG, log_size, build_log, NULL));
      build_log[log_size] = '\0';
      fprintf(
          stderr,
          "=============== OpenCL Program Build Info ================\n\n%s",
          build_log);
      fprintf(stderr,
              "\n========================================================= \n");
      free(build_log);
      exit(EXIT_FAILURE);
    }
    printf("compiling gridsetup_kernel_facey -- done\n");

    // Create the OpenCL kernel
    OPS_opencl_core.kernel[4] = clCreateKernel(
        OPS_opencl_core.program, "ops_gridsetup_kernel_facey", &ret);
    clSafeCall(ret);

    isbuilt_gridsetup_kernel_facey = true;
  }
}

// host stub function
void ops_par_loop_gridsetup_kernel_facey(char const *name, ops_block block,
                                         int dim, int *range, ops_arg arg0,
                                         ops_arg arg1) {

  // Timing
  double t1, t2, c1, c2;

  ops_arg args[2] = {arg0, arg1};

#ifdef CHECKPOINTING
  if (!ops_checkpointing_before(args, 2, range, 4))
    return;
#endif

  if (OPS_diags > 1) {
    ops_timing_realloc(4, "gridsetup_kernel_facey");
    OPS_kernels[4].count++;
    ops_timers_core(&c1, &t1);
  }

  // compute locally allocated range for the sub-block
  int start[2];
  int end[2];
#ifdef OPS_MPI
  sub_block_list sb = OPS_sub_block_list[block->index];
  if (!sb->owned)
    return;
  for (int n = 0; n < 2; n++) {
    start[n] = sb->decomp_disp[n];
    end[n] = sb->decomp_disp[n] + sb->decomp_size[n];
    if (start[n] >= range[2 * n]) {
      start[n] = 0;
    } else {
      start[n] = range[2 * n] - start[n];
    }
    if (sb->id_m[n] == MPI_PROC_NULL && range[2 * n] < 0)
      start[n] = range[2 * n];
    if (end[n] >= range[2 * n + 1]) {
      end[n] = range[2 * n + 1] - sb->decomp_disp[n];
    } else {
      end[n] = sb->decomp_size[n];
    }
    if (sb->id_p[n] == MPI_PROC_NULL &&
        (range[2 * n + 1] > sb->decomp_disp[n] + sb->decomp_size[n]))
      end[n] += (range[2 * n + 1] - sb->decomp_disp[n] - sb->decomp_size[n]);
  }
#else
  for (int n = 0; n < 2; n++) {
    start[n] = range[2 * n];
    end[n] = range[2 * n + 1];
  }
#endif

  int x_size = MAX(0, end[0] - start[0]);
  int y_size = MAX(0, end[1] - start[1]);

  int arg_idx[2];
#ifdef OPS_MPI
  arg_idx[0] = sb->decomp_disp[0] + start[0];
  arg_idx[1] = sb->decomp_disp[1] + start[1];
#else
  arg_idx[0] = start[0];
  arg_idx[1] = start[1];
#endif

  int xdim0 = args[0].dat->size[0];

  // build opencl kernel if not already built

  buildOpenCLKernels_gridsetup_kernel_facey(xdim0);

  // set up OpenCL thread blocks
  size_t globalWorkSize[3] = {
      ((x_size - 1) / OPS_block_size_x + 1) * OPS_block_size_x,
      ((y_size - 1) / OPS_block_size_y + 1) * OPS_block_size_y, 1};
  size_t localWorkSize[3] = {OPS_block_size_x, OPS_block_size_y, 1};

  // set up initial pointers
  int d_m[OPS_MAX_DIM];
#ifdef OPS_MPI
  for (int d = 0; d < dim; d++)
    d_m[d] =
        args[0].dat->d_m[d] + OPS_sub_dat_list[args[0].dat->index]->d_im[d];
#else
  for (int d = 0; d < dim; d++)
    d_m[d] = args[0].dat->d_m[d];
#endif
  int base0 = 1 * 1 * (start[0] * args[0].stencil->stride[0] -
                       args[0].dat->base[0] - d_m[0]);
  base0 = base0 +
          args[0].dat->size[0] * 1 * (start[1] * args[0].stencil->stride[1] -
                                      args[0].dat->base[1] - d_m[1]);

  ops_H_D_exchanges_device(args, 2);
  ops_halo_exchanges(args, 2, range);
  ops_H_D_exchanges_device(args, 2);

  if (OPS_diags > 1) {
    ops_timers_core(&c2, &t2);
    OPS_kernels[4].mpi_time += t2 - t1;
  }

  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 0, sizeof(cl_mem),
                            (void *)&arg0.data_d));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 1, sizeof(cl_double),
                            (void *)&ymin));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 2, sizeof(cl_double),
                            (void *)&ymax));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 3, sizeof(cl_int),
                            (void *)&ycells));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 4, sizeof(cl_int),
                            (void *)&yM1));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 5, sizeof(cl_int),
                            (void *)&base0));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 6, sizeof(cl_int),
                            (void *)&arg_idx[0]));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 7, sizeof(cl_int),
                            (void *)&arg_idx[1]));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 8, sizeof(cl_int),
                            (void *)&x_size));
  clSafeCall(clSetKernelArg(OPS_opencl_core.kernel[4], 9, sizeof(cl_int),
                            (void *)&y_size));

  // call/enque opencl kernel wrapper function
  clSafeCall(clEnqueueNDRangeKernel(
      OPS_opencl_core.command_queue, OPS_opencl_core.kernel[4], 3, NULL,
      globalWorkSize, localWorkSize, 0, NULL, NULL));
  if (OPS_diags > 1) {
    clSafeCall(clFinish(OPS_opencl_core.command_queue));
  }

  if (OPS_diags > 1) {
    ops_timers_core(&c1, &t1);
    OPS_kernels[4].time += t1 - t2;
  }

  ops_set_dirtybit_device(args, 2);
  ops_set_halo_dirtybit3(&args[0], range);

  if (OPS_diags > 1) {
    // Update kernel record
    ops_timers_core(&c2, &t2);
    OPS_kernels[4].mpi_time += t2 - t1;
    OPS_kernels[4].transfer += ops_compute_transfer(dim, start, end, &arg0);
  }
}
