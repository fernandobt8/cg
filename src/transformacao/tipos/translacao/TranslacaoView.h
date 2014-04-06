/*
 * TranslacaoView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef TRANSLACAOVIEW_H_
#define TRANSLACAOVIEW_H_

#include "../TransformacaoAbstractView.h"
#include "../../../api/OnAdicionarTipoTransformacaoEvent.h"

class TranslacaoView : public TransformacaoAbstractView{
public:
	TranslacaoView(OnAdicionarTipoTransformacaoEvent* event);
	virtual ~TranslacaoView();
	virtual void on_adicionarButton_clicked();

private:
	OnAdicionarTipoTransformacaoEvent* event;
};

#endif /* TRANSLACAOVIEW_H_ */
