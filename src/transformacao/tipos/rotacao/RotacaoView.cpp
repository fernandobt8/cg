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
	anguloLabel->setGeometry(QRect(20, 140, 141, 20));
	anguloLabel->setText(QString::fromUtf8("Ângulo de rotação:"));
	anguloInput = new QLineEdit(this);
	anguloInput->setGeometry(QRect(30, 170, 60, 25));
	QLabel *grausXLabel = new QLabel(this);
	grausXLabel->setGeometry(QRect(90, 170, 15, 25));
	grausXLabel->setText(QString::fromUtf8("º"));
	pontoLabel = new QLabel(this);
	pontoLabel->setGeometry(QRect(20, 210, 100, 17));
	pontoLabel->setText(QString::fromUtf8("Ponto"));
	pontoLabel->hide();
	x1Label = new QLabel(this);
	x1Label->setGeometry(QRect(20, 230, 10, 25));
	x1Label->setText(QString::fromUtf8("x"));
	x1Label->hide();
	y1Label = new QLabel(this);
	y1Label->setGeometry(QRect(110, 230, 10, 25));
	y1Label->setText(QString::fromUtf8("y"));
	y1Label->hide();
	z1Label = new QLabel(this);
	z1Label->setGeometry(QRect(200, 230, 10, 25));
	z1Label->setText(QString::fromUtf8("z"));
	z1Label->hide();
	x1Input = new QLineEdit(this);
	x1Input->setGeometry(QRect(30, 230, 60, 25));
	x1Input->hide();
	y1Input = new QLineEdit(this);
	y1Input->setGeometry(QRect(120, 230, 60, 25));
	y1Input->hide();
	z1Input = new QLineEdit(this);
	z1Input->setGeometry(QRect(210, 230, 60, 25));
	z1Input->hide();
	x2Label = new QLabel(this);
	x2Label->setGeometry(QRect(20, 265, 10, 25));
	x2Label->setText(QString::fromUtf8("x"));
	x2Label->hide();
	y2Label = new QLabel(this);
	y2Label->setGeometry(QRect(110, 265, 10, 25));
	y2Label->setText(QString::fromUtf8("y"));
	y2Label->hide();
	z2Label = new QLabel(this);
	z2Label->setGeometry(QRect(200, 265, 10, 25));
	z2Label->setText(QString::fromUtf8("z"));
	z2Label->hide();
	x2Input = new QLineEdit(this);
	x2Input->setGeometry(QRect(30, 265, 60, 25));
	x2Input->hide();
	y2Input = new QLineEdit(this);
	y2Input->setGeometry(QRect(120, 265, 60, 25));
	y2Input->hide();
	z2Input = new QLineEdit(this);
	z2Input->setGeometry(QRect(210, 265, 60, 25));
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
	if(origemButton->isChecked()){
		rotacao->tipoRotacao = Rotacao::ORIGEM;
	}else if(centroButton->isChecked()){
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
		pontoLabel->show();
		x1Input->show();
		y1Input->show();
		z1Input->show();
		x1Label->show();
		y1Label->show();
		z1Label->show();
		x2Input->show();
		y2Input->show();
		z2Input->show();
		x2Label->show();
		y2Label->show();
		z2Label->show();
	} else {
		pontoLabel->hide();
		x1Input->hide();
		y1Input->hide();
		z1Input->hide();
		x1Label->hide();
		y1Label->hide();
		z1Label->hide();
		x2Input->hide();
		y2Input->hide();
		z2Input->hide();
		x2Label->hide();
		y2Label->hide();
		z2Label->hide();
	}
}

void RotacaoView::on_centroButton_toggled(bool checked) {
	if (checked) {
		pontoLabel->setText(QString::fromUtf8("Ponto final"));
		pontoLabel->show();
		x1Input->show();
		y1Input->show();
		z1Input->show();
		x1Label->show();
		y1Label->show();
		z1Label->show();
	} else {
		pontoLabel->hide();
		x1Input->hide();
		y1Input->hide();
		z1Input->hide();
		x1Label->hide();
		y1Label->hide();
		z1Label->hide();
	}
}

void RotacaoView::pontoVisibility(bool checked){

}

RotacaoView::~RotacaoView() {
	delete frame;
	delete origemButton;
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

