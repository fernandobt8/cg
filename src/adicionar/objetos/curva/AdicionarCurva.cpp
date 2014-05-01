/*
 * AdicionarCurva.cpp
 *
 *  Created on: 27/04/2014
 *      Author: alisson
 */

#include "AdicionarCurva.h"

AdicionarCurva::AdicionarCurva(QWidget *parent,	OnAdicionarObjetoTipoEvent *event) :
		AdicionarPoligono(parent, event) {
	this->sentidoHorario->hide();
	pontoControle = new QLabel(this);
	pontoControle->setGeometry(QRect(10, 120, 150, 10));
	pontoControle->setText(QString::fromUtf8("Ponto de controle"));
	x2Label = new QLabel(this);
	x2Label->setGeometry(20, 140, 10, 25);
	x2Label->setText(QString::fromUtf8("x"));
	x2Input = new QLineEdit(this);
	x2Input->setGeometry(30, 140, 50, 25);
	y2Label = new QLabel(this);
	y2Label->setGeometry(QRect(110, 140, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Input = new QLineEdit(this);
	y2Input->setGeometry(QRect(120, 140, 50, 25));

}

void AdicionarCurva::on_okButton_clicked() {
	list<Coordenada*>* novaLista = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadasObjeto->begin();
	while (it != coordenadasObjeto->end()) {
		novaLista->push_back(static_cast<Coordenada*>(*it)->clone());
		it++;
	}
	Curva *p = new Curva(Utils::cloneChar(this->nomeInput->text().toUtf8().data()), novaLista);
	addEvent->OnAdicionarObjetoTipoClick(p);
}

void AdicionarCurva::on_adicionarCoordenada_clicked() {
	Coordenada* coordenada = new Coordenada();
	coordenada->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
	coordenada->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
	this->coordenadasObjeto->push_back(coordenada);
	coordenada = new Coordenada();
	coordenada->setX(strtod(this->x2Input->text().toUtf8().data(), NULL));
	coordenada->setY(strtod(this->y2Input->text().toUtf8().data(), NULL));
	this->coordenadasObjeto->push_back(coordenada);

	QListWidgetItem * item = new QListWidgetItem();
	QString sX(this->xInput->text().toUtf8().data());
	QString sV(", ");
	QString sY(this->yInput->text().toUtf8().data());
	item->setText(sX + sV + sY);
	this->coordenadasList->addItem(item);
	item = new QListWidgetItem();
	QString sX2(this->x2Input->text().toUtf8().data());
	QString sV2(", ");
	QString sY2(this->y2Input->text().toUtf8().data());
	item->setText(sX2 + sV2 + sY2);
	this->coordenadasList->addItem(item);

}

AdicionarCurva::~AdicionarCurva() {

}

