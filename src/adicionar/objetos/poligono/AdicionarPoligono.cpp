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
	coordenadasObjeto = new list<Coordenada*>();

	checkAberto = new QCheckBox(this);
	checkAberto->setObjectName(QString::fromUtf8("checkAberto"));
	checkAberto->setGeometry(QRect(340, 75, 130, 25));
	checkAberto->setText(QString::fromUtf8("Aberto"));
	selectColorButton = new QPushButton(this);
	selectColorButton->setObjectName(QString::fromUtf8("selectColorButton"));
	selectColorButton->setGeometry(QRect(340, 100, 110, 25));
	selectColorButton->setText(QString::fromUtf8("Selecionar Cor"));
	panelSelectedColor = new QWidget(this);
	panelSelectedColor->setObjectName(QString::fromUtf8("panelSelectedColor"));
	panelSelectedColor->setGeometry(QRect(340, 130, 110, 50));
	panelSelectedColor->setAutoFillBackground(true);
	panelSelectedColor->setPalette(QPalette(QPalette::Background, Qt::white));
	sentidoHorario = new QLabel(this);
	sentidoHorario->setObjectName(QString::fromUtf8("label"));
	sentidoHorario->setGeometry(QRect(20, 115, 110, 25));
	sentidoHorario->setText(QString::fromUtf8("*Sentido horário."));
	color = QColor("white");
	QMetaObject::connectSlotsByName(this);
}

void AdicionarPoligono::on_selectColorButton_clicked(){
	QColor colour = QColorDialog::getColor(color);
	if(colour.isValid()){
		panelSelectedColor->setPalette(QPalette(QPalette::Background, colour));
		color = colour;
	}
}

void AdicionarPoligono::on_checkAberto_toggled(bool checked){
	if(checked){
		selectColorButton->hide();
		panelSelectedColor->hide();
	}else{
		selectColorButton->show();
		panelSelectedColor->show();
	}
}

void AdicionarPoligono::on_okButton_clicked() {
	list<Coordenada*>* novaLista = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadasObjeto->begin();
	while (it != coordenadasObjeto->end()) {
		novaLista->push_back((*it)->clone());
		it++;
	}
	Poligono *p = new Poligono(Utils::cloneChar(this->nomeInput->text().toUtf8().data()), novaLista);
	p->aberto = checkAberto->isChecked();
	p->color = new QColor(color);
	addEvent->OnAdicionarObjetoTipoClick(p);
}

void AdicionarPoligono::on_removerCoordenada_clicked() {
	QList<QListWidgetItem *> itens = this->coordenadasList->selectedItems();
	QList<QListWidgetItem*>::iterator it = itens.begin();
	while (it != itens.end()) {
		this->coordenadasList->removeItemWidget(static_cast<QListWidgetItem*>(*it));
		it++;
	}
	this->coordenadasList->repaint();
}

void AdicionarPoligono::on_adicionarCoordenada_clicked() {
	Coordenada* coordenada = new Coordenada();
	coordenada->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
	coordenada->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
	this->coordenadasObjeto->push_back(coordenada);

	QListWidgetItem * item = new QListWidgetItem();
	QString sX(this->xInput->text().toUtf8().data());
	QString sV(", ");
	QString sY(this->yInput->text().toUtf8().data());
	item->setText(sX + sV + sY);
	this->coordenadasList->addItem(item);

}

AdicionarPoligono::~AdicionarPoligono() {
	delete checkAberto;
	delete selectColorButton;
	delete panelSelectedColor;
	ListUtils::destroyList(coordenadasObjeto);
	delete adicionarCoordenadaButton;
	delete coordenadasList;
	delete removerCoordenadaButton;
}

