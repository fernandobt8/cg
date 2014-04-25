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
	list<Coordenada*> *poligonoVertices = new list<Coordenada* >();;
	if(preencherPoligonoLista(poligono, poligonoVertices)){
		list<Coordenada*> *windowVertices = preencherWindowLista(poligono, poligonoVertices);
		list<Coordenada*> *novosVertices = new list<Coordenada*>();
		list<Coordenada*>::iterator it = poligonoVertices->begin();
		for (; it != poligonoVertices->end(); it++) {
			Coordenada *atual = (*it);
			if (atual->isInterseccao()) {
				it++;
				Coordenada *next;
				if(it != poligonoVertices->end())
					next = *it;
				else
					next = poligonoVertices->front();
				if (verificarPonto(next->getX(), next->getY()) || next->isInterseccao()) {
					atual->setVisitado(true);
					novosVertices->push_back(atual);
					int index = Utils::getIndexObject(poligonoVertices, atual);
					percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, index);
				}
				it--;
			}
		}
		Poligono *poligonoNovo = new Poligono(Utils::cloneChar(poligono->getNome()));
		poligonoNovo->setCPPCoordenadas(novosVertices);
		poligonoNovo->color = new QColor(*poligono->color);
		window->addWindowObjeto(poligonoNovo);
	}else {
		Poligono *poligonoNovo = new Poligono(Utils::cloneChar(poligono->getNome()));
		poligonoNovo->setCPPCoordenadas(poligonoVertices);
		poligonoNovo->color = new QColor(*poligono->color);
		window->addWindowObjeto(poligonoNovo);
	}
}

void Clipping::percorrerListaPoligono(list<Coordenada*> *poligonoVertices, list<Coordenada*> *windowVertices, list<Coordenada*> *novosVertices, int index) {
	list<Coordenada*>::iterator it = poligonoVertices->begin();
	if(index > 0){
		advance(it, index);
		it++;
	}
	if(it != poligonoVertices->end()){
		Coordenada* next = *it;
		while (!next->isVisitado()) {
			next->setVisitado(true);
			novosVertices->push_back(next);
			if (next->isInterseccao()) {
				int index = Utils::getIndexObject(windowVertices, next);
				percorrerListaWindow(poligonoVertices, windowVertices, novosVertices, index);
				return;
			}
			it++;
			if(it == poligonoVertices->end()){
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, -1);
				break;
			}
			next =*it;
		}
		return;
	}
	percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, -1);
}

void Clipping::percorrerListaWindow(list<Coordenada*> *poligonoVertices, list<Coordenada*> *windowVertices, list<Coordenada*> *novosVertices, int index) {
	list<Coordenada*>::iterator it = windowVertices->begin();
	if(index > 0){
		advance(it, index);
		it++;
	}
	if(it != windowVertices->end()){
		Coordenada* next = *it;
		while (!next->isVisitado()) {
			next->setVisitado(true);
			novosVertices->push_back(next);
			if (next->isInterseccao()) {
				int index = Utils::getIndexObject(poligonoVertices, next);
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, index);
				return;
			}
			it++;
			if(it == windowVertices->end()){
				percorrerListaWindow(poligonoVertices, windowVertices, novosVertices, -1);
				break;
			}
			next = *it;
		}
		return;
	}
	percorrerListaWindow(poligonoVertices, windowVertices, novosVertices, -1);
}

bool Clipping::preencherPoligonoLista(Poligono* poligono, list<Coordenada*>* poligonoVertices) {
	poligono->getCPPCoordenadas()->push_back(poligono->getCPPCoordenadas()->front());
	list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
	bool needClipping = false;
	Coordenada* current = (*it)->clone();
	poligonoVertices->push_back(current);
	for (; it._M_node != poligono->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
		current = (*it)->clone();
		Coordenada* next = static_cast<_List_node<Coordenada*>*>(it._M_node->_M_next)->_M_data->clone();
		Coordenada* nextClone = next->clone();
		Coordenada* currentClone = current->clone();
		if (clippingLine(currentClone, nextClone)) {
			if (!current->equal(currentClone)) {
				needClipping = true;
				currentClone->setInterseccao(true);
				poligonoVertices->push_back(currentClone);
			}
			if (!next->equal(nextClone)) {
				needClipping = true;
				nextClone->setInterseccao(true);
				poligonoVertices->push_back(nextClone);
			}
		}
		poligonoVertices->push_back(next);
	}
	poligono->getCPPCoordenadas()->pop_back();
	poligonoVertices->pop_back();
	return needClipping;
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
	list<Coordenada* > *inter = new list<Coordenada* >();
	Utils::montListByConditionAndOrder(poligonoVertices, inter, A,  Utils::compareEqualX, Utils::compareMenorY);
	Utils::splice(windowVertices, inter, A);
	delete inter;

	list<Coordenada* > *inter2 = new list<Coordenada* >();
	Utils::montListByConditionAndOrder(poligonoVertices, inter2, B, Utils::compareEqualY, Utils::compareMenorX);
	Utils::splice(windowVertices, inter2, B);
	delete inter2;

	list<Coordenada* > *inter3 = new list<Coordenada* >();
	Utils::montListByConditionAndOrder(poligonoVertices, inter3, C, Utils::compareEqualX, Utils::compareMaiorX);
	Utils::splice(windowVertices, inter3, C);
	delete inter3;

	list<Coordenada* > *inter4 = new list<Coordenada* >();
	Utils::montListByConditionAndOrder(poligonoVertices, inter4, D, Utils::compareEqualY, Utils::compareMaiorY);
	Utils::splice(windowVertices, inter4, D);
	delete inter4;

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
