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
}

void Window::update(){
	list<ObjetoGeometrico* >::iterator it = modelo->getObjetos()->begin();
	for (; it != modelo->getObjetos()->end(); it++) {
		ObjetoGeometrico* objeto = dynamic_cast<ObjetoGeometrico* >(*it);
		if(objeto != 0 && objeto->isAfterCoordenada(start)){

		}
	}
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

}

