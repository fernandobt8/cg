/*
 * RotacaoView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "RotacaoView.h"

RotacaoView::RotacaoView() :
		QWidget() {
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
	anguloInput->setGeometry(QRect(170, 155, 60, 25));
	grausLabel = new QLabel(this);
	grausLabel->setObjectName(QString::fromUtf8("grausLabel"));
	grausLabel->setGeometry(QRect(230, 155, 15, 15));
	grausLabel->setText(QString::fromUtf8("º"));
	pontoLabel = new QLabel(this);
	pontoLabel->setObjectName(QString::fromUtf8("pontoLabel"));
	pontoLabel->setGeometry(QRect(110, 205, 51, 17));
	pontoLabel->setText(QString::fromUtf8("Ponto:"));
	pontoLabel->hide();
	pontoInput = new QLineEdit(this);
	pontoInput->setObjectName(QString::fromUtf8("pontoInput"));
	pontoInput->setGeometry(QRect(170, 200, 60, 25));
	pontoInput->hide();
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(250, 260, 100, 30));
	adicionarButton->setText(QString::fromUtf8("Adicionar"));

	QMetaObject::connectSlotsByName(this);
}

RotacaoView::~RotacaoView() {
}

void RotacaoView::on_pontoButton_toggled(bool checked) {
	if (checked) {
		pontoInput->show();
		pontoLabel->show();
	} else {
		pontoInput->hide();
		pontoLabel->hide();
	}

}

void RotacaoView::on_adicionarButton_clicked() {

}
