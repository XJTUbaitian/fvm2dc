OPS_INSTALL_PATH := $(OPS_INSTALL_PATH)/c
OPS_INC   = -I$(OPS_INSTALL_PATH)/include
OPS_LIB   = -L$(OPS_INSTALL_PATH)/lib
CUDA_LIB = -L$(CUDA_INSTALL_PATH)/lib64
CUDA_INC = -I$(CUDA_INSTALL_PATH)/include

OPENCL_INC = -I$(OPENCL_INSTALL_PATH)/include
OPENCL_LIB = -L$(OPENCL_INSTALL_PATH)/lib64 -lOpenCL

ifeq ($(OPS_COMPILER),intel)
  CPP   = icpc
ifdef DEBUG
  CCFLAGS = -O0 -g -no-prec-div -openmp -fp-model strict -fp-model source -prec-div -prec-sqrt -DMPICH_IGNORE_CXX_SEEK #-DOPS_DEBUG
else
  CCFLAGS = -O3 -ipo -no-prec-div -restrict -fno-alias -fp-model strict -fp-model source -prec-div -prec-sqrt -DMPICH_IGNORE_CXX_SEEK #-vec-report
endif
  CPPFLAGS  = $(CCFLAGS)
  OMPFLAGS  = -openmp -openmp-report2
  MPICPP  = $(MPI_INSTALL_PATH)/bin/mpiicpc
  MPIFLAGS  = $(CCFLAGS)
else
print:
	@echo "unrecognised value for OPS_COMPILER"
endif

SEQ_KERNELS = fvm2dc_seq_kernels.cpp

#
# master to make all versions
#

TARGETS = fvm2dc_seq

all: clean $(TARGETS)

#
fvm2dc_seq: Makefile fvm2dc_ops.cpp $(OPS_INSTALL_PATH)/lib/libops_seq.a
	~/localsoft/OPS/translator/python/c/ops.py fvm2dc.cpp
	$(CPP) $(MPIFLAGS)  $(OPS_INC) $(OPS_LIB) -I. globalvars.cpp fvm2dc_ops.cpp -I. ./MPI/$(SEQ_KERNELS) -lops_seq $(HDF5_LIB) -o fvm2dc_seq

clean:
	rm -f fvm2dc_seq *.o ./MPI/* ./CUDA/* ./MPI_OpenMP/* result.txt facex.dat
