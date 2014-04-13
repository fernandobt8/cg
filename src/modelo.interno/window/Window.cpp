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
	start->multiplyByMatriz(matriz);
	end->multiplyByMatriz(matriz);
}

void Window::mutiplyCPPcoordenadas(Matriz* matriz){
	delete CPPstart;
	delete CPPend;
	CPPstart = start->clone();
	CPPend = end->clone();
	CPPstart->multiplyByMatriz(matriz);
	CPPend->multiplyByMatriz(matriz);
}

void Window::move(double x, double y){
	Coordenada* coor = new Coordenada(x, y);
	CPPstart->addCoordenada(coor);
	CPPend->addCoordenada(coor);

	Rotacao* rota = new Rotacao(this->angulo, ORIGEM);
	Matriz* matriz = Matriz::getMatrizRotacao(NULL, rota);
	coor->multiplyByMatriz(matriz);
	start->addCoordenada(coor);
	end->addCoordenada(coor);
	delete coor;
	delete rota;
	delete matriz;
}

void Window::zoom(double zoomX, double zoomY){
	Coordenada* center = this->getCenter();
	Escalonamento* esca = new Escalonamento(zoomX, zoomY);
	Matriz* matriz = Matriz::getMatrizEscalonamento(center, esca);
	start->multiplyByMatriz(matriz);
	end->multiplyByMatriz(matriz);
	center= new Coordenada(0, 0);
	matriz = Matriz::getMatrizEscalonamento(center, esca);
	CPPstart->multiplyByMatriz(matriz);
	CPPend->multiplyByMatriz(matriz);
	delete center;
	delete esca;
	delete matriz;
}

void Window::setTamanhoWindow(double width, double height){
	double zoomX = width / this->getWidth();
	double zoomY = height / this->getHeight();
	this->zoom(zoomX, zoomY);
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
	delete CPPend;
	delete CPPstart;
	delete start;
	delete end;
}

