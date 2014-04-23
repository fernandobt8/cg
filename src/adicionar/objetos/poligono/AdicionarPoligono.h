/*
 * AdicionarPoligono.h
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARPOLIGONO_H_
#define ADICIONARPOLIGONO_H_

#include "../AdicionarAbstract.h"
#include <list>
#include "QtCore/qlist.h"
#include "QtGui/qlistwidget.h"
#include "QtGui/qcolordialog.h"
#include <QtGui/qcheckbox.h>
#include <QtGui/qpalette.h>
#include "../../../dto/geometrico/Poligono.h"
#include "../../../utils/Utils.h"


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
private:
	QListWidget *coordenadasList;
	QPushButton *adicionarCoordenadaButton;
	QPushButton *removerCoordenadaButton;
	QCheckBox* checkAberto;
	QPushButton *selectColorButton;
	QWidget* panelSelectedColor;
	QColor color;
	list<Coordenada*>* coordenadasPoligono;

public slots:
	void on_removerCoordenada_clicked();
	void on_adicionarCoordenada_clicked();
};

#endif /* ADICIONARPOLIGONO_H_ */
