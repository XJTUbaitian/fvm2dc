/*
 * globalvars.h
 *
 *  Created on: Mar 31, 2018
 *      Author: limingtao mingtao.li@gmail.com
 */

#ifndef FVM2DC_GLOBALVARS_H_
#define FVM2DC_GLOBALVARS_H_

#define  OPS_2D
#include "ops_lib_cpp.h"

//ops block
extern ops_block fvm2d_grid; //grid

//ops dats
extern ops_dat facex; // xu
extern ops_dat facey; // yv
extern ops_dat cellx; // x
extern ops_dat celly; // y
extern ops_dat celldx; // xdif
extern ops_dat celldy; // ydif
extern ops_dat facedx; // xcv
extern ops_dat facedy; // ycv
extern ops_dat xcvs; // xcvs
extern ops_dat ycvs; // ycvs
extern ops_dat xvel0; // U
extern ops_dat yvel0; // V
extern ops_dat presscorr; // P
extern ops_dat density; // RHO
extern ops_dat temperature; // T
extern ops_dat xvelhat; // UHAT
extern ops_dat yvelhat; // VHAT

//extern ops_dat variable1;



//commonly used stencils
extern ops_stencil S2D_00; // 00
extern ops_stencil S2D_00_P10_M10_0P1_0M1;
extern FILE *fp;

//extern string title();
//extern bool lsolve(),lprint(),lblk(),lstop;

extern double xmin;
extern double ymin;
extern double xmax;
extern double ymax;
extern double xlength;
extern double ylength;
extern int xcells;
extern int ycells;
extern int xL1;
extern int xL2;
extern int xL3;
extern int yM1;
extern int yM2;
extern int yM3;
extern int iter;


#endif /* FVM2DC_GLOBALVARS_H_ */
