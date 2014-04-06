/*
 * Reta.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Reta.h"

Reta::Reta(const char *nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas) {
}
Reta::Reta(const char *nome) : ObjetoGeometrico(nome) {
}
Reta::~Reta() {
}



