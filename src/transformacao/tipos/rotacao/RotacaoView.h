/*
 * RotacaoView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef ROTACAOVIEW_H_
#define ROTACAOVIEW_H_

#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include "../../../api/OnAdicionarTipoTransformacaoEvent.h"
#include "../../../dto/transformacao/Rotacao.h"

class RotacaoView: public QWidget {
Q_OBJECT
public:
	RotacaoView(OnAdicionarTipoTransformacaoEvent* event);
	virtual ~RotacaoView();


public slots:
	void on_pontoButton_toggled(bool checked);
	void on_adicionarButton_clicked();

private:
	QFrame *frame;
	QLabel *operacoesLabel;
	QLabel *anguloLabel;
	QLabel *grausLabel;
	QRadioButton *origemButton;
	QRadioButton *centroButton;
	QRadioButton *pontoButton;
	QLineEdit *anguloInput;
	QLineEdit *xInput;
	QLineEdit *yInput;
	QLabel *pontoLabel;
	QLabel *xLabel;
	QLabel *yLabel;
	QPushButton *adicionarButton;
	OnAdicionarTipoTransformacaoEvent* event;
};

#endif /* ROTACAOVIEW_H_ */
