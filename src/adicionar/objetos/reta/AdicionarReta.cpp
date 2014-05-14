/*
 * AdicionarReta.cpp
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#include "AdicionarReta.h"

AdicionarReta::AdicionarReta(QWidget *parent, OnAdicionarObjetoTipoEvent *event) :
		AdicionarAbstract(parent, event) {
	x2Label = new QLabel(this);
	x2Label->setObjectName(QString::fromUtf8("label"));
	x2Label->setGeometry(QRect(20, 125, 10, 25));
	x2Label->setText(QString::fromUtf8("x"));
	x2Input = new QLineEdit(this);
	x2Input->setObjectName(QString::fromUtf8("xTextFieldPonto"));
	x2Input->setGeometry(QRect(30, 125, 50, 25));
	y2Label = new QLabel(this);
	y2Label->setObjectName(QString::fromUtf8("label_2"));
	y2Label->setGeometry(QRect(100, 125, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Input = new QLineEdit(this);
	y2Input->setObjectName(QString::fromUtf8("yTextFieldPonto"));
	y2Input->setGeometry(QRect(110, 125, 50, 25));
	z2Label = new QLabel(this);
	z2Label->setObjectName(QString::fromUtf8("label_2"));
	z2Label->setGeometry(QRect(180, 125, 10, 25));
	z2Label->setText(QString::fromUtf8("z"));
	z2Input = new QLineEdit(this);
	z2Input->setObjectName(QString::fromUtf8("yTextFieldPonto"));
	z2Input->setGeometry(QRect(190, 125, 50, 25));
}

void AdicionarReta::on_okButton_clicked() {
	Coordenada* coordenada1 = new Coordenada();
	coordenada1->setX(atoi(this->xInput->text().toUtf8().constData()));
	coordenada1->setY(atoi(this->yInput->text().toUtf8().constData()));

	Coordenada* coordenada2  = new Coordenada();
	coordenada2->setX(atoi(this->x2Input->text().toUtf8().constData()));
	coordenada2->setY(atoi(this->y2Input->text().toUtf8().constData()));
	Reta* reta = new Reta(Utils::cloneChar(this->nomeInput->text().toUtf8().data()));
	reta->addCoordenada(coordenada1);
	reta->addCoordenada(coordenada2);
	addEvent->OnAdicionarObjetoTipoClick(reta);
}

AdicionarReta::~AdicionarReta() {
	delete x2Label;
	delete y2Label;
	delete x2Input;
	delete y2Input;
}
