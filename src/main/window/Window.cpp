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
	windowObjetos = new list<ObjetoGeometrico*>();
}

void Window::update(){
	this->clearWindowObjetos();
	list<ObjetoGeometrico* >::iterator it = modelo->getObjetos()->begin();
	for (; it != modelo->getObjetos()->end(); it++) {
		ObjetoGeometrico* objeto = *it;
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
	delete windowObjetos;
	delete start;
	delete end;
}

