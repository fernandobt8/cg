/*
 * AdicionarPonto.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "AdicionarPonto.h"

AdicionarPonto::AdicionarPonto(QWidget *parent, OnAdicionarObjetoTipoEvent *event,
		Coordenada *orientation) :
		AdicionarAbstract(parent,event, orientation) {

}

AdicionarPonto::~AdicionarPonto() {
	// TODO Auto-generated destructor stub
}

void AdicionarPonto::okEvent() {
	Coordenada** coordenadas = new Coordenada*[0];
	coordenadas[0] = new Coordenada();
	coordenadas[0]->setX(
			atoi(this->xInput->text().toUtf8().constData())
					+ orientation->getX());
	coordenadas[0]->setY(
			atoi(this->yInput->text().toUtf8().constData())
					+ orientation->getY());
	addEvent->OnAdicionarObjetoTipoClick(
			new Ponto(this->nomeTextField->text().toUtf8().data(),
					coordenadas));
	this->parent->close();
}
