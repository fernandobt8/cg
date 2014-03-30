/*
 * Ponto.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Ponto.h"
Ponto::Ponto(char* nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas) {
}

Ponto::Ponto(char* nome) : ObjetoGeometrico(nome) {
}

Ponto* Ponto::clone(){
	::list<Coordenada* >* list = new ::list<Coordenada* >();
	::list<Coordenada* >::iterator it = coordenadas->begin();
	for( ; it != coordenadas->end() ; it++){
		Coordenada* current = *it;
		list->push_back(current->clone());
	}
	char* temp = new char[strlen(nome)];
	strcpy(temp, nome);
	return new Ponto(temp, list);
}

Ponto::~Ponto() {
}


