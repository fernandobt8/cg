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
	CPPstart = start->clone();
	CPPend = end->clone();
	angulo = 0;
	objetos = NULL;
}

list<ObjetoGeometrico*>* Window::getWindowObjetos(){
	return objetos;
}

void Window::setWindowObjetos(list<ObjetoGeometrico*>* objetos){
	this->objetos = objetos;
}

void Window::mutipliqueCPPcoordenadas(Matriz* matriz){
	delete CPPstart;
	delete CPPend;
	CPPstart = start->clone();
	CPPend = end->clone();
	CPPstart->vezesMatriz(matriz);
	CPPend->vezesMatriz(matriz);
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

Coordenada* Window::getCenter(){
	double x = (start->getX() + end->getX()) / 2;
	double y = (start->getY() + end->getY()) / 2;
	return new Coordenada(x, y);
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

