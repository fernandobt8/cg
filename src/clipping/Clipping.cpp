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
	if (CoordenadaUtils::isDentroWindow(ponto->getCPPCoordenadas()->front(), window)) {
		window->addWindowObjeto(ponto);
	}
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
	list<Coordenada*> *poligonoVertices = new list<Coordenada* >();
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
			if (!atual->isVisitado() && atual->isInterseccao() && (CoordenadaUtils::isDentroWindow(next, window) || next->isInterseccao())) {
				if(first == NULL){
					first = atual;
				}
				atual->setVisitado(true);
				novosVertices->push_back(atual);
				percorrerLista(poligonoVertices, windowVertices, novosVertices, ListUtils::getIteratorInObject(poligonoVertices, atual));

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

void Clipping::percorrerLista(list<Coordenada* >* followList, list<Coordenada*>* goList, list<Coordenada*>* novaLista, _List_iterator<Coordenada*> it){
	while(true){
		it++;
		if(it == followList->end())
			it = followList->begin();
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
