/*
 * AdicionarCurva.cpp
 *
 *  Created on: 27/04/2014
 *      Author: alisson
 */

#include "AdicionarCurva.h"

AdicionarCurva::AdicionarCurva(QWidget *parent, OnAdicionarObjetoTipoEvent *event) : AdicionarAbstract(parent, event) {
	x2Label = new QLabel(this);
	x2Label->setGeometry(QRect(20, 125, 10, 25));
	x2Label->setText(QString::fromUtf8("x"));
	x2Input = new QLineEdit(this);
	x2Input->setGeometry(QRect(30, 125, 50, 25));
	y2Label = new QLabel(this);
	y2Label->setGeometry(QRect(110, 125, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Input = new QLineEdit(this);
	y2Input->setGeometry(QRect(120, 125, 50, 25));
	pontoControle = new QLabel(this);
	pontoControle->setGeometry(QRect(10, 170, 150, 10));
	pontoControle->setText(QString::fromUtf8("Ponto de controle"));
	x3Label = new QLabel(this);
	x3Label->setGeometry(20, 190, 10, 25);
	x3Label->setText(QString::fromUtf8("x"));
	x3Input = new QLineEdit(this);
	x3Input->setGeometry(30, 190, 50, 25);
	y3Label = new QLabel(this);
	y3Label->setGeometry(QRect(110, 190, 10, 25));
	y3Label->setText(QString::fromUtf8("y"));
	y3Input = new QLineEdit(this);
	y3Input->setGeometry(QRect(120, 190, 50, 25));
}

void AdicionarCurva::on_okButton_clicked() {
	Coordenada* coordenada1 = new Coordenada();
	coordenada1->setX(atoi(this->xInput->text().toUtf8().constData()));
	coordenada1->setY(atoi(this->yInput->text().toUtf8().constData()));

	Coordenada* coordenada2  = new Coordenada();
	coordenada2->setX(atoi(this->x2Input->text().toUtf8().constData()));
	coordenada2->setY(atoi(this->y2Input->text().toUtf8().constData()));

	Coordenada* coordenada3  = new Coordenada();
	coordenada3->setX(atoi(this->x3Input->text().toUtf8().constData()));
	coordenada3->setY(atoi(this->y3Input->text().toUtf8().constData()));

	Curva *curva = new Curva(Utils::cloneChar(this->nomeInput->text().toUtf8().data()));
	curva->addCoordenada(coordenada1);
	curva->addCoordenada(coordenada2);
	curva->addPontoControle(coordenada3);

	addEvent->OnAdicionarObjetoTipoClick(curva);
}

AdicionarCurva::~AdicionarCurva() {
	delete x2Label;
	delete y2Label;
	delete x2Input;
	delete y2Input;
}

