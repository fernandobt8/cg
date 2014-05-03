/*
 * MatrizDelta.cpp
 *
 *  Created on: 03/05/2014
 *      Author: fernandobt8
 */

#include "MatrizDelta.h"

MatrizDelta::MatrizDelta(double delta) : Matriz(4, 4) {
	matriz[0][0] = 0;
	matriz[0][1] = 0;
	matriz[0][2] = 0;
	matriz[0][3] = 1;

	matriz[1][0] = pow(delta, 3);
	matriz[1][1] = pow(delta, 2);
	matriz[1][2] = delta;
	matriz[1][3] = 0;

	matriz[2][0] = 6 * pow(delta, 3);
	matriz[2][1] = 2 * pow(delta, 2);
	matriz[2][2] = 0;
	matriz[2][3] = 0;

	matriz[3][0] = 6 * pow(delta, 3);
	matriz[3][1] = 0;
	matriz[3][2] = 0;
	matriz[3][3] = 0;
}

MatrizDelta::~MatrizDelta() {
}

