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
	Matriz* transCPP = Matriz::getMatrizTranslacao(window->CPPstart->getX(), window->CPPstart->getY());
	objeto->multiplyCoordenadasToCPP(transCPP);
	Matriz* matrizWorldCoordinates = this->getMatrizToWorldCoordinates();
	objeto->multiplyCPPtoCoordenadas(matrizWorldCoordinates);
	objetos->push_back(objeto);
	delete matrizWorldCoordinates;
	delete transCPP;
}

void ModeloInterno::transformeObjeto(char* nome, list<Transformacao* >* transformacoes){
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for(;it != objetos->end(); it++){
		ObjetoGeometrico* objeto = *it;
		if(strcmp(objeto->getNome(), nome) == 0){
			Coordenada* center = objeto->getCenterInCPP();
			Matriz* matriz = Matriz::getMatrizTransformacao(center, transformacoes);
			objeto->multiplyCPPcoordenadas(matriz);
			Matriz* matrizWorldCoordinates = this->getMatrizToWorldCoordinates();
			objeto->multiplyCPPtoCoordenadas(matrizWorldCoordinates);
			delete matrizWorldCoordinates;
			delete matriz;
			delete center;
		}
	}
	delete transformacoes;
}

void ModeloInterno::rotacioneWindow(double angulo){
	window->angulo+= angulo;
	Coordenada* center = window->getCenter();
	Rotacao* rotacao = new Rotacao(angulo, CENTRO);
	Matriz* matrizRotacao = Matriz::getMatrizRotacao(center, rotacao);
	window->mutiplyCoordenadas(matrizRotacao);
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

	if(window->angulo / 360 != 0){
		Rotacao* rotacao = new Rotacao(-window->angulo, ORIGEM);
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

Matriz* ModeloInterno::getMatrizToWorldCoordinates(){
	Coordenada* windowCenter = window->getCenter();
	Matriz* transWindowCenter = Matriz::getMatrizTranslacao(windowCenter->getX(), windowCenter->getY());
	if(window->angulo / 360 != 0){
		Rotacao* rotacao = new Rotacao(window->angulo, ORIGEM);
		Matriz* matrizRotacao = Matriz::getMatrizRotacao(NULL, rotacao);
		matrizRotacao->multiply(transWindowCenter);
		delete rotacao;
		delete windowCenter;
		delete transWindowCenter;
		return matrizRotacao;
	}else{
		delete windowCenter;
		return transWindowCenter;
	}
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
