/*
 * EscalonamentoView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "EscalonamentoView.h"
#include <stdio.h>

EscalonamentoView::EscalonamentoView(OnAdicionarTipoTransformacaoEvent* event) : TransformacaoAbstractView(){
	this->event = event;
}

void EscalonamentoView::on_adicionarButton_clicked(){
	Escalonamento* trans = new Escalonamento();
	trans->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
	trans->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
	event->onAdicionarTipoTransformacaoClick(trans);
}

EscalonamentoView::~EscalonamentoView() {

}

