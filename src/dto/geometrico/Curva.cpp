/*
 * Curva.cpp
 *
 *  Created on: 27/04/2014
 *      Author: alisson
 */

#include "Curva.h"

Curva::Curva(const char *nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas) {
	this->pontosControle = new list<Coordenada* >();
}

Curva::Curva(const char *nome) : ObjetoGeometrico(nome) {
	this->pontosControle = new list<Coordenada* >();
}

void Curva::addPontoControle(Coordenada* coordenada) {
	this->pontosControle->push_back(coordenada);
}

Curva::~Curva() {
	delete pontosControle;
}

