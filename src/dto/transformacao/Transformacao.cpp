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
	z = 0;
}

Transformacao::Transformacao(char* nome, double x, double y, double z){
	this->nome = nome;
	this->x = x;
	this->y = y;
	this->z = z;
}

void Transformacao::setX(double x){
	this->x = x;
}

void Transformacao::setY(double y){
	this->y = y;
}

void Transformacao::setZ(double z){
	this->z = z;
}

double Transformacao::getX(){
	return x;
}

double Transformacao::getY(){
	return y;
}

double Transformacao::getZ(){
	return z;
}

char* Transformacao::getNome(){
	return nome;
}

Transformacao::~Transformacao() {

}

