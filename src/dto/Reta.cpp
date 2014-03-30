/*
 * Reta.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Reta.h"

Reta::Reta(char *nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas) {
}
Reta::Reta(char *nome) : ObjetoGeometrico(nome) {
}
Reta::~Reta() {
}

Reta* Reta::clone(){
	::list<Coordenada* >* list = new ::list<Coordenada* >();
	::list<Coordenada* >::iterator it = coordenadas->begin();
	for( ; it != coordenadas->end() ; it++){
		Coordenada* current = *it;
		list->push_back(current->clone());
	}
	char* temp = new char[strlen(nome)];
	strcpy(temp, nome);
	return new Reta(temp, list);
}


