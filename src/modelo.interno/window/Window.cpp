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
//	Matriz* matriz = new MatrizRotacao(this->getAngulo());
//	coor->multiplyByMatriz(matriz);
	start->addCoordenada(coor);
	end->addCoordenada(coor);
	delete coor;
//	delete matriz;
}

void Window::zoom(double zoomX, double zoomY){
	Coordenada* center = this->getCenter();


	MatrizTranslacao transOrigem(-center->getX(), -center->getY(), -center->getZ());
//	MatrizRotacao rotacaoParalela(-angulo);
	MatrizEscalonamento esca(zoomX, zoomY, 1);
//	MatrizRotacao rotacaoNormal(angulo);
	MatrizTranslacao transCenter(center->getX(), center->getY(), center->getZ());
//	transOrigem.multiply(&rotacaoParalela);
	transOrigem.multiply(&esca);
//	transOrigem.multiply(&rotacaoNormal);
	transOrigem.multiply(&transCenter);
	this->mutiplyCoordenadas(&transOrigem);
	delete center;
}

void Window::rotacione(double angulo){
//	Matriz* matrizRotacaoVector = new MatrizRotacao(angulo);
//	vectorUp->multiplyByMatriz(matrizRotacaoVector);

//	Coordenada* center = this->getCenter();
//	Rotacao* rotacao = new Rotacao(angulo, Rotacao::CENTRO);
//	Matriz* matrizRotacao = MatrizUtils::getFullMatrizRotacao(center, rotacao);
//	this->mutiplyCoordenadas(matrizRotacao);
//	delete center;
//	delete rotacao;
//	delete matrizRotacao;
//	delete matrizRotacaoVector;
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

Matriz* Window::getMatrizNormalizacao(){
	Coordenada* vectorUpC = vectorUp->clone();
	Coordenada* VPNC = VPN->clone();

	double anguloXY = Utils::getAnguloPlanoXY(vectorUpC);
	Matriz* matrizXY = new MatrizRotacao(anguloXY, Rotacao::AROUND_X);
	vectorUpC->multiplyByMatriz(matrizXY);

	double anguloZY = Utils::getAnguloPlanoZY(vectorUpC);
	Matriz* matrizZY = new MatrizRotacao(anguloZY, Rotacao::AROUND_Z);

	matrizXY->multiply(matrizZY);
	VPNC->multiplyByMatriz(matrizXY);

	double anguloFrente = Utils::getAnguloPlanoYZ(VPNC);
	Matriz* matrizYZ = new MatrizRotacao(anguloFrente, Rotacao::AROUND_Y);
	matrizXY->multiply(matrizYZ);
	return matrizXY;
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

