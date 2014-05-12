/*
 * WindowView.cpp
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#include "Window.h"

Window::Window(){
	start = new Coordenada(0, 0, 0);
	vectorUp = new Coordenada(0, 0, 1);
	end = new Coordenada(0, 500, 500);
	CPPstart = new Coordenada(0, -250, -250);
	CPPend = new Coordenada(0, 250, 250);
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
	Matriz* matriz = new MatrizRotacao(this->getAngulo());
	coor->multiplyByMatriz(matriz);
	start->addCoordenada(coor);
	end->addCoordenada(coor);
	delete coor;
	delete matriz;
}

void Window::zoom(double zoomX, double zoomY){
	Coordenada* center = this->getCenter();
	double angulo = this->getAngulo();

	MatrizTranslacao transOrigem(-center->getX(), -center->getY());
	MatrizRotacao rotacaoParalela(-angulo);
	MatrizEscalonamento esca(zoomX, zoomY);
	MatrizRotacao rotacaoNormal(angulo);
	MatrizTranslacao transCenter(center->getX(), center->getY());
	transOrigem.multiply(&rotacaoParalela);
	transOrigem.multiply(&esca);
	transOrigem.multiply(&rotacaoNormal);
	transOrigem.multiply(&transCenter);
	this->mutiplyCoordenadas(&transOrigem);
	delete center;
}

void Window::rotacione(double angulo){
	Matriz* matrizRotacaoVector = new MatrizRotacao(angulo);
	vectorUp->multiplyByMatriz(matrizRotacaoVector);

	Coordenada* center = this->getCenter();
	Rotacao* rotacao = new Rotacao(angulo, Rotacao::CENTRO);
	Matriz* matrizRotacao = MatrizUtils::getFullMatrizRotacao(center, rotacao);
	this->mutiplyCoordenadas(matrizRotacao);
	delete center;
	delete rotacao;
	delete matrizRotacao;
	delete matrizRotacaoVector;
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

double Window::getAngulo(){
	//grau = arccos(v1 * v2) / (||v1|| * ||v2||)
	double dividendo = (0 * vectorUp->getX()) + (1 * vectorUp->getY());
	double divisor =  sqrt(pow(0, 2)+pow(1, 2)) * sqrt(pow(vectorUp->getX(), 2) + pow(vectorUp->getY(), 2));
	double angulo = 180 * ( acos(dividendo / divisor) / PI );
	if(vectorUp->getX() > 0){
		return angulo;
	}else{
		return -angulo;
	}
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

