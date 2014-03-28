/*
 * ModeloInterno.cpp
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#include "ModeloInterno.h"
#include <stdio.h>
#include <stdlib.h>

ModeloInterno::ModeloInterno() {
	objetos = new list<ObjetoGeometrico*>();
}

ModeloInterno::~ModeloInterno() {
}

list<ObjetoGeometrico*>* ModeloInterno::getObjetos(){
	return this->objetos;
}

void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	objetos->push_back(objeto);
}
