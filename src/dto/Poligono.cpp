/*
 * Poligono.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "Poligono.h"

Poligono::Poligono(char* nome, list<Coordenada*> *coordenadas) : ObjetoGeometrico(nome, coordenadas){
}

Poligono::~Poligono() {
}

Poligono* Poligono::clone(){
	::list<Coordenada* >* list = new ::list<Coordenada* >();
	::list<Coordenada* >::iterator it = coordenadas->begin();
	for( ; it != coordenadas->end() ; it++){
		Coordenada* current = *it;
		list->push_back(current->clone());
	}
	char* temp = new char[strlen(nome)];
	strcpy(temp, nome);
	return new Poligono(temp, list);
}


