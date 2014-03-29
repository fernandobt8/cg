/*
 * AdicionarReta.cpp
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#include "AdicionarReta.h"

AdicionarReta::AdicionarReta(QWidget *parent, OnAdicionarObjetoTipoEvent *event,
		Coordenada *orientation) :
		AdicionarAbstract(parent, event, orientation) {
	x2Label = new QLabel(this);
	x2Label->setObjectName(QString::fromUtf8("label"));
	x2Label->setGeometry(QRect(30, 125, 10, 25));
	x2Label->setText(QString::fromUtf8("x"));
	x2Input = new QLineEdit(this);
	x2Input->setObjectName(QString::fromUtf8("xTextFieldPonto"));
	x2Input->setGeometry(QRect(50, 125, 50, 25));
	y2Label = new QLabel(this);
	y2Label->setObjectName(QString::fromUtf8("label_2"));
	y2Label->setGeometry(QRect(150, 125, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Input = new QLineEdit(this);
	y2Input->setObjectName(QString::fromUtf8("yTextFieldPonto"));
	y2Input->setGeometry(QRect(170, 125, 50, 25));
}

AdicionarReta::~AdicionarReta() {
}

void AdicionarReta::okEvent() {
	Coordenada** coordenadas = new Coordenada*[1];
	coordenadas[0] = new Coordenada();
	coordenadas[0]->setX(
			atoi(
					this->xInput->text().toUtf8().constData()
							+ orientation->getX()));
	coordenadas[0]->setY(
			atoi(this->yInput->text().toUtf8().constData())
					+ orientation->getY());

	coordenadas[1] = new Coordenada();
	coordenadas[1]->setX(
			atoi(
					this->x2Input->text().toUtf8().constData()
							+ orientation->getX()));
	coordenadas[1]->setY(
			atoi(this->y2Input->text().toUtf8().constData())
					+ orientation->getY());
	addEvent->OnAdicionarObjetoTipoClick(
			new Reta(this->nomeInput->text().toUtf8().data(), coordenadas));
	this->parent->close();
}
