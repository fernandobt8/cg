/*
 * AdicionarReta.h
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARRETA_H_
#define ADICIONARRETA_H_

#include "../AdicionarAbstract.h"
#include "../../../dto/Reta.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"

class AdicionarReta: public AdicionarAbstract {
public:
	AdicionarReta(QWidget *parent, OnAdicionarObjetoTipoEvent *event,
			Coordenada *orientation);
	virtual ~AdicionarReta();
	QLabel *coordenadasLabelX2;
	QLabel *coordenadasLabelY2;
	QLineEdit *xInput2;
	QLineEdit *yInput2;
	void okEvent();

};

#endif /* ADICIONARRETA_H_ */
