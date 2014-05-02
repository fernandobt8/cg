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
	Curva* curva = dynamic_cast<Curva*>(objeto);
	if (ponto) {
		clippingPonto(ponto->clone());
	} else if (reta) {
		clippingReta(reta->clone());
	} else if (poligono) {
		if (poligono->aberto) {
			this->clippingObjetoGeometricoToRetas(poligono);
		} else {
			this->clippingPoligonoFechado(poligono);
		}
	} else if(curva){
		this->clippingObjetoGeometricoToRetas(curva);
	}
}

void Clipping::clippingPonto(Ponto* ponto) {
	if (CoordenadaUtils::isDentroWindow(ponto->getCPPCoordenadas()->front(), window)) {
		window->addWindowObjeto(ponto);
	}
}

void Clipping::clippingReta(Reta *reta) {
	if (clippingLine(reta->getCPPCoordenadas()->front(), reta->getCPPCoordenadas()->back())) {
		window->addWindowObjeto(reta);
	}
}

void Clipping::clippingObjetoGeometricoToRetas(ObjetoGeometrico* objeto) {
	list<Coordenada*>::iterator it = objeto->getCPPCoordenadas()->begin();
	for (; it._M_node != objeto->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
		Coordenada* current = (*it)->clone();
		Coordenada* next =  ListUtils::getDataForwardIterator(it, 1)->clone();
		if (clippingLine(current, next)) {
			Reta* r = new Reta(Utils::cloneChar(objeto->getNome()));
			r->getCPPCoordenadas()->push_back(current);
			r->getCPPCoordenadas()->push_back(next);
			window->addWindowObjeto(r);
		}else{
			delete current;
			delete next;
		}
	}
}

void Clipping::clippingPoligonoFechado(Poligono* poligono) {
	list<Coordenada*> *poligonoVertices = getPoligonoLista(poligono);
	if(poligonoVertices->size() > poligono->getCPPCoordenadas()->size()){
		list<Coordenada*> *windowVertices = getWindowLista(poligonoVertices);
		list<Coordenada*> *novosVertices = new list<Coordenada*>();
		list<Coordenada*>::iterator it = poligonoVertices->begin();
		Coordenada* first = NULL;
		while (true) {
			Coordenada *atual = (*it);
			if(atual == first)
				return;
			it = ListUtils::incrementIteratorCircular(poligonoVertices, it);
			if (!atual->isVisitado() && atual->isInterseccao() && CoordenadaUtils::isDentroWindow(*it, window)) {
				if(!first)
					first = atual;
				atual->setVisitado(true);
				novosVertices->push_back(atual);
				percorrerLista(poligonoVertices, windowVertices, novosVertices, ListUtils::getIteratorInObject(poligonoVertices, atual));

				Poligono *poligonoNovo = poligono->clone();
				poligonoNovo->setCPPCoordenadas(novosVertices);
				window->addWindowObjeto(poligonoNovo);
				novosVertices = new list<Coordenada* >();
			}
		}
		delete novosVertices;
		ListUtils::destroyListByCondition(windowVertices, CoordenadaUtils::notVisitado);
	}else
		window->addWindowObjeto(poligono->clone());
	ListUtils::destroyListByCondition(poligonoVertices, CoordenadaUtils::notVisitado);
}

void Clipping::percorrerLista(list<Coordenada* >* followList, list<Coordenada*>* goList, list<Coordenada*>* novaLista, _List_iterator<Coordenada*> it){
	while(true){
		it = ListUtils::incrementIteratorCircular(followList, it);
		if(!(*it)->isVisitado()){
			(*it)->setVisitado(true);
			novaLista->push_back(*it);
			if((*it)->isInterseccao()){
				percorrerLista(goList, followList, novaLista, ListUtils::getIteratorInObject(goList, *it));
				return;
			}
		}else
			return;
	}
}

list<Coordenada*>* Clipping::getPoligonoLista(Poligono* poligono){
	list<Coordenada*>* poligonoVertices = new list<Coordenada*>();
	list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
	poligono->getCPPCoordenadas()->push_back(poligono->getCPPCoordenadas()->front());
	poligonoVertices->push_back((*it)->clone());
	for (; it._M_node != poligono->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
		Coordenada* currentClone = (*it)->clone();
		Coordenada* next = ListUtils::getDataForwardIterator(it, 1)->clone();
		Coordenada* nextClone = next->clone();
		if (clippingLine(currentClone, nextClone)) {
			if (!(*it)->equal(currentClone)) {
				currentClone->setInterseccao(true);
				poligonoVertices->push_back(currentClone);
			}else
				delete currentClone;
			if (!next->equal(nextClone)) {
				nextClone->setInterseccao(true);
				poligonoVertices->push_back(nextClone);
			}else
				delete nextClone;
		}
		poligonoVertices->push_back(next);
	}
	poligono->getCPPCoordenadas()->pop_back();
	poligonoVertices->pop_back();
	return poligonoVertices;
}

list<Coordenada*>* Clipping::getWindowLista(list<Coordenada*>* poligonoVertices) {
	list<Coordenada*>* windowVertices = new list<Coordenada*>();
	Coordenada *A = this->window->CPPstart->clone();
	Coordenada *C = this->window->CPPend->clone();
	Coordenada *B = new Coordenada(A->getX(), C->getY());
	Coordenada *D = new Coordenada(C->getX(), A->getY());
	windowVertices->push_back(A);
	windowVertices->push_back(B);
	windowVertices->push_back(C);
	windowVertices->push_back(D);
	this->addListToList(poligonoVertices, windowVertices, A, CoordenadaUtils::compareEqualXAndIsInterseccao, CoordenadaUtils::compareMenorY);
	this->addListToList(poligonoVertices, windowVertices, B, CoordenadaUtils::compareEqualYAndIsInterseccao, CoordenadaUtils::compareMenorX);
	this->addListToList(poligonoVertices, windowVertices, C, CoordenadaUtils::compareEqualXAndIsInterseccao, CoordenadaUtils::compareMaiorY);
	this->addListToList(poligonoVertices, windowVertices, D, CoordenadaUtils::compareEqualYAndIsInterseccao, CoordenadaUtils::compareMaiorX);
	return windowVertices;
}

template<typename Equals, typename Sort>
void Clipping::addListToList(list<Coordenada* >* origem, list<Coordenada*>* destino, Coordenada* coordenada, Equals equals, Sort sort){
	list<Coordenada* > *inter = ListUtils::montListByConditionAndOrder(origem, coordenada, equals, sort);
	ListUtils::splice(destino, inter, coordenada);
	delete inter;
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
