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
	pontoControle->setGeometry(QRect(10, 130, 150, 10));
	pontoControle->setText(QString::fromUtf8("Ponto de controle"));
	x2Label = new QLabel(this);
	x2Label->setGeometry(20, 150, 10, 25);
	x2Label->setText(QString::fromUtf8("x"));
	x2Input = new QLineEdit(this);
	x2Input->setGeometry(30, 150, 50, 25);
	y2Label = new QLabel(this);
	y2Label->setGeometry(QRect(100, 150, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Input = new QLineEdit(this);
	y2Input->setGeometry(QRect(110, 150, 50, 25));
	z2Label = new QLabel(this);
	z2Label->setObjectName(QString::fromUtf8("label_2"));
	z2Label->setGeometry(QRect(180, 150, 10, 25));
	z2Label->setText(QString::fromUtf8("z"));
	z2Input = new QLineEdit(this);
	z2Input->setObjectName(QString::fromUtf8("yTextFieldPonto"));
	z2Input->setGeometry(QRect(190, 150, 50, 25));
	avisoLabel = new QLabel(this);
	avisoLabel->setObjectName(QString::fromUtf8("avisoLabel"));
	avisoLabel->setGeometry(QRect(260, 45, 130, 25));
	avisoLabel->setText(QString::fromUtf8("Mínimo 4 pontos!"));
	checkAberto->setText(QString::fromUtf8("B-Splines"));
	blendingFuctionButton = new QRadioButton(this);
	blendingFuctionButton->setObjectName(QString::fromUtf8("blendingFuctionButton"));
	blendingFuctionButton->setGeometry(QRect(410, 100, 160, 25));
	blendingFuctionButton->setText(QString::fromUtf8("Blending Fuction"));
	blendingFuctionButton->setChecked(true);
	forwardDifferenceButton = new QRadioButton(this);
	forwardDifferenceButton->setObjectName(QString::fromUtf8("forwardDifferenceButton"));
	forwardDifferenceButton->setGeometry(QRect(410, 130, 160, 25));
	forwardDifferenceButton->setText(QString::fromUtf8("Forward Difference"));
	selectColorButton->hide();
	panelSelectedColor->hide();

}

void AdicionarCurva::on_checkAberto_toggled(bool checked){
	if(checked){
		x2Input->hide();
		y2Input->hide();
		x2Label->hide();
		y2Label->hide();
		pontoControle->hide();
	}else{
		x2Input->show();
		y2Input->show();
		x2Label->show();
		y2Label->show();
		pontoControle->show();
	}
	bSpline = checkAberto->isChecked();
}

void AdicionarCurva::on_okButton_clicked() {
	list<Coordenada*>* novaLista = new list<Coordenada*>();
	list<Coordenada*>::iterator it = coordenadasObjeto->begin();
	while (it != coordenadasObjeto->end()) {
		novaLista->push_back((*it)->clone());
		it++;
	}
	Curva *p = new Curva(Utils::cloneChar(this->nomeInput->text().toUtf8().data()), novaLista);
	p->bSpline = checkAberto->isChecked();
	p->algoritmo = blendingFuctionButton->isChecked() ? Curva::BLENDING_FUNCTION : Curva::FORWARD_DIFFERENCE;
	addEvent->OnAdicionarObjetoTipoClick(p);
}

void AdicionarCurva::on_adicionarCoordenada_clicked() {
	AdicionarPoligono::on_adicionarCoordenada_clicked();
	if(!bSpline){
		Coordenada* coordenada = new Coordenada();
		coordenada->setX(strtod(this->x2Input->text().toUtf8().data(), NULL));
		coordenada->setY(strtod(this->y2Input->text().toUtf8().data(), NULL));
		this->coordenadasObjeto->push_back(coordenada);

		QListWidgetItem * item = new QListWidgetItem();
		QString sX2(this->x2Input->text().toUtf8().data());
		QString sV2(", ");
		QString sY2(this->y2Input->text().toUtf8().data());
		item->setText(sX2 + sV2 + sY2);
		this->coordenadasList->addItem(item);
	}
}

AdicionarCurva::~AdicionarCurva() {
	delete x2Label;
	delete y2Label;
	delete avisoLabel;
	delete x2Input;
	delete y2Input;
	delete pontoControle;
}

