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
	//TODO falta inicializar o vetor
}

ModeloInterno::~ModeloInterno() {
	// TODO Auto-generated destructor stub
}

vector<ObjetoGeometrico*> ModeloInterno::getObjetos(){
	return this->objetos;
}

void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	objetos.push_back(objeto);
}
