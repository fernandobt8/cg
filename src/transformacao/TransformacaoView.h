/*
 * TransformacaoView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef TRANSFORMACAOVIEW_H_
#define TRANSFORMACAOVIEW_H_

#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "tipos/rotacao/RotacaoView.h"
#include "tipos/escalonamento/EscalonamentoView.h"
#include "tipos/translacao/TranslacaoView.h"
#include "../api/OnOkTransformcaoEvent.h"
#include "../dto/transformacao/Transformacao.h"
#include "../utils/Utils.h"
#include <list>

using namespace std;

class TransformacaoView : public QWidget, virtual public OnAdicionarTipoTransformacaoEvent{
	Q_OBJECT
public:
	TransformacaoView(OnOkTransformcaoEvent* event);
	virtual ~TransformacaoView();
	virtual void onAdicionarTipoTransformacaoClick(Transformacao* transformacao);
	virtual void closeEvent(QCloseEvent* event);

public slots:
	void on_okButton_clicked();
	void on_cancelarButton_clicked();

private:
	QTabWidget *transformacaoWidget;
	QListWidget *listWidget;
	QLabel *label;
	QPushButton *okButton;
	QPushButton *cancelarButton;
	OnOkTransformcaoEvent* event;
	list<Transformacao* >* transformacoes;

};
#endif /* TRANSFORMACAOVIEW_H_ */
