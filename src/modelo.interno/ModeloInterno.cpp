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
			Coordenada* center = objeto->getCenter();
			Matriz* matriz = MatrizUtils::getMatrizTransformacao(center, transformacoes);
			objeto->multiplyCoordenadas(matriz);
			delete matriz;
			delete center;
		}
	}
	this->updateCPPCoordenadas();
	ListUtils::destroyList(transformacoes);
}

void ModeloInterno::rotacioneWindow(double angulo){
	window->rotacione(angulo);
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
	Coordenada* WinCenter = window->getCenter();
	Matriz* transOrigem = new MatrizTranslacao(-WinCenter->getX(), -WinCenter->getY(), -WinCenter->getZ());
	transOrigem->printAll();
	Matriz* matrizRotacao = window->getMatrizNormalizacao();
	transOrigem->multiply(matrizRotacao);

	window->mutiplyCoordenadasToCPP(transOrigem);
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->multiplyCoordenadasToCPP(transOrigem);
		objeto->printAllCPPcoordenadas();
		clipping->clip(objeto);
	}
	delete WinCenter;
	delete transOrigem;
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
