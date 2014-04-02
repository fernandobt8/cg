/*
 * Coordenada.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Coordenada.h"
#include <cstdio>

Coordenada::Coordenada(double x, double y) {
	this->x = x;
	this->y = y;
}

Coordenada::Coordenada() {

}

Coordenada::~Coordenada() {
}

void Coordenada::addToX(double x){
	this->x += x;
}

void Coordenada::addToY(double y){
	this->y += y;
}

void Coordenada::setX(double x) {
	this->x = x;
}

void Coordenada::setY(double y) {
	this->y = y;
}

double Coordenada::getX() {
	return this->x;
}

double Coordenada::getY() {
	return this->y;
}

Coordenada* Coordenada::clone(){
	return new Coordenada(x, y);
}

