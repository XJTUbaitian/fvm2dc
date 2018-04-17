/*

 Open source copyright declaration based on BSD open source template:
 https://opensource.org/licenses/BSD-3-Clause

 This file is part of the fvm2d distribution.


 Copyright (c) 2018, Mingtao Li.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 * Neither the name of the copyright holder nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY Mingtao Li "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


 @author Mingtao Li
 mingtao.li@gmail.com

 @author Tian Bai
 */

/*
 * fvm2dc.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: Mingtao Li
 */

// standard headers
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// OPS header file
#define  OPS_2D
#include "ops_seq.h"

// fvm2dc constants
#include "globalvars.h"

// fvm2dc functions
void initialize();
void gridsetup();
void buildinitialfield();
void dense();
void coeffients_uvp();

int main(int argc, char **argv) {

	if ((fp = fopen("result.txt", "w")) == NULL) {
		printf("can't open file %s\n", "result.txt");
		exit(2);
	} //open result.txt

	lstop = 0;
	//lsolve[NFX4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//lprint[NFX4] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	//lblk[NFX4] =   {1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	lprint[4] = true;
	title[4] = "temperature";

	xmin = 0.0;
	xmax = 1.0;
	xlength = xmax - xmin;
	ymin = 0.0;
	ymax = 2.0;
	ylength = ymax - ymin;

	xcells = 5;
	ycells = 8;

	xL1 = xcells + 2;
	yM1 = ycells + 2;

	xL2 = xL1 - 1;
	xL3 = xL2 - 1;
	yM2 = yM1 - 1;
	yM3 = yM2 - 1;
	coordmode = 1;
	ops_init(argc, argv, 5);

	initialize();

	gridsetup();

//  ops_diagnostic_output();

	buildinitialfield();

	 while (lstop==0) {
	 dense();
//	 bound();
//	 output();
//	 iternext();
	 coeffients_uvp();
	 }

//	 output();

	ops_exit();
	return 0;

}

