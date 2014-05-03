/*
 * AdicionarCurva.h
 *
 *  Created on: 27/04/2014
 *      Author: alisson
 */

#ifndef ADICIONARCURVA_H_
#define ADICIONARCURVA_H_

#include "../poligono/AdicionarPoligono.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "QtGui/qradiobutton.h"
#include "../../../utils/Utils.h"
#include "../../../dto/geometrico/Curva.h"

class AdicionarCurva : public AdicionarPoligono {
public:
	AdicionarCurva(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarCurva();
	void on_okButton_clicked();
	void on_adicionarCoordenada_clicked();
	void on_checkAberto_toggled(bool checked);

private:
	QLabel *x2Label;
	QLabel *y2Label;
	QLabel *avisoLabel;
	QLineEdit *x2Input;
	QLineEdit *y2Input;
	QLabel *pontoControle;
	QRadioButton* blendingFuctionButton;
	QRadioButton* forwardDifferenceButton;
	bool bSpline;

};

#endif /* ADICIONARCURVA_H_ */
