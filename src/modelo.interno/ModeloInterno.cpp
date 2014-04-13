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
		Rotacao* rotacao = new Rotacao(-window->angulo, ORIGEM);
		Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
		transOrigem->multiply(matrizRotacao);
		delete rotacao;
		delete matrizRotacao;
	}
	window->mutiplyCPPcoordenadas(transOrigem);
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->multiplyCPPcoordenadas(transOrigem);
	}
	delete WinCenter;
	delete transOrigem;
}

void ModeloInterno::addObjeto(ObjetoGeometrico *objeto){
	Matriz* transCPP = Matriz::getMatrizTranslacao(window->CPPstart->getX(), window->CPPstart->getY());
	objeto->multiplyCPPcoordenadas(transCPP);
	if(window->angulo / 360 != 0){
		Rotacao* rotacao = new Rotacao(window->angulo, ORIGEM);
		Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
		transCPP->multiply(matrizRotacao);
		delete rotacao;
		delete matrizRotacao;
	}
	Coordenada* windowCenter = window->getCenter();
	Matriz* transWindowCenter = Matriz::getMatrizTranslacao(windowCenter->getX(), windowCenter->getY());
	transCPP->multiply(transWindowCenter);
	objeto->multiplyCoordenadas(transCPP);
	objetos->push_back(objeto);
	delete transWindowCenter;
	delete windowCenter;
	delete transCPP;
}

//todo transforma nas coordenadas de window
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
	window->angulo+= angulo;
	Coordenada* center = window->getCenter();
	Rotacao* rotacao = new Rotacao(angulo, CENTRO);
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

void ModeloInterno::zoomWindow(double zoomX, double zoomY){
	window->zoom(zoomX, zoomY);
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
