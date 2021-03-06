/*
 * MatrizHermite.cpp
 *
 *  Created on: 01/05/2014
 *      Author: fernandobt8
 */

#include "MatrizBezier.h"

MatrizBezier::MatrizBezier() : Matriz(4, 4){
	matriz[0][0] = -1;
	matriz[0][1] = 3;
	matriz[0][2] = -3;
	matriz[0][3] = 1;

	matriz[1][0] = 3;
	matriz[1][1] = -6;
	matriz[1][2] = 3;
	matriz[1][3] = 0;

	matriz[2][0] = -3;
	matriz[2][1] = 3;
	matriz[2][2] = 0;
	matriz[2][3] = 0;

	matriz[3][0] = 1;
	matriz[3][1] = 0;
	matriz[3][2] = 0;
	matriz[3][3] = 0;
}

MatrizBezier::~MatrizBezier() {
}
