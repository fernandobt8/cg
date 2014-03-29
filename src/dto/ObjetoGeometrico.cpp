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
	while(!coordenadas->empty()){
		delete coordenadas->front();
		coordenadas->pop_front();
	}
}

list<Coordenada*>* ObjetoGeometrico::getCoordenadas() {
	return this->coordenadas;
}

void ObjetoGeometrico::addCoordenada(Coordenada* coordenada) {
	coordenadas->push_back(coordenada);
}

bool ObjetoGeometrico::betweenCoordenadas(Coordenada* start, Coordenada* end) {
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* coordenada = dynamic_cast<Coordenada*>(*it);
		if (coordenada->getX() >= start->getX()
				&& coordenada->getX() <= end->getX()
				&& coordenada->getY() >= start->getY()
				&& coordenada->getY() <= end->getY()) {
			return true;
		}
	}
	return false;
}

void ObjetoGeometrico::addToAllCoordenadas(Coordenada* coordenada) {
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* current = dynamic_cast<Coordenada*>(*it);
		if (current) {
			current->addToX(coordenada->getX());
			current->addToY(coordenada->getY());
		}
	}
}

void ObjetoGeometrico::subToAllCoordenadas(Coordenada* coordenada) {
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* current = dynamic_cast<Coordenada*>(*it);
		if (current) {
			current->addToX(-coordenada->getX());
			current->addToY(-coordenada->getY());
		}
	}
}

char* ObjetoGeometrico::getNome() {
	return this->nome;
}

