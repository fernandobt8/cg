/*
 * MatrizHermite.cpp
 *
 *  Created on: 01/05/2014
 *      Author: fernandobt8
 */

#include "MatrizHermite.h"

MatrizHermite::MatrizHermite() : Matriz(4, 4){
	matriz[0][0] = 2;
	matriz[0][1] = -2;
	matriz[0][2] = 1;
	matriz[0][3] = 1;

	matriz[1][0] = -3;
	matriz[1][1] = 3;
	matriz[1][2] = -2;
	matriz[1][3] = 1;

	matriz[2][0] = 0;
	matriz[2][1] = 0;
	matriz[2][2] = 1;
	matriz[2][3] = 0;

	matriz[3][0] = 1;
	matriz[3][1] = 0;
	matriz[3][2] = 0;
	matriz[3][3] = 0;
}

MatrizHermite::~MatrizHermite() {
	// TODO Auto-generated destructor stub
}
