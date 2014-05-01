/*
 * MatrizRotacao.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizRotacao.h"


MatrizRotacao::MatrizRotacao(double angulo) : Matriz(){
	matriz[0][0] = cos(angulo*(PI/180));
	matriz[0][1] = -sin(angulo*(PI/180));
	matriz[0][2] = 0;

	matriz[1][0] = sin(angulo*(PI/180));
	matriz[1][1] = cos(angulo*(PI/180));
	matriz[1][2] = 0;

	matriz[2][0] = 0;
	matriz[2][1] = 0;
	matriz[2][2] = 1;
}

MatrizRotacao::~MatrizRotacao() {
}

