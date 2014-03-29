/*
 * Poligono.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "Poligono.h"

Poligono::Poligono(char* nome, list<Coordenada*> *retas) : ObjetoGeometrico(nome, 0){
	this->coordenadas = retas;
}

Poligono::~Poligono() {
	// TODO Auto-generated destructor stub
}

void Poligono::addObjeto(Coordenada *coordenadas){
	this->coordenadas->push_back(coordenadas);
}

list<Coordenada*>* Poligono::getCoordenadas(){
	return this->coordenadas;
}

