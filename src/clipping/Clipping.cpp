/*
 * ClippingPonto.cpp
 *
 *  Created on: 20/04/2014
 *      Author: alisson
 */

#include "Clipping.h"
#include <iostream>

Clipping::Clipping(Window *window, list<ObjetoGeometrico*> *objetos) {
	this->window = window;
	this->objetos = objetos;
	this->novaLista = new list<ObjetoGeometrico*>();
}

Clipping::~Clipping() {
}

void Clipping::clip() {
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		Ponto* ponto = dynamic_cast<Ponto*>(*it);
		if (ponto) {
			clippingPonto(ponto);
		}
		Reta* reta = dynamic_cast<Reta*>(*it);
		if (reta) {
			clippingReta(reta);
		}
	}
	window->setWindowObjetos(novaLista);
}

void Clipping::clippingPonto(Ponto* ponto) {
	list<Coordenada*> *coordenadas = ponto->getWindowCoordenadas();
	double x = coordenadas->front()->getX();
	double y = coordenadas->front()->getY();
	bool xStart = window->CPPstart->getX() <= x;
	bool xEnd = window->CPPend->getX() >= x;
	bool yStart = window->CPPstart->getY() <= y;
	bool yEnd = window->CPPend->getY() >= y;
	if (xStart && xEnd && yStart && yEnd) {
		novaLista->push_back(ponto);
	}
}

void Clipping::clippingReta(Reta *reta) {
	bool RC1[3] = { false };
	bool RC2[3] = { false };
	Coordenada *coordenada1 = reta->getWindowCoordenadas()->front();
	Coordenada *coordenada2 = reta->getWindowCoordenadas()->back();
	verificarQuadrante(coordenada1, RC1);
	verificarQuadrante(coordenada2, RC2);
	if (!(RC1[0] || RC1[1] || RC1[2] || RC1[3])
			&& !(RC2[0] || RC2[1] || RC2[2] || RC2[3])) {
		novaLista->push_back(reta);
	} else {
		if (!((RC1[0] && RC2[0]) || (RC1[1] && RC2[1]) || (RC1[2] && RC2[2])
				|| (RC1[3] && RC2[3]))) {
			reta->printAllCPPcoordenadas();
			Reta* novaReta = new Reta(reta->getNome());
			list<Coordenada*>* CPPcoordenadas = new list<Coordenada*>();
			CPPcoordenadas->push_back(retaParcial(RC1, coordenada1, coordenada2, coordenada1->clone()));			;
			CPPcoordenadas->push_back(retaParcial(RC2, coordenada1, coordenada2, coordenada2->clone()));
			novaReta->setCPPCoordenadas(CPPcoordenadas);
			novaReta->printAllCPPcoordenadas();
			novaLista->push_back(novaReta);
		}
	}
}

void Clipping::verificarQuadrante(Coordenada* coordenada, bool* RC) {
	if (coordenada->getY() > window->CPPend->getY())
		RC[0] = true;
	if (coordenada->getY() < window->CPPstart->getY()) {
		RC[1] = true;
	}
	if (coordenada->getX() > window->CPPend->getX()) {
		RC[2] = true;
	}
	if (coordenada->getX() < window->CPPstart->getX()) {
		RC[3] = true;
	}
}

Coordenada* Clipping::retaParcial(bool* RC, Coordenada *coordenadaInicial,
		Coordenada* coordenadaFinal, Coordenada *novaCoordenada) {
	double m = (coordenadaFinal->getY() - coordenadaInicial->getY())
			/ (coordenadaFinal->getX() - coordenadaInicial->getX());
	if (RC[0]) {
		novaCoordenada->setY(window->CPPend->getY());
		novaCoordenada->setX(coordenadaInicial->getX() + 1/m * (window->CPPend->getY() - coordenadaInicial->getY()));
	}
	if (RC[1]) {
		novaCoordenada->setY(window->CPPstart->getY());
		novaCoordenada->setX(coordenadaInicial->getX() + 1/m * (window->CPPstart->getY() - coordenadaInicial->getY()));
	}
	if (RC[2]) {
		novaCoordenada->setX(window->CPPend->getX());
		novaCoordenada->setY(m* (window->CPPend->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY());
	}
	if (RC[3]) {
		novaCoordenada->setX(window->CPPstart->getX());
		novaCoordenada->setY(m* (window->CPPstart->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY());
	}
	return novaCoordenada;
}
