/*
 * WindowView.cpp
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#include "Window.h"

Window::Window(){
	start = new Coordenada(0, 0);
	vectorUp = new Coordenada(0,1);
	end = new Coordenada(500, 500);
	CPPstart = new Coordenada(-250, -250);
	CPPend = new Coordenada(250, 250);
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
	Rotacao* rota = new Rotacao(this->getAngulo(), ORIGEM);
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
	Rotacao* paralelo = new Rotacao(-this->getAngulo(), ORIGEM);
	Escalonamento* escalonamento = new Escalonamento(zoomX, zoomY);

	Matriz* transOrigem = Matriz::getMatrizTranslacao(-center->getX(), -center->getY());
	Matriz* rotacaoParalela = Matriz::getMatrizRotacao(NULL, paralelo);
	Matriz* esca = Matriz::getMatrizEscalonamento(escalonamento);
	paralelo->angulo = this->getAngulo();
	Matriz* rotacaoNormal = Matriz::getMatrizRotacao(NULL, paralelo);
	Matriz* transCenter = Matriz::getMatrizTranslacao(center->getX(), center->getY());
	transOrigem->multiply(rotacaoParalela);
	transOrigem->multiply(esca);
	transOrigem->multiply(rotacaoNormal);
	transOrigem->multiply(transCenter);
	this->mutiplyCoordenadas(transOrigem);
}

void Window::rotacione(double angulo){
	Rotacao* rotacaoVector = new Rotacao(angulo, ORIGEM);
	Matriz* matrizRotacaoVector = Matriz::getMatrizRotacao(NULL , rotacaoVector);
	vectorUp->multiplyByMatriz(matrizRotacaoVector);
	Coordenada* center = this->getCenter();
	Rotacao* rotacao = new Rotacao(angulo, CENTRO);
	Matriz* matrizRotacao = Matriz::getMatrizRotacao(center, rotacao);
	this->mutiplyCoordenadas(matrizRotacao);
	delete center;
	delete rotacao;
	delete matrizRotacao;
	delete rotacaoVector;
	delete matrizRotacaoVector;
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
}

