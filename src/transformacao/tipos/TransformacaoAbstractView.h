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
	Q_OBJECT
public:
	TransformacaoAbstractView();
	virtual ~TransformacaoAbstractView();

public slots:
	virtual void on_adicionarButton_clicked() = 0;

protected:
	QFrame *frame;
	QLabel *labelMovimentacao;
	QLineEdit *xInput;
	QLineEdit *yInput;
	QPushButton *adicionarButton;

};

#endif /* TRANSFORMACAOABSTRACTVIEW_H_ */
