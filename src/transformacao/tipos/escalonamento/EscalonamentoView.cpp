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
	printf("escalonamento\n");
}

EscalonamentoView::~EscalonamentoView() {

}

