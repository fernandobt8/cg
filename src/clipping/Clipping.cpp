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
	Reta* reta = dynamic_cast<Reta*>(objeto);
	Poligono* poligono = dynamic_cast<Poligono*>(objeto);
	if (ponto) {
		clippingPonto(ponto->clone());
	} else if (reta) {
		clippingReta(reta->clone());
	} else if(poligono){
		if(poligono->aberto){
			this->clippingPoligonoAberto(poligono);
		}else{
			//completar
		}
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
		window->addWindowObjeto(ponto);
	}
}

void Clipping::clippingReta(Reta *reta) {
	if(clippingLine(reta->getCPPCoordenadas()->front(), reta->getCPPCoordenadas()->back())){
		window->addWindowObjeto(reta);
	}
}

void Clipping::clippingPoligonoAberto(Poligono* poligono){
	list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
	for (; it._M_node != poligono->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
		Coordenada* current = static_cast<Coordenada*>(*it)->clone();
		Coordenada* next = static_cast<_List_node<Coordenada*>*>( it._M_node->_M_next)->_M_data->clone();
		if(clippingLine(current, next)){
			Reta* r = new Reta(Utils::cloneChar(poligono->getNome()));
			r->getCPPCoordenadas()->push_back(current);
			r->getCPPCoordenadas()->push_back(next);
			window->addWindowObjeto(r);
		}
	}
}

bool Clipping::clippingLine(Coordenada* coordenada1, Coordenada* coordenada2){
	bool RC1[4] = { false };
	bool RC2[4] = { false };
	verificarQuadrante(coordenada1, RC1);
	verificarQuadrante(coordenada2, RC2);
	if (!(RC1[acima] || RC1[abaixo] || RC1[direita] || RC1[esquerda]) && !(RC2[acima] || RC2[abaixo] || RC2[direita] || RC2[esquerda])) {
		return true;
	} else if (!((RC1[acima] && RC2[acima]) || (RC1[abaixo] && RC2[abaixo]) || (RC1[direita] && RC2[direita]) || (RC1[esquerda] && RC2[esquerda]))){
		return clippingCoordenada(RC1, coordenada1, coordenada2, coordenada1) |
				clippingCoordenada(RC2, coordenada1, coordenada2, coordenada2);
	}
	return false;
}

bool Clipping::clippingCoordenada(bool* RC, Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *clippingCoordenada) {
	double m = (coordenadaFinal->getY() - coordenadaInicial->getY()) / (coordenadaFinal->getX() - coordenadaInicial->getX());
	bool clipping = false;
	if (RC[acima]) {
		double xCima = coordenadaInicial->getX() + 1/m * (window->CPPend->getY() - coordenadaInicial->getY());
		if(xCima >= window->CPPstart->getX() && xCima <= window->CPPend->getX()){
			clippingCoordenada->setX(xCima);
			clippingCoordenada->setY(window->CPPend->getY());
			clipping = true;
		}
	}
	if (RC[abaixo]) {
		double xBaixo = coordenadaInicial->getX() + 1/m * (window->CPPstart->getY() - coordenadaInicial->getY());
		if(xBaixo >= window->CPPstart->getX() && xBaixo <= window->CPPend->getX()){
			clippingCoordenada->setY(window->CPPstart->getY());
			clippingCoordenada->setX(xBaixo);
			clipping = true;
		}
	}
	if (RC[direita]) {
		double yDireita = m* (window->CPPend->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY();
		if(yDireita >= window->CPPstart->getY() && yDireita <= window->CPPend->getY()){
			clippingCoordenada->setX(window->CPPend->getX());
			clippingCoordenada->setY(yDireita);
			clipping = true;
		}
	}
	if (RC[esquerda]) {
		double yEsquerda = m* (window->CPPstart->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY();
		if(yEsquerda >= window->CPPstart->getY() && yEsquerda <= window->CPPend->getY()){
			clippingCoordenada->setX(window->CPPstart->getX());
			clippingCoordenada->setY(yEsquerda);
			clipping = true;
		}
	}
	return clipping;
}

void Clipping::verificarQuadrante(Coordenada* coordenada, bool* RC) {
	if (coordenada->getY() > window->CPPend->getY())
		RC[acima] = true;
	if (coordenada->getY() < window->CPPstart->getY()) {
		RC[abaixo] = true;
	}
	if (coordenada->getX() > window->CPPend->getX()) {
		RC[direita] = true;
	}
	if (coordenada->getX() < window->CPPstart->getX()) {
		RC[esquerda] = true;
	}
}
