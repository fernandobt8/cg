/*
 * AdicionarReta.h
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARRETA_H_
#define ADICIONARRETA_H_

#include "../AdicionarAbstract.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "../../../../dto/Reta.h"

class AdicionarReta: virtual public AdicionarAbstract {
public:
	AdicionarReta(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarReta();

private:
	QLabel *x2Label;
	QLabel *y2Label;
	QLineEdit *x2Input;
	QLineEdit *y2Input;
	virtual void okEvent();

};

#endif /* ADICIONARRETA_H_ */
