/*
 * WindowView.cpp
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#include "Window.h"

Window::Window(ModeloInterno* modelo){
	this->modelo = modelo;
	start = new Coordenada(0, 0);
	end = new Coordenada(250, 500);
	center = new Coordenada(250, 250);
	windowObjetos = new list<ObjetoGeometrico*>();
}

void Window::update(){
	this->clearWindowObjetos();
	list<ObjetoGeometrico* >::iterator it = modelo->getObjetos()->begin();
	for (; it != modelo->getObjetos()->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		if(objeto->betweenCoordenadas(start,end)){
			ObjetoGeometrico* clone;
			Ponto* ponto = dynamic_cast<Ponto* >(objeto);
			if(ponto){
				clone = ponto->clone();
			}
			Reta* reta = dynamic_cast<Reta* >(objeto);
			if(reta){
				clone = reta->clone();
			}
			Poligono* poligono = dynamic_cast<Poligono* >(objeto);
			if(poligono){
				clone = poligono->clone();
			}
			clone->subToAllCoordenadas(start);
			windowObjetos->push_back(clone);
		}
	}
}

void Window::clearWindowObjetos(){
	while(!windowObjetos->empty()){
		delete windowObjetos->front();
		windowObjetos->pop_front();
	}
}

list<ObjetoGeometrico* >* Window::getWindowObjetos(){
	return windowObjetos;
}

Coordenada* Window::getStart(){
	return start;
}

Coordenada* Window::getEnd(){
	return end;
}

Coordenada* Window::getCenter(){
	return center;
}

void Window::move(double x, double y){
	start->addToX(x);
	start->addToY(y);
	end->addToX(x);
	end->addToY(y);
}

Window::~Window() {
	delete windowObjetos;
	delete start;
	delete end;
	delete center;
}

