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
	int iter_range[] = {0,xL1,0,1};

	ops_par_loop(gridsetup_kernel_facex, "gridsetup_kernel_facex", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facex, 1, S2D_00, "double", OPS_WRITE),
	              ops_arg_idx());




	ops_print_dat_to_txtfile(facex, "facex.dat");
	iter_range[0] = 0;
	iter_range[1] = 1;
	iter_range[2] = 0;
	iter_range[3] = yM1;
	ops_par_loop(gridsetup_kernel_facey, "gridsetup_kernel_facey", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facey, 1, S2D_00, "double", OPS_WRITE),
	              ops_arg_idx());

	ops_print_dat_to_txtfile(facey, "facey.dat");
/*
	iter_range[0] = 0;
	iter_range[0] = 0;
	iter_range[0] = 0;
	iter_range[0] = ycells;

	ops_par_loop(gridsetup_kernel_x, "facesetup_kernel", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facey, 1, S2D_00, "double", OPS_WRITE),
	              ops_arg_idx());
	ops_print_dat_to_txtfile(facex, "facex.dat");
*/
}
