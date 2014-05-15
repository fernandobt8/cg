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
	CPPcoordenadas = new list<Coordenada*>();
}

ObjetoGeometrico::ObjetoGeometrico(const char* nome) {
	this->nome = nome;
	this->coordenadas = new list<Coordenada* >();
	CPPcoordenadas = new list<Coordenada*>();
}

void ObjetoGeometrico::multiplyCoordenadas(Matriz* matriz){
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		static_cast<Coordenada*>(*it)->multiplyByMatriz(matriz);
	}
}

void ObjetoGeometrico::setCPPCoordenadas(list<Coordenada*>* CPPcoordenadas){
	ListUtils::destroyList(this->CPPcoordenadas);
	this->CPPcoordenadas = CPPcoordenadas;
}

void ObjetoGeometrico::multiplyCoordenadasToCPP(Matriz* matriz) {
	ListUtils::destroyList(CPPcoordenadas);
	CPPcoordenadas = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadas->begin();
	for (; it != coordenadas->end(); it++) {
		Coordenada* CPPcoor = static_cast<Coordenada*>(*it)->clone();
		CPPcoor->multiplyByMatriz(matriz);
		CPPcoordenadas->push_back(CPPcoor);
	}
}

Coordenada* ObjetoGeometrico::getCenter(){
	int numberPoints = 0;
	double somaX = 0;
	double somaY = 0;
	double somaZ = 0;
	list<Coordenada* >::iterator it = coordenadas->begin();
	for(; it != coordenadas->end();it++){
		somaX += (*it)->getX();
		somaY += (*it)->getY();
		somaZ += (*it)->getZ();
		numberPoints++;
	}
	return new Coordenada(somaX/numberPoints, somaY/numberPoints, somaZ/numberPoints);
}

void ObjetoGeometrico::addCoordenada(Coordenada* coordenada) {
	coordenadas->push_back(coordenada);
}

list<Coordenada*>* ObjetoGeometrico::getCPPCoordenadas() {
	return this->CPPcoordenadas;
}

const char* ObjetoGeometrico::getNome() {
	return this->nome;
}

void ObjetoGeometrico::printAllcoordenadas(){
	list<Coordenada* >::iterator it = coordenadas->begin();
	for(; it != coordenadas->end();it++){
		(*it)->print();
	}
}

void ObjetoGeometrico::printAllCPPcoordenadas(){
	list<Coordenada* >::iterator it = CPPcoordenadas->begin();
	for(; it != CPPcoordenadas->end();it++){
		(*it)->print();
	}
}

ObjetoGeometrico::~ObjetoGeometrico() {
	ListUtils::destroyList(coordenadas);
	ListUtils::destroyList(CPPcoordenadas);
	delete nome;
}

Coordenada* ObjetoGeometrico::getPontoFinal() {
	this->coordenadas->back();
}
