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
	z2Label->setGeometry(QRect(180, 150, 10, 25));
	z2Label->setText(QString::fromUtf8("z"));
	z2Input = new QLineEdit(this);
	z2Input->setGeometry(QRect(190, 150, 50, 25));
	avisoLabel = new QLabel(this);
	avisoLabel->setGeometry(QRect(260, 45, 130, 25));
	avisoLabel->setText(QString::fromUtf8("Mínimo 4 pontos!"));
	checkAberto->setText(QString::fromUtf8("B-Splines"));
	radioButton1 = new QRadioButton(this);
	radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
	radioButton1->setGeometry(QRect(410, 100, 160, 25));
	radioButton1->setText(QString::fromUtf8("Blending Fuction"));
	radioButton1->setChecked(true);
	radioButton2 = new QRadioButton(this);
	radioButton2->setObjectName(QString::fromUtf8("radioButton2"));
	radioButton2->setGeometry(QRect(410, 130, 160, 25));
	radioButton2->setText(QString::fromUtf8("Forward Difference"));
	selectColorButton->hide();
	panelSelectedColor->hide();
	bSpline = false;

}

void AdicionarCurva::on_checkAberto_toggled(bool checked){
	if(checked){
		x2Input->hide();
		y2Input->hide();
		z2Input->hide();
		x2Label->hide();
		y2Label->hide();
		z2Label->hide();
		pontoControle->hide();
	}else{
		x2Input->show();
		y2Input->show();
		z2Input->show();
		x2Label->show();
		y2Label->show();
		z2Label->show();
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
	p->algoritmo = radioButton1->isChecked() ? Curva::BLENDING_FUNCTION : Curva::FORWARD_DIFFERENCE;
	addEvent->OnAdicionarObjetoTipoClick(p);
}

void AdicionarCurva::on_adicionarCoordenada_clicked() {
	AdicionarPoligono::on_adicionarCoordenada_clicked();
	if(!bSpline){
		Coordenada* coordenada = new Coordenada();
		coordenada->setX(strtod(this->x2Input->text().toUtf8().data(), NULL));
		coordenada->setY(strtod(this->y2Input->text().toUtf8().data(), NULL));
		coordenada->setZ(strtod(this->z2Input->text().toUtf8().data(), NULL));
		this->coordenadasObjeto->push_back(coordenada);

		QListWidgetItem * item = new QListWidgetItem();
		QString sX2(this->x2Input->text().toUtf8().data());
		QString sY2(this->y2Input->text().toUtf8().data());
		QString sZ2(this->z2Input->text().toUtf8().data());
		QString sV2(", ");
		item->setText(sX2 + sV2 + sY2 + sV2 + sZ2);
		coordenadasList->addItem(item);
	}
}

AdicionarCurva::~AdicionarCurva() {
	delete x2Label;
	delete y2Label;
	delete z2Label;
	delete avisoLabel;
	delete x2Input;
	delete y2Input;
	delete z2Input;
	delete pontoControle;
}

