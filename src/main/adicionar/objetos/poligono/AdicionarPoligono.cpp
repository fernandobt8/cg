/*
 * AdicionarPoligono.cpp
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#include "AdicionarPoligono.h"

AdicionarPoligono::AdicionarPoligono(QWidget *parent,
		OnAdicionarObjetoTipoEvent *event ) :
		AdicionarAbstract(parent, event) {
	adicionarCoordenadaButton = new QPushButton(this);
	adicionarCoordenadaButton->setObjectName(
			QString::fromUtf8("adicionarCoordenada"));
	adicionarCoordenadaButton->setGeometry(QRect(25, 125, 200, 30));
	adicionarCoordenadaButton->setText(
			QString::fromUtf8("Adicionar nova coordenada"));
	coordenadasList = new QListWidget(this);
	coordenadasList->setObjectName(QString::fromUtf8("coordenadasList"));
	coordenadasList->setGeometry(QRect(50, 175, 150, 60));
	removerCoordenadaButton = new QPushButton(this);
	removerCoordenadaButton->setObjectName(QString::fromUtf8("removerCoordenada"));
	removerCoordenadaButton->setGeometry(QRect(25, 255, 200, 30));
	removerCoordenadaButton->setText(QString::fromUtf8("Remover coordenada"));

	QMetaObject::connectSlotsByName(this);

}

AdicionarPoligono::~AdicionarPoligono() {
}

void AdicionarPoligono::okEvent() {
	Poligono *p = new Poligono(this->nomeInput->text().toUtf8().data(), coordenadasPoligono);
	memset(&coordenadasPoligono, 0, sizeof(coordenadasPoligono));
	addEvent->OnAdicionarObjetoTipoClick(p);
	this->parent->close();
}

void AdicionarPoligono::on_removerCoordenada_clicked() {

}

void AdicionarPoligono::on_adicionarCoordenada_clicked() {
	Coordenada* coordenada = new Coordenada();
	coordenada->setX(atoi(this->xInput->text().toUtf8().data()));
	coordenada->setY(atoi(this->yInput->text().toUtf8().data()));
	this->coordenadasPoligono->push_back(coordenada);

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

