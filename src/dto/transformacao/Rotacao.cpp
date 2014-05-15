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

void Rotacao::setXFinal(double final) {
	xFinal = final;
}

void Rotacao::setYFinal(double final) {
	yFinal = final;
}

void Rotacao::setZFinal(double final) {
	zFinal = final;
}

Vetor* Rotacao::getVetor(){
	Coordenada* inicial = new Coordenada(x, y, z);
	Coordenada* final = new Coordenada(xFinal, yFinal, zFinal);
	Vetor* vetor = new Vetor(inicial, final);
	return vetor;
}

Rotacao::~Rotacao() {
}

