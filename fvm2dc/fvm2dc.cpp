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
#include "ops_seq.h"

// fvm2dc constants
#include "globalvars.h"


// fvm2dc functions
void initialize();
void gridsetup();


int main(int argc, char **argv) {

	if ((fp = fopen("result.txt", "w")) == NULL) {
		printf("can't open file %s\n", "result.txt");
		exit(2);
	}
	iter = 500;

	xmin = 0.0;
	xmax = 1.0;
	xlength = xmax - xmin;
	ymin = 0.0;
	ymax = 2.0;
	ylength = ymax - ymin;

	xcells = 3;
	ycells = 5;

	xL1 = xcells + 2;
	yM1 = ycells + 2;

	xL2 = xL1 - 1;
	xL3 = xL2 - 1;
	yM2 = yM1 - 1;
	yM3 = yM2 - 1;
	ops_init(argc, argv, 5);

	initialize();

	gridsetup();

//  ops_diagnostic_output();

//buildinitialfield();
/*
	while () {
		dense();
		bound();
		output();
		iternext();
	}

	output();
*/
	ops_exit();
	return 0;

}

