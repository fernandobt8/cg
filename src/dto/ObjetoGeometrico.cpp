/*
 * ObjetoGeometrico.cpp
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#include "ObjetoGeometrico.h"

ObjetoGeometrico::ObjetoGeometrico(char* nome, Coordenada** coordenadas) {
	this->coordenadas = coordenadas;
	this->nome = nome;
}

ObjetoGeometrico::~ObjetoGeometrico() {
}

Coordenada** ObjetoGeometrico::getCoordenadas() {
	return this->coordenadas;
}

char* ObjetoGeometrico::getNome(){
	return this->nome;
}

