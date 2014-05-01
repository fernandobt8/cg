/*
 * Rotacao.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Rotacao.h"

Rotacao::Rotacao() : Transformacao("Rotação") {
	this->angulo = 0;
	this->tipoRotacao = Rotacao::CENTRO;
}

Rotacao::Rotacao(double angulo, Rotacao::Tipo tipoRotacao) : Transformacao("Rotação") {
	this->angulo = angulo;
	this->tipoRotacao = tipoRotacao;
}

Rotacao::~Rotacao() {
}

