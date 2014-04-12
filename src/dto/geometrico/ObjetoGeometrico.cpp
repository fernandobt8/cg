/*
 * ObjetoGeometrico.cpp
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#include "ObjetoGeometrico.h"

ObjetoGeometrico::ObjetoGeometrico(const char* nome, list<Coordenada*>* coordenadas) {
	this->coordenadas = coordenadas;
	this->nome = nome;
	windowCoordenadas = new list<Coordenada*>();
	CPPcoordenadas = new list<Coordenada*>();
}

ObjetoGeometrico::ObjetoGeometrico(const char* nome) {
	this->nome = nome;
	this->coordenadas = new list<Coordenada* >();
	CPPcoordenadas = new list<Coordenada*>();
	this->windowCoordenadas = new list<Coordenada*>();
}

void ObjetoGeometrico::multipliqueCoordenadas(Matriz* matriz){
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		static_cast<Coordenada*>(*it)->vezesMatriz(matriz);
	}
}

void ObjetoGeometrico::multipliqueCPPcoordenadas(Matriz* matriz) {
	delete CPPcoordenadas;
	CPPcoordenadas = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* CPPcoor = static_cast<Coordenada*>(*it)->clone();
		CPPcoor->vezesMatriz(matriz);
		CPPcoordenadas->push_back(CPPcoor);
	}
}

void ObjetoGeometrico::subWindowCoordenadas(Coordenada* coordenada) {
	delete windowCoordenadas;
	windowCoordenadas = new list<Coordenada*>();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	for (; it != CPPcoordenadas->end(); it++) {
		Coordenada* windowCoor = static_cast<Coordenada*>(*it)->clone();
		windowCoor->addToX(- coordenada->getX());
		windowCoor->addToY(- coordenada->getY());
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

void ObjetoGeometrico::addCoordenada(Coordenada* coordenada) {
	coordenadas->push_back(coordenada);
}

list<Coordenada*>* ObjetoGeometrico::getWindowCoordenadas() {
	return this->windowCoordenadas;
}

const char* ObjetoGeometrico::getNome() {
	return this->nome;
}

void ObjetoGeometrico::printAllcoordenadas(){
	list<Coordenada* >::iterator it = coordenadas->begin();
	for(; it != coordenadas->end();it++){
		Coordenada* coordenada = *it;
		printf("x: %f, y: %f \n", coordenada->getX(), coordenada->getY());
	}
}

void ObjetoGeometrico::printAllCPPcoordenadas(){
	list<Coordenada* >::iterator it = CPPcoordenadas->begin();
	for(; it != CPPcoordenadas->end();it++){
		Coordenada* coordenada = *it;
		printf("x: %f, y: %f \n", coordenada->getX(), coordenada->getY());
	}
}

void ObjetoGeometrico::printAllWindowcoordenadas(){
	list<Coordenada* >::iterator it = windowCoordenadas->begin();
	for(; it != windowCoordenadas->end();it++){
		Coordenada* coordenada = *it;
		printf("x: %f, y: %f \n", coordenada->getX(), coordenada->getY());
	}
}

ObjetoGeometrico::~ObjetoGeometrico() {
	delete coordenadas;
	delete CPPcoordenadas;
	delete windowCoordenadas;
	delete nome;
}

