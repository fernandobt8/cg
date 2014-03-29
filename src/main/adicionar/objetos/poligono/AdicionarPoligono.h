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
#include "QtGui/qlistwidget.h"
#include "../../../../dto/Poligono.h"


using namespace std;

class AdicionarPoligono : public AdicionarAbstract{
Q_OBJECT
public:
	AdicionarPoligono(QWidget *parent, OnAdicionarObjetoTipoEvent *event);
	virtual ~AdicionarPoligono();

private:
	QListWidget *coordenadasList;
	QPushButton *adicionarCoordenadaButton;
	QPushButton *removerCoordenadaButton;
	list<Coordenada*>* coordenadasPoligono;
	void okEvent();

public slots:
	void on_removerCoordenada_clicked();
	void on_adicionarCoordenada_clicked();
};

#endif /* ADICIONARPOLIGONO_H_ */
