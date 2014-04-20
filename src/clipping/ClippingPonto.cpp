/*
 * ClippingPonto.cpp
 *
 *  Created on: 20/04/2014
 *      Author: alisson
 */

#include "ClippingPonto.h"

ClippingPonto::ClippingPonto() {

}

ClippingPonto::~ClippingPonto() {
}

void ClippingPonto::clip(Window *window, list<ObjetoGeometrico*> *objetos) {
	list<ObjetoGeometrico*> *novaLista = new list<ObjetoGeometrico*>();
	list<ObjetoGeometrico*>::iterator it = objetos->begin();
	for (; it != objetos->end(); it++) {
		Ponto* ponto = dynamic_cast<Ponto* >(*it);
		if(ponto){
			list<Coordenada*> *coordenadas = ponto->getWindowCoordenadas();
			double x = coordenadas->front()->getX();
			double y = coordenadas->front()->getY();
			bool xStart = window->CPPstart->getX() <= x;
			bool xEnd = window->CPPend->getX() >= x;
			bool yStart = window->CPPstart->getY() <= y;
			bool yEnd = window->CPPend->getY() >= y;
			if(xStart && xEnd && yStart && yEnd){
				novaLista->push_back(ponto);
			}
		}
	}
	window->setWindowObjetos(novaLista);
}

