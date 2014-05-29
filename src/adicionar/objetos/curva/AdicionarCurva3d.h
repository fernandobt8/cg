/*
 * AdicionarCurva3d.h
 *
 *  Created on: 29/05/2014
 *      Author: alisson
 */

#ifndef ADICIONARCURVA3D_H_
#define ADICIONARCURVA3D_H_

#include "../poligono/AdicionarPoligono.h"
#include "QtGui/qlabel.h"
#include "QtGui/qradiobutton.h"
#include "../../../dto/geometrico/Curva3D.h"
#include "QtGui/qmessagebox.h"

class AdicionarCurva3d : public AdicionarPoligono{
public:
	AdicionarCurva3d(QWidget *parent,	OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarCurva3d();
	void on_okButton_clicked();
	void on_adicionarCoordenada_clicked();
	void on_checkAberto_toggled(bool checked);

private:
	QRadioButton* splineButton;
	QRadioButton* bezierButton;
};

#endif /* ADICIONARCURVA3D_H_ */
