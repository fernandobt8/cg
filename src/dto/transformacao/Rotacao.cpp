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
	this->around = Rotacao::AROUND_X;
}

Rotacao::Rotacao(double angulo, Rotacao::Tipo tipoRotacao, Rotacao::Round around) : Transformacao("Rotação") {
	this->angulo = angulo;
	this->tipoRotacao = tipoRotacao;
	this->around = around;
}

Rotacao::~Rotacao() {
}

