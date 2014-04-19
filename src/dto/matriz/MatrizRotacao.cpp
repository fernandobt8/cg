/*
 * MatrizRotacao.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizRotacao.h"

MatrizRotacao::MatrizRotacao(Coordenada* center, Rotacao* rotacao) : Matriz(){
	this->initialize(rotacao->angulo);
	if(rotacao->tipoRotacao != ORIGEM){
		double x;
		double y;
		if(rotacao->tipoRotacao == CENTRO){
			x = center->getX();
			y = center->getY();
		} else if(rotacao->tipoRotacao == PONTO){
			x = rotacao->getX();
			y = rotacao->getY();
		}
			Matriz* transCenter = new MatrizTranslacao(-x, -y);
			transCenter->multiply(this);

			Matriz* transCenterBack = new MatrizTranslacao(x, y);
			transCenter->multiply(transCenterBack);

			this->clearMatriz();
			this->matriz = transCenter->getMatriz();
			delete transCenter;
			delete transCenterBack;
	}
}

MatrizRotacao::MatrizRotacao(double angulo) : Matriz(){
	initialize(angulo);
}

void MatrizRotacao::initialize(double angulo){
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

