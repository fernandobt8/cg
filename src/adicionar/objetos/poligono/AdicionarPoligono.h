/*
 * AdicionarPoligono.h
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARPOLIGONO_H_
#define ADICIONARPOLIGONO_H_

#include "../AdicionarAbstract.h"
#include "QtGui/qlistwidget.h"
#include "QtGui/qcolordialog.h"
#include <QtGui/qcheckbox.h>
#include <QtGui/qpalette.h>
#include "../../../dto/geometrico/Poligono.h"

using namespace std;

class AdicionarPoligono : public AdicionarAbstract{
Q_OBJECT
public:
	AdicionarPoligono(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarPoligono();
	virtual void on_okButton_clicked();

public slots:
	void on_selectColorButton_clicked();
	void on_checkAberto_toggled(bool checked);
protected:
	QListWidget *coordenadasList;
	QPushButton *adicionarCoordenadaButton;
	QPushButton *removerCoordenadaButton;
	QCheckBox* checkAberto;
	QPushButton *selectColorButton;
	QWidget* panelSelectedColor;
	QLabel* sentidoHorario;
	QColor color;
	list<Coordenada*>* coordenadasObjeto;

public slots:
	void on_removerCoordenada_clicked();
	virtual void on_adicionarCoordenada_clicked();
};

#endif /* ADICIONARPOLIGONO_H_ */
