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
}

//todo update all
void ModeloInterno::transformeObjeto(char* nome, list<Transformacao* >* transformacoes){
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for(;it != objetos->end(); it++){
		ObjetoGeometrico* objeto = *it;
		if(strcmp(objeto->getNome(), nome) == 0){
			Matriz* matriz = Matriz::getMatrizTransformacao(objeto->getCenter(), transformacoes);
			objeto->multipliqueAllCoordenadas(matriz);
			delete matriz;
		}
	}
	delete transformacoes;
}
void ModeloInterno::updateCPPcoordenadas(){
	Coordenada* WinCenter = window->getCenter();
	Translacao* trans = new Translacao();
	trans->setX(-WinCenter->getX());
	trans->setY(-WinCenter->getY());
	Matriz* transOrigem = Matriz::getMatrizTranslacao(trans);

	Rotacao* rotacao = new Rotacao();
	rotacao->angulo = -window->angulo;
	rotacao->tipoRotacao = ORIGEM;
	Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
	transOrigem->multiplique(matrizRotacao);

	window->mutipliqueCPPcoordenadas(transOrigem);
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->multipliqueAllCPPcoordenadas(transOrigem);
	}
}

void ModeloInterno::updateWindowCoordenadas(){
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->subAllWindowCoordenadas(window->CPPstart);
	}
}

//ver orientação
void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	objeto->addToAllCoordenadas(window->start);
	objetos->push_back(objeto);
}

//todo update windowcoor
void ModeloInterno::moveWindow(double x, double y){
	window->move(x, y);
}

//todo update windowcoor
void ModeloInterno::zoomWindow(double value){
	window->zoom(value);
}

//todo : update all
void ModeloInterno::setTamanhoWindow(double width, double height){
	window->setTamanhoWindow(width, height);
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
