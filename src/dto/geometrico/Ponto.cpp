/*
 * Ponto.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Ponto.h"
Ponto::Ponto(const char* nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas) {
}

Ponto::Ponto(const char* nome) : ObjetoGeometrico(nome) {
}

Ponto* Ponto::clone(){
	Ponto* p = new Ponto(Utils::cloneChar(this->nome));
	p->getCPPCoordenadas()->push_back(CPPcoordenadas->front()->clone());
	return p;
}

Ponto::~Ponto() {
}


