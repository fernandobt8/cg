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
	window->setWindowObjetos(objetos);
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
			Matriz* matriz = Matriz::getMatrizTransformacao(center, transformacoes);
			objeto->multiplyCoordenadas(matriz);
			delete matriz;
			delete center;
		}
	}
	this->updateCPPCoordenadas();
	delete transformacoes;
}

void ModeloInterno::rotacioneWindow(double angulo){
	window->rotacione(angulo);
	this->updateCPPCoordenadas();
}

void ModeloInterno::moveWindow(double x, double y){
	window->move(x, y);
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
	Coordenada* WinCenter = window->getCenter();
	Matriz* transOrigem = Matriz::getMatrizTranslacao(-WinCenter->getX(), -WinCenter->getY());

	double angulo = window->getAngulo();
	if(angulo/ 360 != 0){
		Rotacao* rotacao = new Rotacao(-angulo, ORIGEM);
		Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
		transOrigem->multiply(matrizRotacao);
		delete rotacao;
		delete matrizRotacao;
	}
	window->mutiplyCoordenadasToCPP(transOrigem);
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->multiplyCoordenadasToCPP(transOrigem);
	}
	delete WinCenter;
	delete transOrigem;
}

void ModeloInterno::printAll(){
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for(; it!= objetos->end() ; it++){
		ObjetoGeometrico* o = *it;
		printf(o->getNome());
		printf("\n");
	}
}

ModeloInterno::~ModeloInterno() {
	delete objetos;
	delete window;
}
