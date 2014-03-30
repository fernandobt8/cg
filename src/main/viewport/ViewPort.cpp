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
	double x =((pontoObjeto->getX() - startWindow->getX()) / (endWindow->getX() - startWindow->getX())) * (end->getX() - start->getX());

	double y = ((1 - ((pontoObjeto->getY() - startWindow->getY()) / (endWindow->getY() - startWindow->getY()))) * (end->getX() - start->getX()));
	return new Coordenada(x, y);
}

void ViewPort::paintEvent(QPaintEvent* event){
	QPainter* painter = new QPainter(this);
	if(window){
		list<ObjetoGeometrico* >::iterator it = window->getWindowObjetos()->begin();
		for(;it != window->getWindowObjetos()->end(); it++){
			Ponto* ponto = dynamic_cast<Ponto* >(*it);
			if(ponto){
				Coordenada* pontoVP = calculeCoordenadaVP(ponto->getCoordenadas()->front(),window->getStart(),window->getEnd());
				painter->drawEllipse(pontoVP->getX(),pontoVP->getY(),2,2);
			}
			Reta* reta = dynamic_cast<Reta* >(*it);
			if(reta){
				Coordenada* pontoVP1 = calculeCoordenadaVP(reta->getCoordenadas()->front(),window->getStart(),window->getEnd());
				Coordenada* pontoVP2 = calculeCoordenadaVP(reta->getCoordenadas()->back(),window->getStart(),window->getEnd());
				painter->drawLine(pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
			}
			Poligono* poligono = dynamic_cast<Poligono* >(*it);
			if(poligono){
				list<Coordenada*>::iterator it = poligono->getCoordenadas()->begin();
				Coordenada* end = poligono->getCoordenadas()->back();
				Coordenada* start = poligono->getCoordenadas()->front();
				for (; it._M_node != poligono->getCoordenadas()->end()._M_node->_M_prev; it++) {
					Coordenada* current = *it;
					Coordenada* ponto = static_cast<_List_node<Coordenada*>*>(it._M_node->_M_next)->_M_data;
					Coordenada* pontoVP1 = calculeCoordenadaVP(current, window->getStart(), window->getEnd());
					Coordenada* pontoVP2 = calculeCoordenadaVP(ponto, window->getStart(), window->getEnd());
					painter->drawLine(pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
				}
				Coordenada* pontoVP1 = calculeCoordenadaVP(start, window->getStart(), window->getEnd());
				Coordenada* pontoVP2 = calculeCoordenadaVP(end, window->getStart(), window->getEnd());
				painter->drawLine(pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
			}
		}
	}
	delete painter;
}

ViewPort::~ViewPort() {
	delete start;
	delete end;
}

