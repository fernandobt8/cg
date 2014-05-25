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
	list<Coordenada* >* l = new list<Coordenada*>();
	l->push_back(new Coordenada(50, 50 , 50));
	l->push_back(new Coordenada(51, 150 , 50));
	l->push_back(new Coordenada(52, 250 , 50));
	l->push_back(new Coordenada(53, 350 , 50));

	l->push_back(new Coordenada(150, 50 , 250));
	l->push_back(new Coordenada(151,150 , 250));
	l->push_back(new Coordenada(152,250 , 250));
	l->push_back(new Coordenada(153,350 , 250));

	l->push_back(new Coordenada(250, 50 , 250));
	l->push_back(new Coordenada(251, 150 , 250));
	l->push_back(new Coordenada(252, 250 , 250));
	l->push_back(new Coordenada(253, 350 , 250));

	l->push_back(new Coordenada(350, 50 , 50));
	l->push_back(new Coordenada(351, 150 , 50));
	l->push_back(new Coordenada(352, 250 , 50));
	l->push_back(new Coordenada(353, 350 , 50));

	l->push_back(new Coordenada(450, 50 , -150));
	l->push_back(new Coordenada(451, 150 , -150));
	l->push_back(new Coordenada(452, 250 , -150));
	l->push_back(new Coordenada(453, 350 , -150));

	l->push_back(new Coordenada(550, 50 , 50));
	l->push_back(new Coordenada(551, 150 , 50));
	l->push_back(new Coordenada(552, 250 , 50));
	l->push_back(new Coordenada(553, 350 , 50));
	Curva3D* c = new Curva3D("aaaa", l);
	objetos->push_back(c);
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
