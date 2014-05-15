/*
 * Vetor.cpp
 *
 *  Created on: 15/05/2014
 *      Author: alisson
 */

#include "Vetor.h"

Vetor::Vetor(Coordenada *inicial, Coordenada* final) {
	this->inicial = inicial;
	this->final = final;
}

Vetor::~Vetor() {
	delete inicial;
	delete final;
}

Coordenada* Vetor::getCoordenadaInicial() {
	return inicial;
}

Coordenada* Vetor::getCoordenadaFinal() {
	return final;
}
