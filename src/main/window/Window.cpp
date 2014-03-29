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
	end = new Coordenada(500, 500);
	center = new Coordenada(250, 250);
	windowObjetos = new list<ObjetoGeometrico*>();
}

void Window::update(){
	this->clearWindowObjetos();
	list<ObjetoGeometrico* >::iterator it = modelo->getObjetos()->begin();
	for (; it != modelo->getObjetos()->end(); it++) {
		ObjetoGeometrico* objeto = dynamic_cast<ObjetoGeometrico* >(*it);
		if(objeto != 0 && objeto->betweenCoordenadas(start,end)){
			ObjetoGeometrico* clone;
			Ponto* ponto = dynamic_cast<Ponto* >(objeto);
			if(ponto){
				clone = new Ponto(*ponto);
			}
			Reta* reta = dynamic_cast<Reta* >(objeto);
			if(reta){
				clone = new Reta(*reta);
			}
			Poligono* poligono = dynamic_cast<Poligono* >(objeto);
			if(poligono){
				clone = new Poligono(*poligono);
			}
			clone->addToAllCoordenadas(start);
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

Window::~Window() {
	this->clearWindowObjetos();
}

