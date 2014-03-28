/*
 * ObjetoGeometrico.cpp
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#include "ObjetoGeometrico.h"

ObjetoGeometrico::ObjetoGeometrico(char* nome, list<Coordenada*>* coordenadas) {
	this->coordenadas = coordenadas;
	this->nome = nome;
}

ObjetoGeometrico::ObjetoGeometrico(char* nome) {
	this->nome = nome;
}

ObjetoGeometrico::~ObjetoGeometrico() {
}

list<Coordenada*>* ObjetoGeometrico::getCoordenadas() {
	return this->coordenadas;
}

void ObjetoGeometrico::addCoordenada(Coordenada* coordenada){
	coordenadas->push_back(coordenada);
}

bool ObjetoGeometrico::isAfterCoordenada(Coordenada* coordenada){
	list<Coordenada* >::iterator it = coordenadas->begin();
}

void ObjetoGeometrico::addToAllCoordenadas(Coordenada* coordenada){
	list<Coordenada* >::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* current = dynamic_cast<Coordenada* >(*it);
		if(current){
			current->addToX(coordenada->getX());
			current->addToY(coordenada->getY());
		}
	}
}

char* ObjetoGeometrico::getNome(){
	return this->nome;
}

