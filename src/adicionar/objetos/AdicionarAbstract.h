/*
 * AdicionarAbstract.h
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARABSTRACT_H_
#define ADICIONARABSTRACT_H_

#include "../../api/OnAdicionarObjetoTipoEvent.h"
#include "QtGui/qpushbutton.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include <stdio.h>

class AdicionarAbstract: public QWidget {
Q_OBJECT
public:
	AdicionarAbstract(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarAbstract();

protected:
	QLabel *nomeLabel;
	QLineEdit *nomeInput;
	QLabel *coordenadasLabel;
	QLabel *xLabel;
	QLabel *yLabel;
	QLabel *zLabel;
	QLineEdit *xInput;
	QLineEdit *yInput;
	QLineEdit *zInput;
	QPushButton *okButton;
	QPushButton *cancelarButton;
	OnAdicionarObjetoTipoEvent *addEvent;
	QWidget *parent;

public slots:
	virtual void on_okButton_clicked() = 0;
	void on_cancelarButton_clicked();
};

#endif /* ADICIONARABSTRACT_H_ */
