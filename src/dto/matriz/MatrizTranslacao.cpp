/*
 * MatrizTranslacao.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizTranslacao.h"

MatrizTranslacao::MatrizTranslacao(double x, double y) : Matriz() {
	this->initialize(x, y);
}

MatrizTranslacao::MatrizTranslacao(Translacao* translacao) : Matriz() {
	this->initialize(translacao->getX(), translacao->getY());
}

void MatrizTranslacao::initialize(double x, double y){
	matriz[0][0] = 1;
	matriz[0][1] = 0;
	matriz[0][2] = 0;

	matriz[1][0] = 0;
	matriz[1][1] = 1;
	matriz[1][2] = 0;

	matriz[2][0] = x;
	matriz[2][1] = y;
	matriz[2][2] = 1;
}

MatrizTranslacao::~MatrizTranslacao() {
}

