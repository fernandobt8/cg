/*
 * Perspectiva.cpp
 *
 *  Created on: 20/05/2014
 *      Author: alisson
 */

#include "Perspectiva.h"

Perspectiva::Perspectiva(Window *window) {
	this->window = window;
	d = 10;
}

Matriz* Perspectiva::getMatrizTranslacao(){
	return new MatrizTranslacao(0, 0, d);
}

void Perspectiva::projetarObjeto(ObjetoGeometrico *objeto){
	list<Coordenada*>::iterator it = objeto->getCPPCoordenadas()->begin();
	for (; it != objeto->getCPPCoordenadas()->end(); it++) {
		if((*it)->getZ() != 10){
			(*it)->setX((*it)->getX()/((*it)->getZ()/d));
			(*it)->setY((*it)->getY()/((*it)->getZ()/d));
			(*it)->setZ(d);
		}
	}
}

Perspectiva::~Perspectiva() {
}

