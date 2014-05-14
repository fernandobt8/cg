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
	CPPstart = new Coordenada(-250, -250, 0);
	CPPend = new Coordenada(250, 250, 0);
	objetos = new list<ObjetoGeometrico* >();

//	Coordenada* p =new Coordenada(5 ,5,5);
//	double angulo = Utils::getAnguloPlanoXY(p);
//	double angulo2 = Utils::getAnguloPlanoZY(p);
//	Matriz* ro = new MatrizRotacao(angulo, Rotacao::AROUND_X);
//	p->multiplyByMatriz(ro);
//	p->print();
//	double angulo3 = Utils::getAnguloPlanoZY(p);
//	p->print();
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
	Coordenada* coor = new Coordenada(x, y, z);
	NormalizadorWindow* normalizador = this->getNormalizador();
	Matriz* matriz = normalizador->getMatrizAnguloWindow();
	coor->multiplyByMatriz(matriz);
	start->addCoordenada(coor);
	end->addCoordenada(coor);
	delete coor;
	delete matriz;
	delete normalizador;
}

void Window::zoom(double zoomX, double zoomY){
	MatrizEscalonamento esca(zoomX, zoomY, 1);
	NormalizadorWindow* normalizador = this->getNormalizador();
	Matriz* norma = normalizador->getMatrizNormalizacao();
	norma->multiply(&esca);
	norma->multiply(normalizador->getMatrizDesnormalizacao());
	this->mutiplyCoordenadas(norma);
}

void Window::rotacione(double angulo, Rotacao::Round around){
	Matriz* matrizRotacao = new MatrizRotacao(angulo, around);
	vectorUp->multiplyByMatriz(matrizRotacao);
	VPN->multiplyByMatriz(matrizRotacao);

	NormalizadorWindow* normalizador = this->getNormalizador();
	Matriz* norma = normalizador->getMatrizNormalizacao();
	norma->multiply(matrizRotacao);
	norma->multiply(normalizador->getMatrizDesnormalizacao());
	this->mutiplyCoordenadas(norma);
	delete normalizador;
	delete matrizRotacao;
}

Coordenada* Window::getCenter(){
	double x = (start->getX() + end->getX()) / 2;
	double y = (start->getY() + end->getY()) / 2;
	double z = (start->getZ() + end->getZ()) / 2;
	return new Coordenada(x, y, z);
}

Coordenada* Window::getCenterCPP(){
	double x = (CPPstart->getX() + CPPend->getX()) / 2;
	double y = (CPPstart->getY() + CPPend->getY()) / 2;
	double z = (CPPstart->getZ() + CPPend->getZ()) / 2;
	return new Coordenada(x, y, z);
}

NormalizadorWindow* Window::getNormalizador(){
	return new NormalizadorWindow(this->getCenter(), vectorUp->clone(), VPN->clone());
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
	ListUtils::destroyList(objetos);
}

