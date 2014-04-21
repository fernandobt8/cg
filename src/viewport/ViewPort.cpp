/*
 * ViewPort.cpp
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#include "ViewPort.h"

ViewPort::ViewPort(QWidget* parent): QWidget(parent)  {
	this->setAutoFillBackground(true);
	this->setPalette(QPalette(QPalette::Background, Qt::white));
	start = new Coordenada(10, 10);
	end = new Coordenada(470, 470);
	window = NULL;
}

void ViewPort::renderWindow(Window* window){
	this->window = window;
	this->update();
}

Coordenada* ViewPort::calculeCoordenadaVP(Coordenada* pontoObjeto, Coordenada* startWindow, Coordenada* endWindow){
	double x =((pontoObjeto->getX() - startWindow->getX()) / (endWindow->getX() - startWindow->getX())) * (end->getX() - start->getX());

	double y = ((1 - ((pontoObjeto->getY() - startWindow->getY()) / (endWindow->getY() - startWindow->getY()))) * (end->getX() - start->getX()));
	return new Coordenada(x + 10, y + 10);
}

void ViewPort::paintEvent(QPaintEvent* event){
	QPainter* painter = new QPainter(this);
	this->drawViewPort(painter);
	if(window){
		list<ObjetoGeometrico* >::iterator it = window->getWindowObjetos()->begin();
		for(;it != window->getWindowObjetos()->end(); it++){
			Ponto* ponto = dynamic_cast<Ponto* >(*it);
			Reta* reta = dynamic_cast<Reta* >(*it);
			Poligono* poligono = dynamic_cast<Poligono* >(*it);
			if(ponto){
				this->drawPonto(painter, ponto);
			} else if(reta){
				this->drawReta(painter, reta);
			} else if(poligono){
				this->drawPoligono(painter, poligono);
			}
		}
	}
	delete painter;
}

void ViewPort::drawPonto(QPainter* painter, Ponto* ponto){
	Coordenada* pontoVP = calculeCoordenadaVP(ponto->getCPPCoordenadas()->front(), window->CPPstart, window->CPPend);
	painter->drawEllipse(pontoVP->getX(),pontoVP->getY(),2,2);
}

void ViewPort::drawPoligono(QPainter* painter, Poligono* poligono){
	if(poligono->aberto){
		list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
		for (; it._M_node != poligono->getCPPCoordenadas()->end()._M_node->_M_prev; it++) {
			Coordenada* next = static_cast<_List_node<Coordenada*>*>( it._M_node->_M_next)->_M_data;
			Coordenada* pontoVP1 = calculeCoordenadaVP(*it, window->CPPstart, window->CPPend);
			Coordenada* pontoVP2 = calculeCoordenadaVP(next, window->CPPstart, window->CPPend);
			painter->drawLine(pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
		}
	}else{
		QPolygonF polygon = QPolygonF(false);
		list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
		for (; it!= poligono->getCPPCoordenadas()->end(); it++) {
			Coordenada* pontoVP1 = calculeCoordenadaVP(*it, window->CPPstart, window->CPPend);
			polygon.push_back(QPointF(pontoVP1->getX(), pontoVP1->getY()));
		}
		painter->setBrush(QBrush(*poligono->color, Qt::SolidPattern));
		painter->drawPolygon(polygon, Qt::OddEvenFill);
		painter->setBrush(QBrush());
	}
}

void ViewPort::drawReta(QPainter* painter, Reta* reta){
	Coordenada* pontoVP1 = calculeCoordenadaVP(reta->getCPPCoordenadas()->front(), window->CPPstart, window->CPPend);
	Coordenada* pontoVP2 = calculeCoordenadaVP(reta->getCPPCoordenadas()->back(), window->CPPstart, window->CPPend);
	painter->drawLine( pontoVP1->getX(), pontoVP1->getY(), pontoVP2->getX(), pontoVP2->getY());
}

void ViewPort::drawViewPort(QPainter* painter){
	painter->setPen(QColor("red"));
	painter->drawRect(QRect(10,10,460,460));
	painter->setPen(QColor("black"));
}

ViewPort::~ViewPort() {
	delete start;
	delete end;
}

