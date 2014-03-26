/*
 * Ponto.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Ponto.h"

Ponto::Ponto(int x, int y) : ObjetoGeometrico(x, y) {

}

Ponto::~Ponto() {
	// TODO Auto-generated destructor stub
}

Coordenada* Ponto::getCoordenadasParaDesenho(){
	return this->getCoordenada();
}

