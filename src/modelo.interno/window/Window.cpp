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

void Window::mutiplyCoordenadas(Matriz* matriz){
	start->multiplyByMatriz(matriz);
	end->multiplyByMatriz(matriz);
}

void Window::mutiplyCoordenadasToCPP(Matriz* matriz){
	delete CPPstart;
	delete CPPend;
	CPPstart = start->clone();
	CPPend = end->clone();
	CPPstart->multiplyByMatriz(matriz);
	CPPend->multiplyByMatriz(matriz);
}

void Window::move(double x, double y){
	Coordenada* coor = new Coordenada(x, y);
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
	Rotacao* paralelo = new Rotacao(-angulo, ORIGEM);
	Escalonamento* escalonamento = new Escalonamento(zoomX, zoomY);

	Matriz* transOrigem = Matriz::getMatrizTranslacao(-center->getX(), -center->getY());
	Matriz* rotacaoParalela = Matriz::getMatrizRotacao(NULL, paralelo);
	Matriz* esca = Matriz::getMatrizEscalonamento(escalonamento);
	paralelo->angulo = angulo;
	Matriz* rotacaoNormal = Matriz::getMatrizRotacao(NULL, paralelo);
	Matriz* transCenter = Matriz::getMatrizTranslacao(center->getX(), center->getY());
	transOrigem->multiply(rotacaoParalela);
	transOrigem->multiply(esca);
	transOrigem->multiply(rotacaoNormal);
	transOrigem->multiply(transCenter);
	this->mutiplyCoordenadas(transOrigem);
}

void Window::rotacione(double angulo){
	this->angulo+= angulo;
	Coordenada* center = this->getCenter();
	Rotacao* rotacao = new Rotacao(angulo, CENTRO);
	Matriz* matrizRotacao = Matriz::getMatrizRotacao(center, rotacao);
	this->mutiplyCoordenadas(matrizRotacao);
	delete center;
	delete rotacao;
	delete matrizRotacao;
}

Coordenada* Window::getCenter(){
	double x = (start->getX() + end->getX()) / 2;
	double y = (start->getY() + end->getY()) / 2;
	return new Coordenada(x, y);
}

Coordenada* Window::getCenterCPP(){
	double x = (CPPstart->getX() + CPPend->getX()) / 2;
	double y = (CPPstart->getY() + CPPend->getY()) / 2;
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

