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
	windowCoordenadas = new list<Coordenada*>();
}

ObjetoGeometrico::ObjetoGeometrico(char* nome) {
	this->nome = nome;
	this->coordenadas = new list<Coordenada* >();
	windowCoordenadas = new list<Coordenada*>();
}

list<Coordenada*>* ObjetoGeometrico::getWindowCoordenadas() {
	return this->windowCoordenadas;
}

void ObjetoGeometrico::addCoordenada(Coordenada* coordenada) {
	coordenadas->push_back(coordenada);
}

void ObjetoGeometrico::addToAllCoordenadas(Coordenada* coordenada) {
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* current = *it;
		current->addToX(coordenada->getX());
		current->addToY(coordenada->getY());
	}
}

void ObjetoGeometrico::updateWindowCoordenadas(Coordenada* windowStart) {
	delete windowCoordenadas;
	windowCoordenadas = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* windowCoor = static_cast<Coordenada*>(*it)->clone();
		windowCoor->addToX(- windowStart->getX());
		windowCoor->addToY(- windowStart->getY());
		windowCoordenadas->push_back(windowCoor);
	}
}

char* ObjetoGeometrico::getNome() {
	return this->nome;
}

ObjetoGeometrico::~ObjetoGeometrico() {
	delete coordenadas;
	delete windowCoordenadas;
	delete nome;
}

