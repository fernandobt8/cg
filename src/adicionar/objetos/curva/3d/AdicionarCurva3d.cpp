/*
 * AdicionarCurva3d.cpp
 *
 *  Created on: 29/05/2014
 *      Author: alisson
 */

#include "AdicionarCurva3d.h"

AdicionarCurva3d::AdicionarCurva3d(QWidget *parent,	OnAdicionarObjetoTipoEvent *event) : AdicionarCurva(parent, event){
	radioButton1->setText(QString::fromUtf8("Bezier"));
	radioButton2->setText(QString::fromUtf8("Spline"));
	avisoLabel->setText(QString::fromUtf8("16 pontos"));
	radioButton2->setChecked(true);
	checkAberto->hide();
}

AdicionarCurva3d::~AdicionarCurva3d() {
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
	if(this->radioButton2->isChecked())
		p->tipoCuva = Curva3D::SPLINES;
	addEvent->OnAdicionarObjetoTipoClick(p);
	}else
		QMessageBox::information(NULL, "Aviso", "Sao necessarios 16 pontos!");
}

void AdicionarCurva3d::on_adicionarCoordenada_clicked() {
	this->radioButton1->setEnabled(false);
	this->radioButton2->setEnabled(false);
	if(coordenadasObjeto->size() < 16){
		AdicionarCurva::on_adicionarCoordenada_clicked();
	}else
		QMessageBox::information(NULL, "Aviso", "Ja foram adicionados 16 pontos!");

}

void AdicionarCurva3d::on_radioButton1_toggled(bool toggled) {
	if(toggled){
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
}
