/*
 * Coordenada.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Coordenada.h"

Coordenada::Coordenada(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->interseccao = false;
	this->visitado = false;
}

Coordenada::Coordenada() {
	x = 0;
	y = 0;
	z = 0;
	this->interseccao = false;
	this->visitado = false;
}

Coordenada::~Coordenada() {
}

void Coordenada::multiplyByMatriz(Matriz* matriz){
	Matriz coordenada(this);
	coordenada.multiply(matriz);
	x = coordenada.getMatriz()[0][0];
	y = coordenada.getMatriz()[0][1];
	z = coordenada.getMatriz()[0][2];
}

void Coordenada::addCoordenada(Coordenada* coordenada){
	this->x += coordenada->getX();
	this->y += coordenada->getY();
	this->z += coordenada->getZ();
}

void Coordenada::setX(double x) {
	this->x = x;
}

void Coordenada::setY(double y) {
	this->y = y;
}

void Coordenada::setZ(double z) {
	this->z = z;
}

double Coordenada::getZ(){
	return z;
}

double Coordenada::getX() {
	return this->x;
}

double Coordenada::getY() {
	return this->y;
}

bool Coordenada::isVisitado() {
	return visitado;
}

void Coordenada::setVisitado(bool isVisitado) {
	this->visitado = isVisitado;
}

Coordenada* Coordenada::clone(){
	return new Coordenada(x, y, z);
}

bool Coordenada::equal(Coordenada* coordenada) {
	if(this->x == coordenada->x && this->y == coordenada->y && this->z == coordenada->z)
		return true;
	return false;
}

bool Coordenada::isInterseccao() {
	return this->interseccao;
}

void Coordenada::setInterseccao(bool isInterseccao) {
	this->interseccao = isInterseccao;
}

void Coordenada::print(){
	printf("%f, %f, %f\n", x, y, z);

}
