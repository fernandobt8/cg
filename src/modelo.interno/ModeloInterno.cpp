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
			Coordenada* center = objeto->getCenter();
			Matriz* matriz = Matriz::getMatrizTransformacao(center, transformacoes);
			objeto->multipliqueCoordenadas(matriz);
			delete matriz;
			delete center;
		}
	}
	delete transformacoes;
}
void ModeloInterno::updateCPPAndWindowCoordenadas(){
	Coordenada* WinCenter = window->getCenter();
	Translacao* trans = new Translacao();
	trans->setX(-WinCenter->getX());
	trans->setY(-WinCenter->getY());
	Matriz* transOrigem = Matriz::getMatrizTranslacao(trans);

	if(window->angulo / 360 != 0){
		Rotacao* rotacao = new Rotacao();
		rotacao->angulo = -window->angulo;
		rotacao->tipoRotacao = ORIGEM;
		Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
		transOrigem->multiplique(matrizRotacao);
		delete rotacao;
		delete matrizRotacao;
	}
	window->mutipliqueCPPcoordenadas(transOrigem);
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->multipliqueCPPcoordenadas(transOrigem);
		objeto->subWindowCoordenadas(window->CPPstart);
	}
	delete WinCenter;
	delete trans;
	delete transOrigem;
}

void ModeloInterno::updateWindowCoordenadas(){
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->subWindowCoordenadas(window->CPPstart);
	}
}

//ver orientação
void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	objeto->addToCoordenadas(window->start);
	objetos->push_back(objeto);
}

//todo update all
void ModeloInterno::rotacioneWindow(double angulo){
	window->angulo+= angulo;
	Coordenada* center = window->getCenter();
	Rotacao* rotacao = new Rotacao();
	rotacao->tipoRotacao = CENTRO;
	Matriz* matrizRotacao = Matriz::getMatrizRotacao(center, rotacao);
	window->mutipliqueCoordenadas(matrizRotacao);
	delete center;
	delete rotacao;
	delete matrizRotacao;

}

//todo update windowcoor
void ModeloInterno::moveWindow(double x, double y){
	window->move(x, y);
}

//todo update windowcoor
void ModeloInterno::zoomWindow(double value){
	window->zoom(value);
}

//todo : update wincoor
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
