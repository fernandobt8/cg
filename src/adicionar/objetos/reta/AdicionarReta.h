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
#include "../../../dto/geometrico/Reta.h"
#include "../../../utils/Utils.h"

class AdicionarReta: virtual public AdicionarAbstract {
public:
	AdicionarReta(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarReta();
	virtual void on_okButton_clicked();

private:
	QLabel *x2Label;
	QLabel *y2Label;
	QLabel *z2Label;
	QLineEdit *x2Input;
	QLineEdit *y2Input;
	QLineEdit *z2Input;

};

#endif /* ADICIONARRETA_H_ */
