/*
 * AdicionarCurva3d.cpp
 *
 *  Created on: 29/05/2014
 *      Author: alisson
 */

#include "AdicionarCurva3d.h"

AdicionarCurva3d::AdicionarCurva3d(QWidget *parent,	OnAdicionarObjetoTipoEvent *event) : AdicionarCurva(parent, event){
	radioButton1->hide();
	radioButton2->hide();
	avisoLabel->setText(QString::fromUtf8("16 pontos"));
}

AdicionarCurva3d::~AdicionarCurva3d() {
}

void AdicionarCurva3d::on_okButton_clicked() {
	if(coordenadasObjeto->size() >= 16 && coordenadasObjeto->size()%8 == 0){
		list<Coordenada*>* novaLista = new list<Coordenada*>();
		list<Coordenada*>::iterator it = coordenadasObjeto->begin();
		while (it != coordenadasObjeto->end()) {
			novaLista->push_back((*it)->clone());
			it++;
		}
		Curva3D *p = new Curva3D(Utils::cloneChar(this->nomeInput->text().toUtf8().data()), novaLista);
		if(bSpline)
			p->tipoCuva = Curva3D::SPLINES;
		addEvent->OnAdicionarObjetoTipoClick(p);
	}else
		QMessageBox::information(NULL, "Aviso", "Sao necessarios no mais de 16 pontos multiplo de 8!");
}

void AdicionarCurva3d::on_adicionarCoordenada_clicked() {
	AdicionarCurva::on_adicionarCoordenada_clicked();
}

