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
 */

/*
 * buildinitialfiels_kernel.h
 *
 *  Created on: Apr 2, 2018
 *      Author: limingtao
 */

#ifndef BUILDINITIALFIELS_KERNEL_H_
#define BUILDINITIALFIELS_KERNEL_H_

void buildinitialfield_kernel_setupinitialfield(double *pc_presscorr,
		double *u_xvel0, double *v_yvel0, double *con, double *app,
		double *density, double *cp, double *pressure, int *idx) {

	pc_presscorr[OPS_ACC0(0, 0)] = 0.0;
	u_xvel0[OPS_ACC1(0, 0)] = 0.0;
	v_yvel0[OPS_ACC2(0, 0)] = 0.0;
	con[OPS_ACC3(0, 0)] = 0.0;
	app[OPS_ACC4(0, 0)] = 0.0;
	density[OPS_ACC5(0, 0)] = rhocon;
	cp[OPS_ACC6(0, 0)] = cpcon;
	pressure[OPS_ACC7(0, 0)] = 0.0;

}

void buildinitialfield_kernel_start(double *t_temperature, double *x_cellx,
		double *y_celly, int *idx) {

	if (idx[0] == 1 | idx[0] == xL1 | idx[1] == 1 | idx[1] == yM1) {

		t_temperature[OPS_ACC0(0, 0)] = x_cellx[OPS_ACC1(0, 0)]
												+ y_celly[OPS_ACC2(0, 0)]
														  + x_cellx[OPS_ACC1(0, 0)] * y_celly[OPS_ACC2(0, 0)];

	} else {
		t_temperature[OPS_ACC0(0, 0)] = 0.0;

	}

}

#endif /* BUILDINITIALFIELS_KERNEL_H_ */
