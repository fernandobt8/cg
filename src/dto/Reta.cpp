/*
 * Reta.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Reta.h"

Reta::Reta(char *nome, Coordenada** coordenada) :
		ObjetoGeometrico(nome, coordenada) {
	this->nome = nome;
	this->coordenada = coordenada;
}

Reta::~Reta() {
	// TODO Auto-generated destructor stub
}

Coordenada** Reta::getCoordenadasParaDesenho() {

}

