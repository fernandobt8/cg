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
	coordenadasLabelX2 = new QLabel(this);
	coordenadasLabelX2->setObjectName(QString::fromUtf8("label"));
	coordenadasLabelX2->setGeometry(QRect(30, 125, 10, 25));
	coordenadasLabelX2->setText(QString::fromUtf8("x"));
	xInput2 = new QLineEdit(this);
	xInput2->setObjectName(QString::fromUtf8("xTextFieldPonto"));
	xInput2->setGeometry(QRect(50, 125, 50, 25));
	coordenadasLabelY2 = new QLabel(this);
	coordenadasLabelY2->setObjectName(QString::fromUtf8("label_2"));
	coordenadasLabelY2->setGeometry(QRect(150, 125, 10, 25));
	coordenadasLabelY2->setText(QString::fromUtf8("y"));
	yInput2 = new QLineEdit(this);
	yInput2->setObjectName(QString::fromUtf8("yTextFieldPonto"));
	yInput2->setGeometry(QRect(170, 125, 50, 25));

	QMetaObject::connectSlotsByName(this);

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
					this->xInput2->text().toUtf8().constData()
							+ orientation->getX()));
	coordenadas[1]->setY(
			atoi(this->yInput2->text().toUtf8().constData())
					+ orientation->getY());
	addEvent->OnAdicionarObjetoTipoClick(
			new Reta(this->nomeTextField->text().toUtf8().data(), coordenadas));
	this->parent->close();
}
