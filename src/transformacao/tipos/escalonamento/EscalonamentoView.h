/*
 * EscalonamentoView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef ESCALONAMENTOVIEW_H_
#define ESCALONAMENTOVIEW_H_

#include "../TransformacaoAbstractView.h"
#include "../../../api/OnAdicionarTipoTransformacaoEvent.h"
#include "../../../dto/transformacao/Escalonamento.h"

class EscalonamentoView : public TransformacaoAbstractView{
public:
	EscalonamentoView(OnAdicionarTipoTransformacaoEvent* event);
	virtual ~EscalonamentoView();
	virtual void on_adicionarButton_clicked();

private:
	OnAdicionarTipoTransformacaoEvent* event;
};

#endif /* ESCALONAMENTOVIEW_H_ */
