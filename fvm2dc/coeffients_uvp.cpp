/*
 * coeffients_uvp.cpp
 *
 *  Created on: 2018年4月17日
 *      Author: limingtao
 */

//计算uvp方程的系数
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// OPS header file
#define  OPS_2D
#include "ops_seq.h"

#include "globalvars.h"

#include "coeffients_uvp_kernel.h"

void coeffients_uvp(){


	int iter_range[] = { 0, 1, 0, 1 }; //局部变量

	//gamsor();

	iter_range[0] = 1;
	iter_range[1] = xL1+1;
	iter_range[2] = 1;
	iter_range[3] = yM1+1;



	ops_par_loop(coeffients_uvp_kernel_setupU,
			"coeffients_uvp_kernel_setupU", fvm2dc_grid, 2,
			iter_range,
			ops_arg_dat(ucon, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(uaip, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(uaim, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(uajp, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(uajm, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(uapp, 1, S2D_00, "double", OPS_WRITE),

			ops_arg_dat(arx, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(u_xvel0, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(density, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(gam, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(xcv_facedx, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(sx, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(fx, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(fxm, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(xcvi, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(xcvip, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(v_yvel0, 1, S2D_00, "double", OPS_READ),
			ops_arg_dat(radius, 1, S2D_00, "double", OPS_READ),
			ops_arg_idx());



	ops_par_loop(coeffients_uvp_kernel_setupV,
			"coeffients_uvp_kernel_setupU", fvm2dc_grid, 2,
			iter_range, ops_arg_dat(radius, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(sx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(rmn, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_idx());
	ops_par_loop(coeffients_uvp_kernel_setupP,
			"coeffients_uvp_kernel_setupU", fvm2dc_grid, 2,
			iter_range, ops_arg_dat(radius, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(sx, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_dat(rmn, 1, S2D_00, "double", OPS_WRITE),
			ops_arg_idx());

	lstop=1;
}

