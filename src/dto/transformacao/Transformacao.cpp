/*
 * Transformacao.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Transformacao.h"

Transformacao::Transformacao(char* nome) {
	this->nome = nome;
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

