/*
 * ModeloInterno.cpp
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#include "ModeloInterno.h"

ModeloInterno::ModeloInterno() {
	objetos = new list<ObjetoGeometrico*>();
	this->window = new Window();
	clipping = new Clipping(window);
}

void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	objetos->push_back(objeto);
	this->updateCPPCoordenadas();
}

void ModeloInterno::transformeObjeto(char* nome, list<Transformacao* >* transformacoes){
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for(;it != objetos->end(); it++){
		ObjetoGeometrico* objeto = *it;
		if(strcmp(objeto->getNome(), nome) == 0){
			Coordenada* inicial = new Coordenada(objeto->getCenter()->getX(), objeto->getCenter()->getY(), objeto->getCenter()->getZ());
			Coordenada* final = new Coordenada(objeto->getPontoFinal()->getX(), objeto->getPontoFinal()->getY(), objeto->getPontoFinal()->getZ());
			Vetor *vetor = new Vetor(inicial, final);
			Matriz* matriz = MatrizUtils::getMatrizTransformacao(vetor, transformacoes);
			objeto->multiplyCoordenadas(matriz);
			delete matriz;
			delete vetor;
		}
	}
	this->updateCPPCoordenadas();
	ListUtils::destroyList(transformacoes);
}

void ModeloInterno::rotacioneWindow(double angulo, Rotacao::Round around){
	window->rotacione(angulo, around);
	this->updateCPPCoordenadas();
}

void ModeloInterno::moveWindow(double x, double y, double z){
	window->move(x, y, z);
	this->updateCPPCoordenadas();
}

void ModeloInterno::zoomWindow(double zoomX, double zoomY){
	window->zoom(zoomX, zoomY);
	this->updateCPPCoordenadas();
}

void ModeloInterno::setTamanhoWindow(double width, double height){
	double zoomX = width / window->getWidth();
	double zoomY = height / window->getHeight();
	this->zoomWindow(zoomX, zoomY);
}

void ModeloInterno::updateCPPCoordenadas(){
	window->clearWindowObjetos();
	NormalizadorWindow* normalizador = window->getNormalizador();
	Matriz* norma = normalizador->getMatrizNormalizacao();
	window->mutiplyCoordenadasToCPP(norma);
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->multiplyCoordenadasToCPP(norma);
		clipping->clip(objeto);
	}
	delete normalizador;
	delete norma;
}

void ModeloInterno::printAll(){
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for(; it!= objetos->end() ; it++){
		ObjetoGeometrico* o = *it;
		printf("%s\n", o->getNome());
	}
}

ModeloInterno::~ModeloInterno() {
	ListUtils::destroyList(objetos);
	delete window;
}

list<ObjetoGeometrico*>* ModeloInterno::getObjetos(){
	return this->objetos;
}
