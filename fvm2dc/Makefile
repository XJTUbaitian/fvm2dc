OPS_INSTALL_PATH=/home/limingtao/localsoft/OPS/ops
OPS_INC   = -I$(OPS_INSTALL_PATH)/c/include
OPS_LIB   = -L$(OPS_INSTALL_PATH)/c/lib

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
  OMPFLAGS  = -openmp #-openmp-report2
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

TARGETS = trans fvm2dc_seq

all: $(TARGETS)

#
trans:
	ops.py fvm2dc.cpp globalvars.cpp initialize.cpp gridsetup.cpp buildinitialfield.cpp dense.cpp
	mkdir -p ../fvm2dc_ops
	cp *_ops.cpp ../fvm2dc_ops 
	cp globalvars.h ../fvm2dc_ops
	cp Makefile2 ../fvm2dc_ops/Makefile
	cp -rf MPI ../fvm2dc_ops
	#cp -rf MPI_OpenMP ../../fvm2dc_ops
	#cp -rf CUDA ../../fvm2dc_ops
fvm2dc_seq: Makefile fvm2dc.cpp $(OPS_INSTALL_PATH)/c/lib/libops_seq.a
	$(CPP) $(MPIFLAGS)  $(OPS_INC) $(OPS_LIB) -I. globalvars.cpp initialize.cpp gridsetup_ops.cpp buildinitialfield_ops.cpp dense_ops.cpp -I. ./MPI/$(SEQ_KERNELS) fvm2dc_ops.cpp -lops_seq $(HDF5_LIB) -o fvm2dc_seq

clean:
	rm -f fvm2dc_seq globalvars_ops.cpp initialize_ops.cpp gridsetup_ops.cpp buildinitialfield_ops.cpp fvm2dc_ops.cpp *.o result.txt facex.dat facey.dat cellx.dat celly.dat
	rm -f CUDA/*
	rm -f MPI/*
	rm -f MPI_inline/*
	rm -f MPI_OpenMP/*
	rm -f OpenACC/*
	rm -f OpenCL/*
	rm -f Tiled/*
	rm -rf ../fvm2dc_ops/*
