/*
 * TransformacaoAbstractView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef TRANSFORMACAOABSTRACTVIEW_H_
#define TRANSFORMACAOABSTRACTVIEW_H_

#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

class TransformacaoAbstractView : public QWidget{
public:
	TransformacaoAbstractView();
	virtual ~TransformacaoAbstractView();
	QFrame *frame;
	QLabel *labelMovimentacao;
	QLineEdit *xInput;
	QLabel *xLabel;
	QLineEdit *yInput;
	QLabel *yLabel;
	QPushButton *adicionarButton;
};

#endif /* TRANSFORMACAOABSTRACTVIEW_H_ */
