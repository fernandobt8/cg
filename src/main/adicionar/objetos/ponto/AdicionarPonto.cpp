/*
 * AdicionarPonto.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "AdicionarPonto.h"

AdicionarPonto::AdicionarPonto(QWidget *parent, OnAdicionarObjetoTipoEvent *event) :
		AdicionarAbstract(parent,event) {

}

AdicionarPonto::~AdicionarPonto() {
	// TODO Auto-generated destructor stub
}

void AdicionarPonto::okEvent() {
	Coordenada* coordenada = new Coordenada();
	coordenada->setX(atoi(this->xInput->text().toUtf8().constData()) );
	coordenada->setY(atoi(this->yInput->text().toUtf8().constData()) );
	Ponto* ponto = new Ponto(this->nomeInput->text().toUtf8().data());
	ponto->addCoordenada(coordenada);
	addEvent->OnAdicionarObjetoTipoClick(ponto);
	this->parent->close();
}
