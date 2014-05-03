/*
 * MatrizBSplines.cpp
 *
 *  Created on: 03/05/2014
 *      Author: fernandobt8
 */

#include "MatrizBSplines.h"

MatrizBSplines::MatrizBSplines() : Matriz(4, 4){
	matriz[0][0] = -1.0/6.0;
	matriz[0][1] = (1.0/2.0);
	matriz[0][2] = (-1.0/2.0);
	matriz[0][3] = (1.0/6.0);

	matriz[1][0] = (1.0/2.0);
	matriz[1][1] = -1;
	matriz[1][2] = (1.0/2.0);
	matriz[1][3] = 0;

	matriz[2][0] = (-1.0/2.0);
	matriz[2][1] = 0;
	matriz[2][2] = (1.0/2.0);
	matriz[2][3] = 0;

	matriz[3][0] = (1.0/6.0);
	matriz[3][1] = (2.0/3.0);
	matriz[3][2] = (1.0/6.0);
	matriz[3][3] = 0;
}

MatrizBSplines::~MatrizBSplines() {
}

