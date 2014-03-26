/*
 * Ponto.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Ponto.h"

Ponto::Ponto(char* nome, Coordenada** coordenada) : ObjetoGeometrico(nome, coordenada) {
	this->nome = nome;
	this->coordenada = coordenada;
}

Ponto::~Ponto() {
	// TODO Auto-generated destructor stub
}

Coordenada** Ponto::getCoordenadasParaDesenho(){
	return this->getCoordenada();
}

