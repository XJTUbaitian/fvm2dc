/*
 * gridsetup.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: limingtao
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// OPS header file
#define  OPS_2D
#include "ops_seq.h"

#include "globalvars.h"

#include "gridsetup_kernel.h"


void gridsetup()
{
	//ops_diagnostic_output();
	int iter_range[] = {0,xL1+1,0,1};

	ops_par_loop(gridsetup_kernel_facex, "gridsetup_kernel_facex", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facex, 1, S2D_00, "double", OPS_WRITE),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_cellx, "gridsetup_kernel_cellx", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(cellx, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(facex, 1, S2D_00_P10, "double", OPS_READ),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_facedx, "gridsetup_kernel_facedx", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facedx, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(facex, 1, S2D_00_M10, "double", OPS_READ),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_celldx, "gridsetup_kernel_celldx", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(celldx, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(cellx, 1, S2D_00_M10, "double", OPS_READ),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_xcvs, "gridsetup_kernel_xcvs", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(xcvs, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(celldx, 1, S2D_00_P10_M10, "double", OPS_READ),
	              ops_arg_idx());

	iter_range[0] = 0;
	iter_range[1] = 1;
	iter_range[2] = 0;
	iter_range[3] = yM1+1;
	ops_par_loop(gridsetup_kernel_facey, "gridsetup_kernel_facey", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facey, 1, S2D_00, "double", OPS_WRITE),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_celly, "gridsetup_kernel_celly", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(celly, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(facey, 1, S2D_00_0P1, "double", OPS_READ),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_facedy, "gridsetup_kernel_facedy", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facedy, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(facey, 1, S2D_00_0M1, "double", OPS_READ),
	              ops_arg_idx());

	ops_par_loop(gridsetup_kernel_celldy, "gridsetup_kernel_celldy", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(celldy, 1, S2D_00, "double", OPS_WRITE),
				  ops_arg_dat(celly, 1, S2D_00_0M1, "double", OPS_READ),
	              ops_arg_idx());


//	ops_print_dat_to_txtfile(facex, "facex.dat");
//	ops_print_dat_to_txtfile(facey, "facey.dat");
//	ops_print_dat_to_txtfile(cellx, "cellx.dat");
//	ops_print_dat_to_txtfile(celly, "celly.dat");
//	ops_print_dat_to_txtfile(celldx, "celldx.dat");
//	ops_print_dat_to_txtfile(celldy, "celldy.dat");
//	ops_print_dat_to_txtfile(facedx, "facedx.dat");
//	ops_print_dat_to_txtfile(facedy, "facedy.dat");

	if(coordmode==1){

	}
	else if(coordmode==2){

	}
	else if(coordmode==3){

	}
	else
	{

	}

}
