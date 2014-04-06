/*
 * TranslacaoView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "TranslacaoView.h"

TranslacaoView::TranslacaoView(OnAdicionarTipoTransformacaoEvent* event) : TransformacaoAbstractView(){
	this->event = event;
}

void TranslacaoView::on_adicionarButton_clicked(){
	Translacao* trans = new Translacao();
	trans->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
	trans->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
	event->onAdicionarTipoTransformacaoClick(trans);
}

TranslacaoView::~TranslacaoView() {

}

