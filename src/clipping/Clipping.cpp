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
	} else if (poligono) {
		if (poligono->aberto) {
			this->clippingPoligonoAberto(poligono);
		} else {
			this->clippingPoligonoFechado(poligono);
		}
	}
}

void Clipping::clippingPonto(Ponto* ponto) {
	list<Coordenada*> *coordenadas = ponto->getCPPCoordenadas();
	double x = coordenadas->front()->getX();
	double y = coordenadas->front()->getY();
	if (verificarPonto(x, y)) {
		window->addWindowObjeto(ponto);
	}
}

bool Clipping::verificarPonto(double x, double y) {
	bool xStart = window->CPPstart->getX() <= x;
	bool xEnd = window->CPPend->getX() >= x;
	bool yStart = window->CPPstart->getY() <= y;
	bool yEnd = window->CPPend->getY() >= y;
	if (xStart && xEnd && yStart && yEnd) {
		return true;
	}
	return false;
}

void Clipping::clippingReta(Reta *reta) {
	if (clippingLine(reta->getCPPCoordenadas()->front(), reta->getCPPCoordenadas()->back())) {
		window->addWindowObjeto(reta);
	}
}

void Clipping::clippingPoligonoAberto(Poligono* poligono) {
	list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
	for (; it._M_node != poligono->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
		Coordenada* current = (*it)->clone();
		Coordenada* next = static_cast<_List_node<Coordenada*>*>(it._M_node->_M_next)->_M_data->clone();
		if (clippingLine(current, next)) {
			Reta* r = new Reta(Utils::cloneChar(poligono->getNome()));
			r->getCPPCoordenadas()->push_back(current);
			r->getCPPCoordenadas()->push_back(next);
			window->addWindowObjeto(r);
		}
	}
}

void Clipping::clippingPoligonoFechado(Poligono* poligono) {
	list<Coordenada*> *poligonoVertices = preencherPoligonoLista(poligono);
	list<Coordenada*> *windowVertices = preencherWindowLista(poligono, poligonoVertices);
	list<Coordenada*> *novosVertices = new list<Coordenada*>();
	list<Coordenada*>::iterator it = poligonoVertices->begin();
	for (; it != poligonoVertices->end(); it++) {
		Coordenada *atual = (*it);
		if (atual->isInterseccao()) {
			Coordenada *next = static_cast<_List_node<Coordenada*>*>(it._M_node->_M_next)->_M_data;
			if (verificarPonto(next->getX(), next->getY()) || next->isInterseccao()) {
				atual->setVisitado(true);
				novosVertices->push_back(atual);
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, atual);
			}
		}
	}
	Poligono *poligonoNovo = new Poligono(Utils::cloneChar(poligono->getNome()));
	poligono->setCPPCoordenadas(novosVertices);
	poligonoNovo->color = new QColor(*poligono->color);
	window->addWindowObjeto(poligonoNovo);
}

void Clipping::percorrerListaPoligono(list<Coordenada*> *poligonoVertices, list<Coordenada*> *windowVertices, list<Coordenada*> *novosVertices, Coordenada* anterior) {
	list<Coordenada*>::iterator it = poligonoVertices->begin();
	advance(it, Utils::getIndexObject(poligonoVertices, anterior) + 1);
	for (; it != poligonoVertices->end(); it++) {
		Coordenada *atual = (*it);
		atual->setVisitado(true);
		novosVertices->push_back(atual);
		if (!atual->isVisitado()) {
			if (atual->isInterseccao()) {
				atual->setVisitado(true);
				percorrerListaWindow(poligonoVertices, windowVertices, novosVertices, atual);
			}
		}
	}
}

void Clipping::percorrerListaWindow(list<Coordenada*> *poligonoVertices, list<Coordenada*> *windowVertices, list<Coordenada*> *novosVertices, Coordenada *anterior) {
	list<Coordenada*>::iterator it = windowVertices->begin();
	advance(it, Utils::getIndexObject(windowVertices, anterior) + 1);
	for (; it != windowVertices->end(); it++) {
		Coordenada *atual = (*it);
		atual->setVisitado(true);
		novosVertices->push_back(atual);
		if (!atual->isVisitado()) {
			if (atual->isInterseccao()) {
				atual->setVisitado(true);
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, atual);
			}
		}
	}
}

list<Coordenada*>* Clipping::preencherPoligonoLista(Poligono* poligono) {
	list<Coordenada*>* poligonoVertices = new list<Coordenada* >();
	list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
	for (; it._M_node != poligono->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
		Coordenada* current = (*it)->clone();
		Coordenada* next = static_cast<_List_node<Coordenada*>*>(it._M_node->_M_next)->_M_data->clone();
		Coordenada* nextClone = next->clone();
		Coordenada* currentClone = current->clone();
		poligonoVertices->push_back(current);
		if (clippingLine(currentClone, nextClone)) {
			if (!current->equal(currentClone)) {
				currentClone->setInterseccao(true);
				poligonoVertices->push_back(currentClone);
			}
			if (!next->equal(nextClone)) {
				nextClone->setInterseccao(true);
				poligonoVertices->push_back(nextClone);
			}
		}
		poligonoVertices->push_back(next);
	}
	return poligonoVertices;
}

list<Coordenada*>* Clipping::preencherWindowLista(Poligono* poligono, list<Coordenada*>* poligonoVertices) {
	list<Coordenada*>* windowVertices = new list<Coordenada*>();
	Coordenada *A = this->window->CPPstart->clone();
	Coordenada *C = this->window->CPPend->clone();
	Coordenada *B = new Coordenada(A->getX(), C->getY());
	Coordenada *D = new Coordenada(C->getX(), A->getY());
	windowVertices->push_back(A);
	windowVertices->push_back(B);
	windowVertices->push_back(C);
	windowVertices->push_back(D);
	list<Coordenada* > inter = list<Coordenada* >();
	Utils::monteList(poligonoVertices, inter, A, Utils::compareMenorY, Utils::compareEqualX);
	windowVertices->splice(++windowVertices->begin(), inter);

	list<Coordenada* > inter2 = list<Coordenada* >();
	Utils::monteList(poligonoVertices, inter, B, Utils::compareMenorX, Utils::compareEqualY);
	windowVertices->splice(Utils::getIteratorInObject(windowVertices, C), inter2);

	list<Coordenada* > inter3 = list<Coordenada* >();
	Utils::monteList(poligonoVertices, inter, C, Utils::compareMaiorX, Utils::compareEqualX);
	windowVertices->splice(Utils::getIteratorInObject(windowVertices, D), inter3);

	list<Coordenada* > inter4 = list<Coordenada* >();
	Utils::monteList(poligonoVertices, inter, D, Utils::compareMaiorY, Utils::compareEqualY);
	windowVertices->splice(windowVertices->end(), inter4);
	return windowVertices;
}



bool Clipping::clippingLine(Coordenada* coordenada1, Coordenada* coordenada2) {
	bool RC1[4] = { false };
	bool RC2[4] = { false };
	verificarQuadrante(coordenada1, RC1);
	verificarQuadrante(coordenada2, RC2);
	if (!(RC1[acima] || RC1[abaixo] || RC1[direita] || RC1[esquerda]) && !(RC2[acima] || RC2[abaixo] || RC2[direita] || RC2[esquerda])) {
		return true;
	} else if (!((RC1[acima] && RC2[acima]) || (RC1[abaixo] && RC2[abaixo]) || (RC1[direita] && RC2[direita]) || (RC1[esquerda] && RC2[esquerda]))) {
		return clippingCoordenada(RC1, coordenada1, coordenada2, coordenada1)
				| clippingCoordenada(RC2, coordenada1, coordenada2, coordenada2);
	}
	return false;
}

bool Clipping::clippingCoordenada(bool* RC, Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *clippingCoordenada) {
	double m = (coordenadaFinal->getY() - coordenadaInicial->getY()) / (coordenadaFinal->getX() - coordenadaInicial->getX());
	bool clipping = false;
	if (RC[acima]) {
		double xCima = coordenadaInicial->getX() + 1 / m * (window->CPPend->getY() - coordenadaInicial->getY());
		if (xCima >= window->CPPstart->getX() && xCima <= window->CPPend->getX()) {
			clippingCoordenada->setX(xCima);
			clippingCoordenada->setY(window->CPPend->getY());
			clipping = true;
		}
	}
	if (RC[abaixo]) {
		double xBaixo = coordenadaInicial->getX() + 1 / m * (window->CPPstart->getY() - coordenadaInicial->getY());
		if (xBaixo >= window->CPPstart->getX() && xBaixo <= window->CPPend->getX()) {
			clippingCoordenada->setY(window->CPPstart->getY());
			clippingCoordenada->setX(xBaixo);
			clipping = true;
		}
	}
	if (RC[direita]) {
		double yDireita = m * (window->CPPend->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY();
		if (yDireita >= window->CPPstart->getY() && yDireita <= window->CPPend->getY()) {
			clippingCoordenada->setX(window->CPPend->getX());
			clippingCoordenada->setY(yDireita);
			clipping = true;
		}
	}
	if (RC[esquerda]) {
		double yEsquerda = m * (window->CPPstart->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY();
		if (yEsquerda >= window->CPPstart->getY() && yEsquerda <= window->CPPend->getY()) {
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
