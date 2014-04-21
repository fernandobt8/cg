/*
 * ClippingPonto.cpp
 *
 *  Created on: 20/04/2014
 *      Author: alisson
 */

#include "Clipping.h"
#include <iostream>

Clipping::Clipping(Window *window) {
	this->window = window;
}

Clipping::~Clipping() {
}

void Clipping::clip(ObjetoGeometrico* objeto) {
	Ponto* ponto = dynamic_cast<Ponto*>(objeto);
	if (ponto) {
		clippingPonto(ponto);
	}
	Reta* reta = dynamic_cast<Reta*>(objeto);
	if (reta) {
		clippingReta(reta);
	}
}

void Clipping::clippingPonto(Ponto* ponto) {
	list<Coordenada*> *coordenadas = ponto->getCPPCoordenadas();
	double x = coordenadas->front()->getX();
	double y = coordenadas->front()->getY();
	bool xStart = window->CPPstart->getX() <= x;
	bool xEnd = window->CPPend->getX() >= x;
	bool yStart = window->CPPstart->getY() <= y;
	bool yEnd = window->CPPend->getY() >= y;
	if (xStart && xEnd && yStart && yEnd) {
		window->getWindowObjetos()->push_back(ponto);
	}
}

void Clipping::clippingReta(Reta *reta) {
	bool RC1[4] = { false };
	bool RC2[4] = { false };
	Coordenada *coordenada1 = reta->getCPPCoordenadas()->front();
	Coordenada *coordenada2 = reta->getCPPCoordenadas()->back();
	verificarQuadrante(coordenada1, RC1);
	verificarQuadrante(coordenada2, RC2);
	if (!(RC1[0] || RC1[1] || RC1[2] || RC1[3]) && !(RC2[0] || RC2[1] || RC2[2] || RC2[3])) {
		window->getWindowObjetos()->push_back(reta);
	} else {
		if (!((RC1[0] && RC2[0]) || (RC1[1] && RC2[1]) || (RC1[2] && RC2[2]) || (RC1[3] && RC2[3]))) {
			list<Coordenada*>* CPPcoordenadas = new list<Coordenada*>();
			CPPcoordenadas->push_back(retaParcial(RC1, coordenada1, coordenada2, coordenada1->clone()));
			CPPcoordenadas->push_back(retaParcial(RC2, coordenada1, coordenada2, coordenada2->clone()));
			reta->setCPPCoordenadas(CPPcoordenadas);
			window->getWindowObjetos()->push_back(reta);
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

Coordenada* Clipping::retaParcial(bool* RC, Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *novaCoordenada) {
	double m = (coordenadaFinal->getY() - coordenadaInicial->getY()) / (coordenadaFinal->getX() - coordenadaInicial->getX());
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
