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

}

TranslacaoView::~TranslacaoView() {

}

