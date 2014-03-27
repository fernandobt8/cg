/*
 * WindowView.cpp
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#include "WindowView.h"

WindowView::WindowView(QWidget* parent) :
		QWidget(parent) {
	QPalette pale(palette());
	pale.setColor(QPalette::Background, Qt::white);
	this->setAutoFillBackground(true);
	this->setPalette(pale);
	start = new Coordenada(0, 0);
	end = new Coordenada(500, 500);
	center = new Coordenada(250, 250);
	modeloInterno = new ModeloInterno();
}

void WindowView::paintEvent(QPaintEvent* event){
	QPainter *painter = painter = new QPainter(this);
	list<ObjetoGeometrico* >::iterator it = modeloInterno->getObjetos()->begin();
	for(; it != modeloInterno->getObjetos()->end(); it++ ){
		Reta* temp = dynamic_cast<Reta* >(*it);
		if(temp != 0){
			Coordenada** coordenadas = this->drawReta(temp);
			painter->drawLine(coordenadas[0]->getX(),coordenadas[0]->getY(),coordenadas[1]->getX(),coordenadas[1]->getY());
		}
	}
}

Coordenada** WindowView::drawReta(Reta* reta){
	int count = 0;
	Coordenada** coordenadas = new Coordenada*[1];
	while(count < 2){
		if(this->isBetweenWindow(coordenadas[count])){
			coordenadas[count] = new Coordenada(reta->getCoordenadas()[count]->getX(),reta->getCoordenadas()[count]->getY());
			coordenadas[count]->setX(coordenadas[count]->getX() - start->getX());
			coordenadas[count]->setY(coordenadas[count]->getY() - start->getY());
			count++;
		}else{
			break;
		}
	}
	return coordenadas;
}

bool WindowView::isBetweenWindow(Coordenada* coordenada){
	return coordenada->getX() >= start->getX() && coordenada->getX() <= end->getX() && coordenada->getY() >= start->getY() && coordenada->getY() <= end->getY();
}

void WindowView::addObjeto(ObjetoGeometrico* objeto){
	modeloInterno->addObjeto(objeto);
	this->repaint();
}

Coordenada* WindowView::getStart(){
	return start;
}

Coordenada* WindowView::getEnd(){
	return end;
}

Coordenada* WindowView::getCenter(){
	return center;
}

WindowView::~WindowView() {
	// TODO Auto-generated destructor stub
}

