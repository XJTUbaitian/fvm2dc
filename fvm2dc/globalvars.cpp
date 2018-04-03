/*
 * globalvars.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: limingtao
 */

#include "globalvars.h"

//ops block
ops_block fvm2d_grid; //grid

//ops dats
ops_dat facex; // xu
ops_dat facey; // yv
ops_dat cellx; // x
ops_dat celly; // y
ops_dat celldx; // xdif
ops_dat celldy; // ydif
ops_dat facedx; // xcv
ops_dat facedy; // ycv
ops_dat xcvs; // xcvs
ops_dat ycvs; // ycvs

ops_dat xcvi; // xcvi
ops_dat xcvip; // xcvip


ops_dat ycvr; // xcvi
ops_dat ycvrs; // xcvip

ops_dat arx;
ops_dat arxj;
ops_dat arxjp;
ops_dat radius;
ops_dat rmn;

ops_dat sx;
ops_dat sxmn;

ops_dat xvel0; // U
ops_dat yvel0; // V
ops_dat presscorr; // P
ops_dat density; // RHO
ops_dat temperature; // T
ops_dat xvelhat; // UHAT
ops_dat yvelhat; // VHAT

//commonly used stencils
ops_stencil S2D_00; // 00
ops_stencil S2D_00_P10; // 00:10
ops_stencil S2D_00_M10; // 00:-10
ops_stencil S2D_00_0P1; // 00:01
ops_stencil S2D_00_0M1; // 00:0-1
ops_stencil S2D_00_P10_M10; //00:10:-10
ops_stencil S2D_00_P10_M10_0P1_0M1;

FILE *fp;

double xmin;
double ymin;
double xmax;
double ymax;
double xlength;
double ylength;
int xcells;
int ycells;
int xL1;
int xL2;
int xL3;
int yM1;
int yM2;
int yM3;
int iter;
bool lsolve[14];
bool lprint[14];
bool lblk[14];
bool lstop;
string title[14];
int coordmode=1;
