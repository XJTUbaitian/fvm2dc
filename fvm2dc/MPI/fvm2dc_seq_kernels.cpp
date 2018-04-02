//
// auto-generated by ops.py//

// header
#define OPS_2D
#define OPS_ACC_MD_MACROS
#include "ops_lib_cpp.h"
#ifdef OPS_MPI
#include "ops_mpi_core.h"
#endif

// global constants
extern double xmin;
extern double xmax;
extern int xcells;
extern double ymin;
extern double ymax;
extern int ycells;
extern int xL1;
extern int yM1;
// user kernel files
#include "gridsetup_kernel_celldx_seq_kernel.cpp"
#include "gridsetup_kernel_celldy_seq_kernel.cpp"
#include "gridsetup_kernel_cellx_seq_kernel.cpp"
#include "gridsetup_kernel_celly_seq_kernel.cpp"
#include "gridsetup_kernel_facedx_seq_kernel.cpp"
#include "gridsetup_kernel_facedy_seq_kernel.cpp"
#include "gridsetup_kernel_facex_seq_kernel.cpp"
#include "gridsetup_kernel_facey_seq_kernel.cpp"
#include "gridsetup_kernel_xcvs_seq_kernel.cpp"
