/*
 * Transformacao.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Transformacao.h"

Transformacao::Transformacao(char* nome) {
	this->nome = nome;
	x = 0;
	y = 0;
}

Transformacao::Transformacao(char* nome, double x, double y){
	this->nome = nome;
	this->x = x;
	this->y = y;
}

void Transformacao::setX(double x){
	this->x = x;
}

void Transformacao::setY(double y){
	this->y = y;
}

double Transformacao::getX(){
	return x;
}

double Transformacao::getY(){
	return y;
}

char* Transformacao::getNome(){
	return nome;
}

Transformacao::~Transformacao() {

}

