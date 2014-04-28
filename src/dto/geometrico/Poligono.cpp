/*
 * Poligono.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "Poligono.h"

Poligono::Poligono(const char* nome, list<Coordenada*> *coordenadas) : ObjetoGeometrico(nome, coordenadas){
	aberto = false;
	color = NULL;
}

Poligono::Poligono(const char* nome) : ObjetoGeometrico(nome){
	aberto = false;
	color = NULL;
}

Poligono* Poligono::clone(){
	Poligono *poligonoNovo = new Poligono(Utils::cloneChar(nome));
	poligonoNovo->color = this->color ? new QColor(*this->color) : NULL;
	list<Coordenada* >* newList = new list<Coordenada*>();
	for(list<Coordenada*>::iterator it = CPPcoordenadas->begin(); it != CPPcoordenadas->end(); it++){
		newList->push_back((*it)->clone());
	}
	poligonoNovo->setCPPCoordenadas(newList);
	return poligonoNovo;
}

Poligono::~Poligono() {
	delete color;
}


