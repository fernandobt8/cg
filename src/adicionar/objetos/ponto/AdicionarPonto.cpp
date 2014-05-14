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

void AdicionarPonto::on_okButton_clicked() {
	Coordenada* coordenada = new Coordenada();
	coordenada->setX(atoi(this->xInput->text().toUtf8().constData()) );
	coordenada->setY(atoi(this->yInput->text().toUtf8().constData()) );
	coordenada->setZ(atoi(this->zInput->text().toUtf8().constData()) );
	Ponto* ponto = new Ponto(Utils::cloneChar(this->nomeInput->text().toUtf8().data()));
	ponto->addCoordenada(coordenada);
	addEvent->OnAdicionarObjetoTipoClick(ponto);
}

AdicionarPonto::~AdicionarPonto() {
}
