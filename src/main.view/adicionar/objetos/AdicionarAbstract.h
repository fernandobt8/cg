/*
 * AdicionarAbstract.h
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARABSTRACT_H_
#define ADICIONARABSTRACT_H_

#include "../../../api/OnAdicionarObjetoTipoEvent.h"
#include "QtGui/qpushbutton.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include <stdio.h>

class AdicionarAbstract: public QWidget {
Q_OBJECT
public:
	AdicionarAbstract(QWidget *parent, OnAdicionarObjetoTipoEvent *event, Coordenada *orientation);
	virtual ~AdicionarAbstract();

protected:
	QLabel *nomeLabel;
	QLineEdit *nomeInput;
	QLabel *coordenadasLabel;
	QLabel *xLabel;
	QLabel *yLabel;
	QLineEdit *xInput;
	QLineEdit *yInput;
	QPushButton *okButton;
	QPushButton *cancelarButton;
	Coordenada* orientation;
	OnAdicionarObjetoTipoEvent *addEvent;
	QWidget *parent;
	virtual void okEvent() = 0;

public slots:
	void on_okButton_clicked();
	void on_cancelarButton_clicked();
};

#endif /* ADICIONARABSTRACT_H_ */
