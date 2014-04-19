/*
 * MatrizEscalonamento.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizEscalonamento.h"

MatrizEscalonamento::MatrizEscalonamento(Coordenada* center, Escalonamento* escalonamento) : Matriz() {
	Matriz* transCenter = new MatrizTranslacao(-center->getX(), -center->getY());
	this->initialize(escalonamento->getX(), escalonamento->getY());
	transCenter->multiply(this);
	Matriz* transCenterBack = new MatrizTranslacao(center->getX(), center->getY());
	transCenter->multiply(transCenterBack);
	this->clearMatriz();
	matriz = transCenter->getMatriz();
	delete transCenter;
	delete transCenterBack;
}

MatrizEscalonamento::MatrizEscalonamento(double x, double y) : Matriz(){
	this->initialize(x, y);
}

void MatrizEscalonamento::initialize(double x, double y){
	matriz[0][0] = x;
	matriz[0][1] = 0;
	matriz[0][2] = 0;

	matriz[1][0] = 0;
	matriz[1][1] = y;
	matriz[1][2] = 0;

	matriz[2][0] = 0;
	matriz[2][1] = 0;
	matriz[2][2] = 1;
}

MatrizEscalonamento::~MatrizEscalonamento() {
}

