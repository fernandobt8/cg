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
	start = new Coordenada(10, 10, 0);
	end = new Coordenada(470, 470, 0);
	window = NULL;
}

void ViewPort::renderWindow(Window* window){
	this->window = window;
	this->update();
}

void ViewPort::calculeCoordenadaVP(Coordenada* pontoObjeto){
	Coordenada* startWindow = window->CPPstart;
	Coordenada* endWindow = window->CPPend;
	pontoObjeto->setX((((pontoObjeto->getX() - startWindow->getX()) / (endWindow->getX() - startWindow->getX())) * (end->getX() - start->getX())) + 10);
	pontoObjeto->setY((((1 - ((pontoObjeto->getY() - startWindow->getY()) / (endWindow->getY() - startWindow->getY()))) * (end->getX() - start->getX()))) + 10);
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
	calculeCoordenadaVP(ponto->getCPPCoordenadas()->front());
	painter->drawEllipse(ponto->getCPPCoordenadas()->front()->getX(),ponto->getCPPCoordenadas()->front()->getY(),2,2);
}

void ViewPort::drawPoligono(QPainter* painter, Poligono* poligono){
	if(!poligono->aberto){
		QPolygonF polygon = QPolygonF(false);
		list<Coordenada*>::iterator it = poligono->getCPPCoordenadas()->begin();
		for (; it!= poligono->getCPPCoordenadas()->end(); it++) {
			calculeCoordenadaVP(*it);
			polygon.push_back(QPointF((*it)->getX(), (*it)->getY()));
		}
		painter->setBrush(QBrush(*poligono->color, Qt::SolidPattern));
		painter->drawPolygon(polygon, Qt::OddEvenFill);
		painter->setBrush(QBrush());
	}
}

void ViewPort::drawReta(QPainter* painter, Reta* reta){
	calculeCoordenadaVP(reta->getCPPCoordenadas()->front());
	calculeCoordenadaVP(reta->getCPPCoordenadas()->back());
	painter->drawLine(QPointF(reta->getCPPCoordenadas()->front()->getX(), reta->getCPPCoordenadas()->front()->getY()),
			QPointF(reta->getCPPCoordenadas()->back()->getX(), reta->getCPPCoordenadas()->back()->getY()));
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

