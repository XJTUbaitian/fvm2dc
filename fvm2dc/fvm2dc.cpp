/*
 * fvm2dc.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: limingtao
 */

// standard headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// OPS header file
#define  OPS_2D
#include "ops_seq.h"

#include "globalvars.h"

int main(int argc, char **argv)
{

if ((fp = fopen("result.txt", "w")) == NULL) {
    printf("can't open file %s\n","result.txt");
    exit(2);
  }
iter=500;

xmin = 0.0;
xmax = 1.0;
xlength = xmax - xmin;
ymin = 0.0;
ymax = 2.0;
ylength = ymax - ymin;

xcells = 3;
ycells = 5;

xL1=xcells+2;
yM1=ycells+2;

xL2=xL1-1;
xL3=xL2 -1;
yM2=yM1-1;
yM3=yM2-1;
ops_init(argc,argv,5);

//  ops_diagnostic_output();

fvm2d_grid = ops_decl_block(2, "fvm2d_grid");



//  ops_diagnostic_output();


int d_p[2]={0,0};
int d_m[2]={0,0};
int base[2]={0,0};
int size[2]={xL1+1,yM1+1};
double *temp = NULL;


//XU
size[0]=xL1+1;
size[1]=1;
facex = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "facex");


//YV
size[0]=1;
size[1]=yM1+1;
facey = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "facey");
//X
size[0]=xL1;
size[1]=1;
cellx = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "cellx");

//Y
size[0]=1;
size[1]=yM1;
celly = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "celly");


//XDIF
size[0]=xL1;
size[1]=1;
celldx = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "celldx");


//YDIF
size[0]=1;
size[1]=yM1;
celldy = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "celldy");

//XCV
size[0]=xL1;
size[1]=1;
facedx = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "facedx");

//YCV
size[0]=1;
size[1]=yM1;
facedy = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "facedy");
size[0]=xL1;
size[1]=yM1;
xvel0      = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "xvel0");
yvel0      = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "yvel0");
presscorr  = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "presscorr");
density    = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "density");
temperature= ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "temperature");
xvelhat    = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "xvelhat");
yvelhat    = ops_decl_dat(fvm2d_grid, 1, size, base, d_m, d_p, temp, "double", "yvelhat");





ops_diagnostic_output();

int s2D_00[]   = {0,0};
S2D_00         = ops_decl_stencil( 2, 1, s2D_00, "00");

int s2D_00_P10_M10_0P1_0M1[]   = {0,0,1,0,-1,0,0,1,0,-1};
S2D_00_P10_M10_0P1_0M1 =  ops_decl_stencil( 2, 5, s2D_00_P10_M10_0P1_0M1, "00:10:-10:01:0-1");


//ops_diagnostic_output();
int iter_range[] = {0,xL1,0,1};

ops_par_loop(facesetup_kernel, "facesetup_kernel", fvm2d_grid, 2, iter_range,
              ops_arg_dat(facex, 1, S2D_00, "double", OPS_WRITE),
              ops_arg_idx());

ops_print_dat_to_txtfile(facex, "facex.dat");

iter_range[0] = 0;
iter_range[0] = 0;
iter_range[0] = 0;
iter_range[0] = ycells;

ops_par_loop(facesetup_kernel, "facesetup_kernel", fvm2d_grid, 2, iter_range,
              ops_arg_dat(facey, 1, S2D_00, "double", OPS_WRITE),
              ops_arg_idx());
ops_exit();
return 0;


}


