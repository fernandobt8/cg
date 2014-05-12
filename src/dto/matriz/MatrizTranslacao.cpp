/*
 * MatrizTranslacao.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizTranslacao.h"

MatrizTranslacao::MatrizTranslacao(double x, double y, double z) : Matriz() {
	this->initialize(x, y, z);
}

MatrizTranslacao::MatrizTranslacao(Translacao* translacao) : Matriz() {
	this->initialize(translacao->getX(), translacao->getY(), translacao->getZ());
}

void MatrizTranslacao::initialize(double x, double y, double z){
	matriz[0][0] = 1;
	matriz[0][1] = 0;
	matriz[0][2] = 0;
	matriz[0][3] = 0;

	matriz[1][0] = 0;
	matriz[1][1] = 1;
	matriz[1][2] = 0;
	matriz[1][3] = 0;

	matriz[2][0] = 0;
	matriz[2][1] = 0;
	matriz[2][2] = 1;
	matriz[2][3] = 0;

	matriz[3][0] = x;
	matriz[3][1] = y;
	matriz[3][2] = z;
	matriz[3][3] = 1;
}

MatrizTranslacao::~MatrizTranslacao() {
}

