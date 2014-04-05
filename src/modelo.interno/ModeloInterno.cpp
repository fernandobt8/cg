/*
 * ModeloInterno.cpp
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#include "ModeloInterno.h"
#include <stdio.h>
#include <stdlib.h>

ModeloInterno::ModeloInterno(Window* window) {
	objetos = new list<ObjetoGeometrico*>();
	this->window = window;
}

list<ObjetoGeometrico*>* ModeloInterno::getObjetos(){
	return this->objetos;
}

void ModeloInterno::updateWindow(){
	window->updateObjetos(objetos);
}

void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	objetos->push_back(objeto);
	window->updateObjetos(objetos);
}

ModeloInterno::~ModeloInterno() {
	delete objetos;
}
