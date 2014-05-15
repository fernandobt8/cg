/*
 * WindowView.cpp
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#include "Window.h"

Window::Window(){
	vectorUp = new Coordenada(0, 1, 0);
	VPN = new Coordenada(0, 0, 1);
	start = new Coordenada(0, 0, 0);
	end = new Coordenada(500, 500, 0);
	windowCenter = new Coordenada(250, 250, 0);
	CPPstart = new Coordenada(-250, -250, 0);
	CPPend = new Coordenada(250, 250, 0);
	objetos = new list<ObjetoGeometrico* >();
}

list<ObjetoGeometrico*>* Window::getWindowObjetos(){
	return objetos;
}

void Window::addWindowObjeto(ObjetoGeometrico* objeto){
	this->objetos->push_back(objeto);
}

void Window::clearWindowObjetos(){
	ListUtils::destroyList(objetos);
	objetos = new list<ObjetoGeometrico* >();
}

void Window::mutiplyCoordenadas(Matriz* matriz){
	start->multiplyByMatriz(matriz);
	end->multiplyByMatriz(matriz);
	windowCenter->multiplyByMatriz(matriz);
}

void Window::mutiplyCoordenadasToCPP(Matriz* matriz){
	delete CPPstart;
	delete CPPend;
	CPPstart = start->clone();
	CPPend = end->clone();
	CPPstart->multiplyByMatriz(matriz);
	CPPend->multiplyByMatriz(matriz);
}

void Window::move(double x, double y, double z){
	Coordenada coor(x, y, z);
	NormalizadorWindow* normalizador = this->getNormalizador();
	Matriz* matriz = normalizador->getMatrizDesnormalizarAngulo();
	coor.multiplyByMatriz(matriz);
	start->addCoordenada(&coor);
	end->addCoordenada(&coor);
	windowCenter->addCoordenada(&coor);
	delete matriz;
	delete normalizador;
}

void Window::zoom(double zoomX, double zoomY){
	MatrizEscalonamento esca(zoomX, zoomY, 1);
	NormalizadorWindow* normalizador = this->getNormalizador();
	Matriz* norma = normalizador->getMatrizFullNormalizar(&esca);
	this->mutiplyCoordenadas(norma);
	delete normalizador;
	delete norma;
}

void Window::rotacione(double angulo, Rotacao::Round around){
	MatrizRotacao matrizRotacao(angulo, around);
	NormalizadorWindow* normalizador = this->getNormalizador();
	Matriz* norma = normalizador->getMatrizFullNormalizar(&matrizRotacao);
	this->mutiplyCoordenadas(norma);

	Matriz* normaAngulo = normalizador->getMatrizFullNormalizarAngulo(&matrizRotacao);
	vectorUp->multiplyByMatriz(normaAngulo);
	VPN->multiplyByMatriz(normaAngulo);
	delete normalizador;
	delete normaAngulo;
	delete norma;
}

NormalizadorWindow* Window::getNormalizador(){
	return new NormalizadorWindow(windowCenter->clone(), vectorUp->clone(), VPN->clone());
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
	delete vectorUp;
	delete VPN;
	delete windowCenter;
	ListUtils::destroyList(objetos);
}

