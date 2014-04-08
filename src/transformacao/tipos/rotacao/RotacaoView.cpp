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
	frame->setObjectName(QString::fromUtf8("frame"));
	frame->setGeometry(QRect(20, 30, 320, 100));
	frame->setFrameShape(QFrame::WinPanel);
	frame->setFrameShadow(QFrame::Sunken);
	operacoesLabel = new QLabel(this);
	operacoesLabel->setObjectName(QString::fromUtf8("operacoesLabel"));
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
	anguloLabel = new QLabel(this);
	anguloLabel->setObjectName(QString::fromUtf8("anguloLabel"));
	anguloLabel->setGeometry(QRect(30, 155, 141, 20));
	anguloLabel->setText(QString::fromUtf8("Ângulo de rotação:"));
	anguloInput = new QLineEdit(this);
	anguloInput->setObjectName(QString::fromUtf8("anguloInput"));
	anguloInput->setGeometry(QRect(150, 155, 60, 25));
	grausLabel = new QLabel(this);
	grausLabel->setObjectName(QString::fromUtf8("grausLabel"));
	grausLabel->setGeometry(QRect(210, 155, 15, 15));
	grausLabel->setText(QString::fromUtf8("º"));
	pontoLabel = new QLabel(this);
	pontoLabel->setObjectName(QString::fromUtf8("pontoLabel"));
	pontoLabel->setGeometry(QRect(30, 205, 51, 17));
	pontoLabel->setText(QString::fromUtf8("Ponto"));
	pontoLabel->hide();
	xLabel = new QLabel(this);
	xLabel->setObjectName(QString::fromUtf8("xLabel"));
	xLabel->setGeometry(QRect(135, 205, 51, 17));
	xLabel->setText(QString::fromUtf8("X"));
	xLabel->hide();
	yLabel = new QLabel(this);
	yLabel->setObjectName(QString::fromUtf8("yLabel"));
	yLabel->setGeometry(QRect(135, 230, 51, 17));
	yLabel->setText(QString::fromUtf8("Y"));
	yLabel->hide();
	xInput = new QLineEdit(this);
	xInput->setObjectName(QString::fromUtf8("xInput"));
	xInput->setGeometry(QRect(150, 200, 60, 25));
	xInput->hide();
	yInput = new QLineEdit(this);
	yInput->setObjectName(QString::fromUtf8("yInput"));
	yInput->setGeometry(QRect(150, 225, 60, 25));
	yInput->hide();
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(250, 260, 100, 30));
	adicionarButton->setText(QString::fromUtf8("Adicionar"));

	QMetaObject::connectSlotsByName(this);
}

void RotacaoView::on_adicionarButton_clicked() {
	Rotacao* rotacao = new Rotacao();
	rotacao->setX(strtod(this->xInput->text().toUtf8().data(), NULL));
	rotacao->setY(strtod(this->yInput->text().toUtf8().data(), NULL));
	rotacao->angulo = strtod(this->anguloInput->text().toUtf8().data(), NULL);
	if(origemButton->isChecked()){
		rotacao->tipoRotacao = ORIGEM;
	}else if(centroButton->isChecked()){
		rotacao->tipoRotacao = CENTRO;
	}else if(pontoButton->isChecked()){
		rotacao->tipoRotacao = PONTO;
	}
	event->onAdicionarTipoTransformacaoClick(rotacao);
}

void RotacaoView::on_pontoButton_toggled(bool checked) {
	if (checked) {
		xInput->show();
		yInput->show();
		pontoLabel->show();
		xLabel->show();
		yLabel->show();
	} else {
		xInput->hide();
		yInput->hide();
		pontoLabel->hide();
		xLabel->hide();
		yLabel->hide();
	}
}

RotacaoView::~RotacaoView() {
}

