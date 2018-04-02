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

	ops_par_loop(gridsetup_kernel_x, "gridsetup_kernel_x", fvm2d_grid, 2, iter_range,
	              ops_arg_dat(facex, 1, S2D_00, "double", OPS_WRITE),
	              ops_arg_idx());




	ops_print_dat_to_txtfile(facex, "facex.dat");
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
