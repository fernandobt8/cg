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
	this->windowCoordenadas = new list<Coordenada*>();
}

char* ObjetoGeometrico::getNome() {
	return this->nome;
}

list<Coordenada*>* ObjetoGeometrico::getWindowCoordenadas() {
	return this->windowCoordenadas;
}

list<Coordenada*>* ObjetoGeometrico::getCoordenadas() {
	return this->coordenadas;
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

Coordenada* ObjetoGeometrico::getCenter(){
	int numberPoints = 0;
	double somaX = 0;
	double somaY = 0;
	list<Coordenada* >::iterator it = coordenadas->begin();
	for(; it != coordenadas->end();it++){
		Coordenada* coordenada = *it;
		somaX += coordenada->getX();
		somaY += coordenada->getY();
		numberPoints++;
	}
	return new Coordenada(somaX/numberPoints, somaY/numberPoints);
}

ObjetoGeometrico::~ObjetoGeometrico() {
	delete coordenadas;
	delete windowCoordenadas;
	delete nome;
}

