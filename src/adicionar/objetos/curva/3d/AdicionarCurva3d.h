/*
 * AdicionarCurva3d.h
 *
 *  Created on: 29/05/2014
 *      Author: alisson
 */

#ifndef ADICIONARCURVA3D_H_
#define ADICIONARCURVA3D_H_

#include "../../curva/AdicionarCurva.h"
#include "QtGui/qlabel.h"
#include "QtGui/qradiobutton.h"
#include "../../../../dto/geometrico/Curva3D.h"
#include "QtGui/qmessagebox.h"

class AdicionarCurva3d : public AdicionarCurva{
public:
	AdicionarCurva3d(QWidget *parent,	OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarCurva3d();
	void on_okButton_clicked();
	void on_adicionarCoordenada_clicked();

};

#endif /* ADICIONARCURVA3D_H_ */
