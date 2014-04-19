/*
 * AdicionarPoligono.cpp
 *
 *  Created on: 29/03/2014
 *      Author: alisson
 */

#include "AdicionarPoligono.h"

AdicionarPoligono::AdicionarPoligono(QWidget *parent,
		OnAdicionarObjetoTipoEvent *event) :
		AdicionarAbstract(parent, event) {
	coordenadasList = new QListWidget(this);
	coordenadasList->setObjectName(QString::fromUtf8("coordenadasList"));
	coordenadasList->setGeometry(QRect(190, 65, 130, 150));
	adicionarCoordenadaButton = new QPushButton(this);
	adicionarCoordenadaButton->setObjectName(QString::fromUtf8("adicionarCoordenada"));
	adicionarCoordenadaButton->setGeometry(QRect(100, 190, 80, 25));
	adicionarCoordenadaButton->setText(QString::fromUtf8("Adicionar"));
	removerCoordenadaButton = new QPushButton(this);
	removerCoordenadaButton->setObjectName(QString::fromUtf8("removerCoordenada"));
	removerCoordenadaButton->setGeometry(QRect(20, 190, 80, 25));
	removerCoordenadaButton->setText(QString::fromUtf8("Remover"));
	coordenadasPoligono = new list<Coordenada*>();

	QMetaObject::connectSlotsByName(this);

}

void AdicionarPoligono::on_okButton_clicked() {
	list<Coordenada*>* novaLista = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadasPoligono->begin();
	while (it != coordenadasPoligono->end()) {
		novaLista->push_back(static_cast<Coordenada*>(*it)->clone());
		it++;
	}
	Poligono *p = new Poligono(Utils::cloneChar(this->nomeInput->text().toUtf8().data()),
			novaLista);
	addEvent->OnAdicionarObjetoTipoClick(p);
}

void AdicionarPoligono::on_removerCoordenada_clicked() {
	QList<QListWidgetItem *> itens = this->coordenadasList->selectedItems();
	QList<QListWidgetItem*>::iterator it = itens.begin();
	while (it != itens.end()) {
		this->coordenadasList->removeItemWidget(static_cast<QListWidgetItem*>(*it)->clone());
		it++;
	}
	this->coordenadasList->repaint();
}

void AdicionarPoligono::on_adicionarCoordenada_clicked() {
	Coordenada* coordenada = new Coordenada();
	coordenada->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
	coordenada->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
	this->coordenadasPoligono->push_back(coordenada);

	QListWidgetItem * item = new QListWidgetItem();
	QString sX(this->xInput->text().toUtf8().data());
	QString sV(", ");
	QString sY(this->yInput->text().toUtf8().data());
	item->setText(sX + sV + sY);
	this->coordenadasList->addItem(item);

}

AdicionarPoligono::~AdicionarPoligono() {
	delete coordenadasPoligono;
	delete adicionarCoordenadaButton;
	delete coordenadasList;
	delete removerCoordenadaButton;
}

