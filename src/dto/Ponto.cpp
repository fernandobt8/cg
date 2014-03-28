/*
 * Ponto.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Ponto.h"

Ponto::Ponto(char* nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas) {
}

Ponto::Ponto(char* nome) : ObjetoGeometrico(nome) {
}

Ponto::~Ponto() {
}


