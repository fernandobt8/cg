/*
 * AdicionarAbstract.cpp
 *
 *  Created on: 28/03/2014
 *      Author: alisson
 */

#include "AdicionarAbstract.h"

AdicionarAbstract::AdicionarAbstract(QWidget *parent, OnAdicionarObjetoTipoEvent *event) :
		QWidget() {
	this->parent = parent;
	this->addEvent = event;
	nomeInput = new QLineEdit(this);
	nomeInput->setObjectName(QString::fromUtf8("nomeTextField"));
	nomeInput->setGeometry(QRect(60, 10, 160, 25));
	nomeLabel = new QLabel(this);
	nomeLabel->setObjectName(QString::fromUtf8("nomeLabel"));
	nomeLabel->setGeometry(QRect(10, 15, 40, 15));
	nomeLabel->setText(QString::fromUtf8("Nome"));
	coordenadasLabel = new QLabel(this);
	coordenadasLabel->setObjectName(QString::fromUtf8("coordenadasLabel"));
	coordenadasLabel->setGeometry(QRect(10, 65, 90, 10));
	coordenadasLabel->setText(QString::fromUtf8("Coordenadas"));
	xLabel = new QLabel(this);
	xLabel->setObjectName(QString::fromUtf8("label"));
	xLabel->setGeometry(QRect(30, 90, 10, 25));
	xLabel->setText(QString::fromUtf8("x"));
	xInput = new QLineEdit(this);
	xInput->setObjectName(QString::fromUtf8("xTextFieldPonto"));
	xInput->setGeometry(QRect(50, 90, 50, 25));
	yLabel = new QLabel(this);
	yLabel->setObjectName(QString::fromUtf8("label_2"));
	yLabel->setGeometry(QRect(150, 90, 10, 25));
	yLabel->setText(QString::fromUtf8("y"));
	yInput = new QLineEdit(this);
	yInput->setObjectName(QString::fromUtf8("yTextFieldPonto"));
	yInput->setGeometry(QRect(170, 90, 50, 25));
	okButton = new QPushButton(this);
	okButton->setObjectName(QString::fromUtf8("okButton"));
	okButton->setGeometry(QRect(10, 310, 80, 30));
	okButton->setText(QString::fromUtf8("Ok"));
	cancelarButton = new QPushButton(this);
	cancelarButton->setObjectName(QString::fromUtf8("cancelarButton"));
	cancelarButton->setGeometry(QRect(160, 310, 80, 30));
	cancelarButton->setText(QString::fromUtf8("Cancelar"));

	QMetaObject::connectSlotsByName(this);

}

void AdicionarAbstract::on_okButton_clicked() {
	this->okEvent();
}

void AdicionarAbstract::on_cancelarButton_clicked() {
	delete parent;
}

AdicionarAbstract::~AdicionarAbstract() {
	delete nomeLabel;
	delete nomeInput;
	delete coordenadasLabel;
	delete xLabel;
	delete yLabel;
	delete xInput;
	delete yInput;
	delete okButton;
	delete cancelarButton;
}
