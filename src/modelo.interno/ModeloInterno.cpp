/*
 * ModeloInterno.cpp
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#include "ModeloInterno.h"

ModeloInterno::ModeloInterno(Window* window) {
	objetos = new list<ObjetoGeometrico*>();
	this->window = window;
}

list<ObjetoGeometrico*>* ModeloInterno::getObjetos(){
	return this->objetos;
}

void ModeloInterno::transformeObjeto(char* nome, list<Transformacao* >* transformacoes){
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for(;it != objetos->end(); it++){
		ObjetoGeometrico* objeto = *it;
		if(strcmp(objeto->getNome(), nome) == 0){
			Matriz* matriz = Matriz::getMatrizTransformacao(objeto->getCenter(), transformacoes);
			list<Coordenada*>::iterator itCoor = objeto->getCoordenadas()->begin();
			for(;itCoor != objeto->getCoordenadas()->end(); itCoor++){
				Coordenada* coor = *itCoor;
				coor->vezesMatriz(matriz);
			}
		}
	}
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
