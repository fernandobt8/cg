/*
 * RotacaoView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "RotacaoView.h"

RotacaoView::RotacaoView(OnAdicionarTipoTransformacaoEvent* event) :
		QWidget() {
	this->event = event;
	frame = new QFrame(this);
	frame->setGeometry(QRect(20, 30, 320, 100));
	frame->setFrameShape(QFrame::WinPanel);
	frame->setFrameShadow(QFrame::Sunken);
	QLabel *operacoesLabel = new QLabel(this);
	operacoesLabel->setGeometry(QRect(30, 10, 80, 20));
	operacoesLabel->setText(QString::fromUtf8("Operações"));
	origemButton = new QRadioButton(this);
	origemButton->setObjectName(QString::fromUtf8("origemButton"));
	origemButton->setGeometry(QRect(40, 40, 241, 22));
	origemButton->setText(QString::fromUtf8("Rotacionar sobre a origem"));
	centroButton = new QRadioButton(this);
	centroButton->setObjectName(QString::fromUtf8("centroButton"));
	centroButton->setGeometry(QRect(40, 70, 281, 22));
	centroButton->setText(
			QString::fromUtf8("Rotacionar sobre o centro do objeto"));
	pontoButton = new QRadioButton(this);
	pontoButton->setObjectName(QString::fromUtf8("pontoButton"));
	pontoButton->setGeometry(QRect(40, 100, 291, 22));
	pontoButton->setText(
			QString::fromUtf8("Rotacionar sobre um ponto especifico"));
	QLabel *anguloLabel = new QLabel(this);
	anguloLabel->setGeometry(QRect(30, 140, 141, 20));
	anguloLabel->setText(QString::fromUtf8("Ângulo de rotação:"));
	QLabel *anguloXLabel = new QLabel(this);
	anguloXLabel->setGeometry(QRect(30, 170, 10, 25));
	anguloXLabel->setText(QString::fromUtf8("x"));
	anguloXInput = new QLineEdit(this);
	anguloXInput->setGeometry(QRect(40, 170, 60, 25));
	QLabel *grausXLabel = new QLabel(this);
	grausXLabel->setGeometry(QRect(100, 170, 15, 25));
	grausXLabel->setText(QString::fromUtf8("º"));
	QLabel *anguloYLabel = new QLabel(this);
	anguloYLabel->setGeometry(QRect(120, 170, 10, 25));
	anguloYLabel->setText(QString::fromUtf8("y"));
	anguloYInput = new QLineEdit(this);
	anguloYInput->setGeometry(QRect(130, 170, 60, 25));
	QLabel *grausYLabel = new QLabel(this);
	grausYLabel->setGeometry(QRect(190, 170, 15, 25));
	grausYLabel->setText(QString::fromUtf8("º"));
	QLabel *anguloZLabel = new QLabel(this);
	anguloZLabel->setGeometry(QRect(210, 170, 10, 25));
	anguloZLabel->setText(QString::fromUtf8("z"));
	anguloZInput = new QLineEdit(this);
	anguloZInput->setGeometry(QRect(220, 170, 60, 25));
	QLabel *grausZLabel = new QLabel(this);
	grausZLabel->setGeometry(QRect(280, 170, 15, 25));
	grausZLabel->setText(QString::fromUtf8("º"));
	pontoLabel = new QLabel(this);
	pontoLabel->setGeometry(QRect(30, 210, 51, 17));
	pontoLabel->setText(QString::fromUtf8("Ponto"));
	pontoLabel->hide();
	xLabel = new QLabel(this);
	xLabel->setGeometry(QRect(30, 230, 10, 25));
	xLabel->setText(QString::fromUtf8("x"));
	xLabel->hide();
	yLabel = new QLabel(this);
	yLabel->setGeometry(QRect(120, 230, 10, 25));
	yLabel->setText(QString::fromUtf8("y"));
	yLabel->hide();
	zLabel = new QLabel(this);
	zLabel->setGeometry(QRect(210, 230, 10, 25));
	zLabel->setText(QString::fromUtf8("z"));
	zLabel->hide();
	xInput = new QLineEdit(this);
	xInput->setGeometry(QRect(40, 230, 60, 25));
	xInput->hide();
	yInput = new QLineEdit(this);
	yInput->setGeometry(QRect(130, 230, 60, 25));
	yInput->hide();
	zInput = new QLineEdit(this);
	zInput->setGeometry(QRect(220, 230, 60, 25));
	zInput->hide();
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(280, 265, 80, 25));
	adicionarButton->setText(QString::fromUtf8("Adicionar"));

	QMetaObject::connectSlotsByName(this);
}

void RotacaoView::on_adicionarButton_clicked() {
	for(int i = 0; i < 3; i++){
		Rotacao* rotacao = new Rotacao();
		getAround(rotacao, i);
		if(origemButton->isChecked()){
			rotacao->tipoRotacao = Rotacao::ORIGEM;
		}else if(centroButton->isChecked()){
			rotacao->tipoRotacao = Rotacao::CENTRO;
		}else if(pontoButton->isChecked()){
			rotacao->tipoRotacao = Rotacao::PONTO;
			rotacao->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
			rotacao->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
			rotacao->setZ(strtod(this->zInput->text().toUtf8().data(), NULL));
		}
	event->onAdicionarTipoTransformacaoClick(rotacao);
	}
}

void RotacaoView::getAround(Rotacao *rotacao, int indice){
	switch(indice){
		case 0:{
			rotacao->angulo = strtod(this->anguloXInput->text().toUtf8().data(), NULL);
			rotacao->around = Rotacao::AROUND_X;
			break;
		}
		case 1:{
			rotacao->angulo = strtod(this->anguloYInput->text().toUtf8().data(), NULL);
			rotacao->around = Rotacao::AROUND_Y;
			break;
		}
		case 2:{
			rotacao->angulo = strtod(this->anguloZInput->text().toUtf8().data(), NULL);
			rotacao->around = Rotacao::AROUND_Z;
			break;
		}
	}

}

void RotacaoView::on_pontoButton_toggled(bool checked) {
	if (checked) {
		xInput->show();
		yInput->show();
		zInput->show();
		pontoLabel->show();
		xLabel->show();
		yLabel->show();
		zLabel->show();
	} else {
		xInput->hide();
		yInput->hide();
		zInput->hide();
		pontoLabel->hide();
		xLabel->hide();
		yLabel->hide();
		zLabel->hide();
	}
}

RotacaoView::~RotacaoView() {
	delete frame;
	delete origemButton;
	delete centroButton;
	delete pontoButton;
	delete anguloXInput;
	delete anguloYInput;
	delete anguloZInput;
	delete xInput;
	delete yInput;
	delete adicionarButton;
	delete pontoLabel;
	delete xLabel;
	delete yLabel;
	delete zLabel;
}

