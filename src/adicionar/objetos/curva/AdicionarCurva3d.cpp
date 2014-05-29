/*
 * AdicionarCurva3d.cpp
 *
 *  Created on: 29/05/2014
 *      Author: alisson
 */

#include "AdicionarCurva3d.h"

AdicionarCurva3d::AdicionarCurva3d(QWidget *parent,	OnAdicionarObjetoTipoEvent *event) : AdicionarPoligono(parent, event){
	this->checkAberto->hide();
	QLabel *avisoLabel = new QLabel();
	avisoLabel->setGeometry(QRect(260, 45, 130, 25));
	avisoLabel->setText(QString::fromUtf8("16 pontos"));
	bezierButton = new QRadioButton(this);
	bezierButton->setGeometry(QRect(410, 100, 160, 25));
	bezierButton->setText(QString::fromUtf8("Bezier"));
	bezierButton->setChecked(true);
	splineButton = new QRadioButton(this);
	splineButton->setGeometry(QRect(410, 130, 160, 25));
	splineButton->setText(QString::fromUtf8("Spline"));
	selectColorButton->hide();
	panelSelectedColor->hide();

}

AdicionarCurva3d::~AdicionarCurva3d() {
	// TODO Auto-generated destructor stub
}

void AdicionarCurva3d::on_okButton_clicked() {
	if(coordenadasObjeto->size() == 16){
		list<Coordenada*>* novaLista = new list<Coordenada*>();
		list<Coordenada*>::iterator it = coordenadasObjeto->begin();
		while (it != coordenadasObjeto->end()) {
			novaLista->push_back((*it)->clone());
			it++;
	}
	Curva3D *p = new Curva3D(Utils::cloneChar(this->nomeInput->text().toUtf8().data()), novaLista);
	addEvent->OnAdicionarObjetoTipoClick(p);
	}else
		QMessageBox::information(NULL, "Aviso", "São necessários 16 pontos!");
}

void AdicionarCurva3d::on_adicionarCoordenada_clicked() {
	this->bezierButton->setEnabled(false);
	this->splineButton->setEnabled(false);
	if(coordenadasObjeto->size() < 16){
		AdicionarPoligono::on_adicionarCoordenada_clicked();
	}else
		QMessageBox::information(NULL, "Aviso", "Já foram adicionados 16 pontos!");

}
