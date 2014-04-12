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
	CPPstart = new Coordenada(-250, -250);
	CPPend = new Coordenada(250, 250);
	angulo = 0;
	objetos = NULL;
}

list<ObjetoGeometrico*>* Window::getWindowObjetos(){
	return objetos;
}

void Window::setWindowObjetos(list<ObjetoGeometrico*>* objetos){
	this->objetos = objetos;
}

void Window::mutipliqueCoordenadas(Matriz* matriz){
	start->vezesMatriz(matriz);
	end->vezesMatriz(matriz);
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
	Coordenada* coor = new Coordenada(x, y);
	Rotacao* rota = new Rotacao();
	rota->tipoRotacao = ORIGEM;
	rota->angulo = this->angulo;
	Matriz* matriz = Matriz::getMatrizRotacao(NULL, rota);
	coor->vezesMatriz(matriz);

	start->addToX(coor->getX());
	start->addToY(coor->getY());
	end->addToX(coor->getX());
	end->addToY(coor->getY());
	CPPstart->addToX(x);
	CPPstart->addToY(y);
	CPPend->addToX(x);
	CPPend->addToY(y);
	delete coor;
	delete rota;
	delete matriz;
}

void Window::zoom(double zoom){
	Coordenada* coor = this->getCenter();
	Escalonamento* esca = new Escalonamento();
	esca->setX(zoom);
	esca->setY(zoom);
	Matriz* matriz = Matriz::getMatrizEscalonamento(coor, esca);
	start->vezesMatriz(matriz);
	end->vezesMatriz(matriz);
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
	return CPPend->getX() - CPPstart->getX();
}

double Window::getHeight(){
	return CPPend->getY() - CPPstart->getY();
}

Window::~Window() {
	delete start;
	delete end;
}

