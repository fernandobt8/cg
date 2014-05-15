/*
 * MatrizRotacao.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizRotacao.h"


MatrizRotacao::MatrizRotacao(double angulo,  Rotacao::Round around) : Matriz(){
	double radianos = Utils::convertGrausToRadianos(angulo);
	bool aroundX = around == Rotacao::AROUND_X;
	bool aroundY = around == Rotacao::AROUND_Y;
	bool aroundZ = around == Rotacao::AROUND_Z;

	matriz[0][0] = !aroundX ? cos(radianos) : 1;
	matriz[0][1] = aroundZ ?  sin(radianos) : 0;
	matriz[0][2] = aroundY ? -sin(radianos) : 0;
	matriz[0][3] = 0;

	matriz[1][0] = aroundZ ? -sin(radianos) : 0;
	matriz[1][1] = !aroundY ? cos(radianos) : 1;
	matriz[1][2] = aroundX ?  sin(radianos) : 0;
	matriz[1][3] = 0;

	matriz[2][0] = aroundY ?  sin(radianos) : 0;
	matriz[2][1] = aroundX ? -sin(radianos) : 0;
	matriz[2][2] = !aroundZ ? cos(radianos) : 1;
	matriz[2][3] = 0;

	matriz[3][0] = 0;
	matriz[3][1] = 0;
	matriz[3][2] = 0;
	matriz[3][3] = 1;
}

MatrizRotacao::~MatrizRotacao() {
}

