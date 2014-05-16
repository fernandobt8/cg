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
	this->around = Rotacao::AROUND_Y;
	this->coordenadaFinal = new Coordenada();
}

Rotacao::Rotacao(double angulo, Rotacao::Tipo tipoRotacao, Rotacao::Round around) : Transformacao("Rotação") {
	this->angulo = angulo;
	this->tipoRotacao = tipoRotacao;
	this->around = around;
	this->coordenadaFinal = new Coordenada();
}

void Rotacao::setXFinal(double final) {
	coordenadaFinal->setX(final);
}

void Rotacao::setYFinal(double final) {
	coordenadaFinal->setY(final);
}

void Rotacao::setZFinal(double final) {
	coordenadaFinal->setZ(final);
}

Coordenada* Rotacao::getCoordenadaFinal(){
	return coordenadaFinal;
}

Rotacao::~Rotacao() {
	delete coordenadaFinal;
}

