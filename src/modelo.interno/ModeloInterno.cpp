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

void ModeloInterno::updateCPPCoordenadas(){
	Coordenada* WinCenter = window->getCenter();
	Matriz* transOrigem = Matriz::getMatrizTranslacao(-WinCenter->getX(), -WinCenter->getY());

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
	}
	delete WinCenter;
	delete transOrigem;
}

void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	Matriz* transCPP = Matriz::getMatrizTranslacao(window->CPPstart->getX(), window->CPPstart->getY());
	objeto->multipliqueCPPcoordenadas(transCPP);
	if(window->angulo / 360 != 0){
		Rotacao* rotacao = new Rotacao();
		rotacao->tipoRotacao = ORIGEM;
		rotacao->angulo = window->angulo;
		Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
		transCPP->multiplique(matrizRotacao);
		delete rotacao;
		delete matrizRotacao;
	}
	Coordenada* windowCenter = window->getCenter();
	Matriz* transWindowCenter = Matriz::getMatrizTranslacao(windowCenter->getX(), windowCenter->getY());
	transCPP->multiplique(transWindowCenter);
	objeto->multipliqueCoordenadas(transCPP);

	objetos->push_back(objeto);
	delete transWindowCenter;
	delete windowCenter;
	delete transCPP;
}

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
	this->updateCPPCoordenadas();
	delete transformacoes;
}

void ModeloInterno::rotacioneWindow(double angulo){
	window->angulo+= angulo;
	Coordenada* center = window->getCenter();
	Rotacao* rotacao = new Rotacao();
	rotacao->tipoRotacao = CENTRO;
	rotacao->angulo = angulo;
	Matriz* matrizRotacao = Matriz::getMatrizRotacao(center, rotacao);
	window->mutipliqueCoordenadas(matrizRotacao);
	this->updateCPPCoordenadas();
	delete center;
	delete rotacao;
	delete matrizRotacao;
}

void ModeloInterno::moveWindow(double x, double y){
	window->move(x, y);
}

void ModeloInterno::zoomWindow(double value){
	window->zoom(value);
}

void ModeloInterno::setTamanhoWindow(double width, double height){
	window->setTamanhoWindow(width, height);
	this->updateCPPCoordenadas();
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
