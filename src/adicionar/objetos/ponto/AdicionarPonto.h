/*
 * AdicionarPonto.h
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARPONTO_H_
#define ADICIONARPONTO_H_

#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "../AdicionarAbstract.h"
#include "../../../dto/geometrico/Ponto.h"
#include "../../../utils/Utils.h"

class AdicionarPonto: virtual public AdicionarAbstract {
public:
	AdicionarPonto(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarPonto();
	virtual void on_okButton_clicked();

};

#endif /* ADICIONARPONTO_H_ */
