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
		bool keepGooing = true;
		Coordenada* first = NULL;
		while (keepGooing) {
			Coordenada *atual = (*it);
			keepGooing = atual != first;
			it++;
			if(it == poligonoVertices->end()){
				it = poligonoVertices->begin();
			}
			Coordenada *next = *it;
			if (!atual->isVisitado() && atual->isInterseccao() && (verificarPonto(next->getX(), next->getY()) || (next->isInterseccao()))) {
				if(first == NULL){
					first = atual;
				}
				atual->setVisitado(true);
				novosVertices->push_back(atual);
				int index = ListUtils::getIndexObject(poligonoVertices, atual);
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, index);

				Poligono *poligonoNovo = new Poligono(Utils::cloneChar(poligono->getNome()));
				poligonoNovo->setCPPCoordenadas(novosVertices);
				poligonoNovo->color = new QColor(*poligono->color);
				window->addWindowObjeto(poligonoNovo);
				novosVertices = new list<Coordenada* >();
			}
		}
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
				int index = ListUtils::getIndexObject(windowVertices, next);
				percorrerListaWindow(poligonoVertices, windowVertices, novosVertices, index);
				return;
			}
			it++;
			if(it == poligonoVertices->end()){
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, -1);
				return;
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
				int index = ListUtils::getIndexObject(poligonoVertices, next);
				percorrerListaPoligono(poligonoVertices, windowVertices, novosVertices, index);
				return;
			}
			it++;
			if(it == windowVertices->end()){
				percorrerListaWindow(poligonoVertices, windowVertices, novosVertices, -1);
				return;
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
	list<Coordenada* > *inter = ListUtils::montListByConditionAndOrder(poligonoVertices, A,
			CoordenadaUtils::compareEqualXAndIsInterseccao, CoordenadaUtils::compareMenorY);
	ListUtils::splice(windowVertices, inter, A);
	delete inter;

	list<Coordenada* > *inter2 = ListUtils::montListByConditionAndOrder(poligonoVertices, B,
			CoordenadaUtils::compareEqualYAndIsInterseccao, CoordenadaUtils::compareMenorX);
	ListUtils::splice(windowVertices, inter2, B);
	delete inter2;

	list<Coordenada* > *inter3 = ListUtils::montListByConditionAndOrder(poligonoVertices, C,
			CoordenadaUtils::compareEqualXAndIsInterseccao, CoordenadaUtils::compareMaiorY);
	ListUtils::splice(windowVertices, inter3, C);
	delete inter3;

	list<Coordenada* > *inter4 = ListUtils::montListByConditionAndOrder(poligonoVertices, D,
			CoordenadaUtils::compareEqualYAndIsInterseccao, CoordenadaUtils::compareMaiorX);
	ListUtils::splice(windowVertices, inter4, D);
	delete inter4;
	return windowVertices;
}

bool Clipping::clippingLine(Coordenada* coordenada1, Coordenada* coordenada2) {
	vector<bool> RC1 = CoordenadaUtils::verificarQuadranteCoordenada(coordenada1, window);
	vector<bool> RC2 = CoordenadaUtils::verificarQuadranteCoordenada(coordenada2, window);;
	if (!(RC1[Quadrante::acima] || RC1[Quadrante::abaixo] || RC1[Quadrante::direita] || RC1[Quadrante::esquerda])
			&& !(RC2[Quadrante::acima] || RC2[Quadrante::abaixo] || RC2[Quadrante::direita] || RC2[Quadrante::esquerda])) {
		return true;
	} else if (!((RC1[Quadrante::acima] && RC2[Quadrante::acima]) || (RC1[Quadrante::abaixo] && RC2[Quadrante::abaixo])
			|| (RC1[Quadrante::direita] && RC2[Quadrante::direita]) || (RC1[Quadrante::esquerda] && RC2[Quadrante::esquerda]))) {
		return CoordenadaUtils::clippingCoordenada(RC1, coordenada1, coordenada2, coordenada1, window)
				| CoordenadaUtils::clippingCoordenada(RC2, coordenada1, coordenada2, coordenada2, window);
	}
	return false;
}
