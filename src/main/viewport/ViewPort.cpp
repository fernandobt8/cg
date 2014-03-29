/*
 * ViewPort.cpp
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#include "ViewPort.h"

ViewPort::ViewPort(QWidget* parent): QWidget(parent)  {
	QPalette pale(palette());
	pale.setColor(QPalette::Background, Qt::white);
	this->setAutoFillBackground(true);
	this->setPalette(pale);
	start = new Coordenada(0,0);
	end = new Coordenada(500,500);
	window = NULL;
}

void ViewPort::renderWindow(Window* window){
	this->window = window;
	this->update();
}

Coordenada* ViewPort::calculeCoordenadaVP(Coordenada* pontoObjeto, Coordenada* startWindow, Coordenada* endWindow){
	int x =((pontoObjeto->getX() - startWindow->getX()) / (endWindow->getX() - startWindow->getX())) * (end->getX() - start->getX());
	int y = ((1 - (pontoObjeto->getY() - startWindow->getY())) / (endWindow->getY()) - startWindow->getY()) * (end->getX() - start->getX());
	return new Coordenada(x, y);
}

void ViewPort::paintEvent(QPaintEvent* event){
	QPainter* painter = new QPainter(this);
	if(window){
		list<ObjetoGeometrico* >::iterator it = window->getWindowObjetos()->begin();
		for(;it != window->getWindowObjetos()->end(); it++){
			Ponto* ponto = dynamic_cast<Ponto* >(*it);
			if(ponto){
				Coordenada* pontoVP = calculeCoordenadaVP(static_cast<Coordenada*>(*ponto->getCoordenadas()->begin()),window->getStart(),window->getEnd());
				painter->drawPoint(pontoVP->getX(),pontoVP->getY());
			}
			Reta* reta = dynamic_cast<Reta* >(*it);
			if(reta){
				Coordenada* pontoVP1 = calculeCoordenadaVP(static_cast<Coordenada*>(*reta->getCoordenadas()->begin()),window->getStart(),window->getEnd());
				Coordenada* pontoVP2 = calculeCoordenadaVP(static_cast<Coordenada*>(*reta->getCoordenadas()->end()),window->getStart(),window->getEnd());
				painter->drawLine(pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
			}
			Poligono* poligono = dynamic_cast<Poligono* >(*it);
			if(poligono){
				list<Coordenada*>::iterator it = poligono->getCoordenadas()->begin();
				Coordenada* end = static_cast<Coordenada* >(*poligono->getCoordenadas()->end());
				Coordenada* start = static_cast<Coordenada* >(*poligono->getCoordenadas()->begin());
				for (; it._M_node != poligono->getCoordenadas()->end()._M_node->_M_prev; it++) {
					Coordenada* current = static_cast<Coordenada*>(*it);
					Coordenada* ponto = static_cast<_List_node<Coordenada*>*>(it._M_node->_M_next)->_M_data;
					Coordenada* pontoVP1 = calculeCoordenadaVP(current, window->getStart(), window->getEnd());
					Coordenada* pontoVP2 = calculeCoordenadaVP(ponto, window->getStart(), window->getEnd());
					painter->drawLine(pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
				}
				painter->drawLine(start->getX(), start->getY(), end->getX(), end->getY());
			}
		}
	}
	delete painter;
}

ViewPort::~ViewPort() {
}

