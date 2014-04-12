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
	end = new Coordenada(480, 480);
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
				Coordenada* pontoVP = calculeCoordenadaVP(ponto->getWindowCoordenadas()->front(), window->CPPstart, window->CPPend);
				painter->drawEllipse(pontoVP->getX(),pontoVP->getY(),2,2);
			}
			ObjetoGeometrico* objeto = *it;
			if(objeto){
				list<Coordenada*>::iterator it = objeto->getWindowCoordenadas()->begin();
				for (; it._M_node != objeto->getWindowCoordenadas()->end()._M_node->_M_prev; it++) {
					Coordenada* current = *it;
					Coordenada* next = static_cast<_List_node<Coordenada*>*>( it._M_node->_M_next)->_M_data;
					Coordenada* pontoVP1 = calculeCoordenadaVP( current, window->CPPstart, window->CPPend);
					Coordenada* pontoVP2 = calculeCoordenadaVP( next, window->CPPstart, window->CPPend);
					painter->drawLine( pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
				}
				Coordenada* pontoVP1 = calculeCoordenadaVP( objeto->getWindowCoordenadas()->front(), window->CPPstart, window->CPPend);
				Coordenada* pontoVP2 = calculeCoordenadaVP( objeto->getWindowCoordenadas()->back(), window->CPPstart, window->CPPend);
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

