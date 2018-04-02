//
// auto-generated by ops.py//

// header
#define OPS_2D
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// set max number of OMP threads for reductions
#ifndef MAX_REDUCT_THREADS
#define MAX_REDUCT_THREADS 64
#endif
// global constants
extern double xmin;
extern double xmax;
extern int xcells;
extern double ymin;
extern double ymax;
extern int ycells;

// user kernel files
#include "gridsetup_kernel_facex_omp_kernel.cpp"
#include "gridsetup_kernel_facey_omp_kernel.cpp"
