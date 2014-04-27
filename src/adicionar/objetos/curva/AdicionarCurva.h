/*
 * AdicionarCurva.h
 *
 *  Created on: 27/04/2014
 *      Author: alisson
 */

#ifndef ADICIONARCURVA_H_
#define ADICIONARCURVA_H_

#include "../AdicionarAbstract.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "../../../utils/Utils.h"
#include "../../../dto/geometrico/Curva.h"

class AdicionarCurva : virtual public AdicionarAbstract {
public:
	AdicionarCurva(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarCurva();
	virtual void on_okButton_clicked();

private:
	QLabel *x2Label;
	QLabel *y2Label;
	QLineEdit *x2Input;
	QLineEdit *y2Input;
	QLabel *pontoControle;
	QLabel *x3Label;
	QLabel *y3Label;
	QLineEdit *x3Input;
	QLineEdit *y3Input;

};

#endif /* ADICIONARCURVA_H_ */
