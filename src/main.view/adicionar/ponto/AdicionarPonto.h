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
#include "../../../dto/Ponto.h"

class AdicionarPonto: public AdicionarAbstract {
public:
	AdicionarPonto(QWidget *parent, OnAdicionarObjetoTipoEvent *event, Coordenada *orientation);
	virtual ~AdicionarPonto();

	void okEvent();
};

#endif /* ADICIONARPONTO_H_ */
