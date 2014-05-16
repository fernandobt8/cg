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
	frame->setGeometry(QRect(20, 30, 320, 70));
	frame->setFrameShape(QFrame::WinPanel);
	frame->setFrameShadow(QFrame::Sunken);
	QLabel *operacoesLabel = new QLabel(this);
	operacoesLabel->setGeometry(QRect(30, 10, 80, 20));
	operacoesLabel->setText(QString::fromUtf8("Operações"));
	centroButton = new QRadioButton(this);
	centroButton->setObjectName(QString::fromUtf8("centroButton"));
	centroButton->setGeometry(QRect(40, 40, 300, 20));
	centroButton->setText(
			QString::fromUtf8("Rotacionar sobre o centro do objeto"));
	centroButton->setChecked(true);
	pontoButton = new QRadioButton(this);
	pontoButton->setObjectName(QString::fromUtf8("pontoButton"));
	pontoButton->setGeometry(QRect(40, 70, 281, 20));
	pontoButton->setText(
			QString::fromUtf8("Rotacionar sobre um ponto especifico"));
	QLabel *anguloLabel = new QLabel(this);
	anguloLabel->setGeometry(QRect(20, 120, 141, 20));
	anguloLabel->setText(QString::fromUtf8("Ângulo de rotação:"));
	anguloInput = new QLineEdit(this);
	anguloInput->setGeometry(QRect(30, 150, 60, 25));
	QLabel *grausXLabel = new QLabel(this);
	grausXLabel->setGeometry(QRect(90, 150, 15, 25));
	grausXLabel->setText(QString::fromUtf8("º"));
	pontoLabel = new QLabel(this);
	pontoLabel->setGeometry(QRect(20, 190, 100, 17));
	pontoLabel->setText(QString::fromUtf8("Ponto"));
	x1Label = new QLabel(this);
	x1Label->setGeometry(QRect(20, 210, 10, 25));
	x1Label->setText(QString::fromUtf8("x"));
	y1Label = new QLabel(this);
	y1Label->setGeometry(QRect(110, 210, 10, 25));
	y1Label->setText(QString::fromUtf8("y"));
	z1Label = new QLabel(this);
	z1Label->setGeometry(QRect(200, 210, 10, 25));
	z1Label->setText(QString::fromUtf8("z"));
	x1Input = new QLineEdit(this);
	x1Input->setGeometry(QRect(30, 210, 60, 25));
	y1Input = new QLineEdit(this);
	y1Input->setGeometry(QRect(120, 210, 60, 25));
	z1Input = new QLineEdit(this);
	z1Input->setGeometry(QRect(210, 210, 60, 25));
	x2Label = new QLabel(this);
	x2Label->setGeometry(QRect(20, 245, 10, 25));
	x2Label->setText(QString::fromUtf8("x"));
	x2Label->hide();
	y2Label = new QLabel(this);
	y2Label->setGeometry(QRect(110, 245, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Label->hide();
	z2Label = new QLabel(this);
	z2Label->setGeometry(QRect(200, 245, 10, 25));
	z2Label->setText(QString::fromUtf8("z"));
	z2Label->hide();
	x2Input = new QLineEdit(this);
	x2Input->setGeometry(QRect(30, 245, 60, 25));
	x2Input->hide();
	y2Input = new QLineEdit(this);
	y2Input->setGeometry(QRect(120, 245, 60, 25));
	y2Input->hide();
	z2Input = new QLineEdit(this);
	z2Input->setGeometry(QRect(210, 245, 60, 25));
	z2Input->hide();
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(280, 265, 80, 25));
	adicionarButton->setText(QString::fromUtf8("Adicionar"));

	QMetaObject::connectSlotsByName(this);
}

void RotacaoView::on_adicionarButton_clicked() {
	Rotacao* rotacao = new Rotacao();
	rotacao->angulo = strtod(this->anguloInput->text().toUtf8().data(), NULL);
	if(centroButton->isChecked()){
		rotacao->tipoRotacao = Rotacao::CENTRO;
		rotacao->setXFinal(strtod(this->x1Input->text().toUtf8().data(), NULL));
		rotacao->setYFinal(strtod(this->y1Input->text().toUtf8().data(), NULL));
		rotacao->setZFinal(strtod(this->z1Input->text().toUtf8().data(), NULL));
	}else if(pontoButton->isChecked()){
		rotacao->tipoRotacao = Rotacao::PONTO;
		rotacao->setX(strtod(this->x1Input->text().toUtf8().data(), NULL));
		rotacao->setY(strtod(this->y1Input->text().toUtf8().data(), NULL));
		rotacao->setZ(strtod(this->z1Input->text().toUtf8().data(), NULL));
		rotacao->setXFinal(strtod(this->x2Input->text().toUtf8().data(), NULL));
		rotacao->setYFinal(strtod(this->y2Input->text().toUtf8().data(), NULL));
		rotacao->setZFinal(strtod(this->z2Input->text().toUtf8().data(), NULL));
	}
	event->onAdicionarTipoTransformacaoClick(rotacao);
}

void RotacaoView::on_pontoButton_toggled(bool checked) {
	if (checked) {
		pontoLabel->setText(QString::fromUtf8("Pontos"));
		x2Input->show();
		y2Input->show();
		z2Input->show();
		x2Label->show();
		y2Label->show();
		z2Label->show();
	} else {
		pontoLabel->setText(QString::fromUtf8("Ponto"));
		x2Input->hide();
		y2Input->hide();
		z2Input->hide();
		x2Label->hide();
		y2Label->hide();
		z2Label->hide();
	}
}

RotacaoView::~RotacaoView() {
	delete frame;
	delete centroButton;
	delete pontoButton;
	delete anguloInput;
	delete x1Input;
	delete y1Input;
	delete adicionarButton;
	delete pontoLabel;
	delete x1Label;
	delete y1Label;
	delete z1Label;
}

