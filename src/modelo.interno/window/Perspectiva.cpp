/*
 * Perspectiva.cpp
 *
 *  Created on: 20/05/2014
 *      Author: alisson
 */

#include "Perspectiva.h"

Perspectiva::Perspectiva() {
}

Perspectiva::~Perspectiva() {
}

double Perspectiva::projetar(Coordenada *cop, Window *window){
	d = cop->getZ();
	transladeOrigem(cop, window);
	alinharPlanoZ(window);
	return d;
}

void Perspectiva::transladeOrigem(Coordenada *cop, Window *window) {
	window->move(-d, -d, -d);
	Matriz* transCenter = new MatrizTranslacao(-d, -d, -d);
	cop->multiplyByMatriz(transCenter);
}

void Perspectiva::alinharPlanoZ(Window *window){
	anguloX = Utils::getAnguloBetweenVectors(new Coordenada(1,0,0), window->getCenter());
	anguloY = Utils::getAnguloBetweenVectors(new Coordenada(0,1,0), window->getCenter());
	window->rotacione(anguloX, Rotacao::AROUND_X);
	window->rotacione(anguloY, Rotacao::AROUND_Y);
}

void Perspectiva::transladeBack(Coordenada *cop, Window *window) {
	window->move(d, d, d);
	Matriz* transCenter = new MatrizTranslacao(d, d, d);
	cop->multiplyByMatriz(transCenter);
}

void Perspectiva::alinharPlanoXY(Window *window){
	window->rotacione(-anguloX, Rotacao::AROUND_X);
	window->rotacione(-anguloY, Rotacao::AROUND_Y);
}

void Perspectiva::projetarObjeto(ObjetoGeometrico *objeto){
	list<Coordenada*>::iterator it = objeto->getCPPCoordenadas()->begin();
	Coordenada* current;
	for (; it != objeto->getCPPCoordenadas()->end(); it++) {
		current = (*it);
		if(current->getZ() != 0){
			current->setX(current->getX()/(current->getZ()/d));
			current->setY(current->getY()/(current->getZ()/d));
			current->setZ(d);
		}
	}

}

void Perspectiva::normalizar(Coordenada *cop, Window *window) {
	this->alinharPlanoXY(window);
	this->transladeBack(cop, window);
}
