/*
 * Poligono.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "Poligono.h"

Poligono::Poligono(const char* nome, list<Coordenada*> *coordenadas) : ObjetoGeometrico(nome, coordenadas){
	aberto = false;
}

Poligono::Poligono(const char* nome) : ObjetoGeometrico(nome){
	coordenadas = new list<Coordenada*>();
	CPPcoordenadas = new list<Coordenada*>();
	aberto = false;
}

Poligono::~Poligono() {
	delete color;
}


