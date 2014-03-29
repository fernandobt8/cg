/*
 * AdicionarPoligono.cpp
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#include "AdicionarPoligono.h"

AdicionarPoligono::AdicionarPoligono(QWidget *parent,
		OnAdicionarObjetoTipoEvent *event, Coordenada *orientation) :
		AdicionarAbstract(parent, event, orientation) {
	adicionarCoordenada = new QPushButton(this);
	adicionarCoordenada->setObjectName(
			QString::fromUtf8("adicionarCoordenada"));
	adicionarCoordenada->setGeometry(QRect(25, 125, 200, 30));
	adicionarCoordenada->setText(
			QString::fromUtf8("Adicionar nova coordenada"));
	coordenadasList = new QListWidget(this);
	coordenadasList->setObjectName(QString::fromUtf8("coordenadasList"));
	coordenadasList->setGeometry(QRect(50, 175, 150, 60));
	removerCoordenada = new QPushButton(this);
	removerCoordenada->setObjectName(QString::fromUtf8("removerCoordenada"));
	removerCoordenada->setGeometry(QRect(25, 255, 200, 30));
	removerCoordenada->setText(QString::fromUtf8("Remover coordenada"));

	QMetaObject::connectSlotsByName(this);

}

AdicionarPoligono::~AdicionarPoligono() {
}

void AdicionarPoligono::okEvent() {
	Poligono *p = new Poligono(this->nomeTextField->text().toUtf8().data(),
			&coordenadasPoligono);
	memset(&coordenadasPoligono, 0, sizeof(coordenadasPoligono));
	addEvent->OnAdicionarObjetoTipoClick(p);
	this->parent->close();
}

void AdicionarPoligono::on_removerCoordenada_clicked() {

}

void AdicionarPoligono::on_adicionarCoordenada_clicked() {
	Coordenada** coordenadas = new Coordenada*[0];
	coordenadas[0] = new Coordenada();
	coordenadas[0]->setX(
			atoi(this->xInput->text().toUtf8().data()) + orientation->getX());
	coordenadas[0]->setY(
			atoi(this->yInput->text().toUtf8().data()) + orientation->getY());
	this->coordenadasPoligono.push_back(coordenadas[0]);
	QListWidgetItem * item = new QListWidgetItem();
	char *text = new char[strlen(this->xInput->text().toUtf8().data())
			+ strlen(this->yInput->text().toUtf8().data())];
	memset(&text[0], 0, sizeof(text));
	strcat(text, this->xInput->text().toUtf8().data());
	strcat(text, ",");
	strcat(text, this->yInput->text().toUtf8().data());
	item->setText(text);
	this->coordenadasList->addItem(item);
}

