/*
 * WindowView.cpp
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#include "Window.h"

Window::Window(){
	start = new Coordenada(0, 0);
	end = new Coordenada(500, 500);
	objetos = NULL;
}

void Window::updateObjetos(list<ObjetoGeometrico* >* objetos){
	this->objetos = objetos;
	list<ObjetoGeometrico* >::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		ObjetoGeometrico* objeto = *it;
		objeto->updateWindowCoordenadas(start);
	}
}

Coordenada* Window::getStart(){
	return start;
}

list<ObjetoGeometrico*>* Window::getWindowObjetos(){
	return objetos;
}

Coordenada* Window::getEnd(){
	return end;
}

void Window::move(double x, double y){
	start->addToX(x);
	start->addToY(y);
	end->addToX(x);
	end->addToY(y);
}

void Window::zoom(double zoom){
	start->addToX(-zoom);
	start->addToY(-zoom);
	end->addToX(zoom);
	end->addToY(zoom);
	this->move(zoom/2, zoom/2);
}

void Window::setTamanhoWindow(double width, double height){
	end->setX(start->getX() + width);
	end->setY(start->getY() + height);
}

double Window::getWidth(){
	return end->getX() - start->getX();
}

double Window::getHeight(){
	return end->getY() - start->getY();
}

Window::~Window() {
	delete start;
	delete end;
}

