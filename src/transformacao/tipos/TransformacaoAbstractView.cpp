/*
 * TransformacaoAbstractView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "TransformacaoAbstractView.h"

TransformacaoAbstractView::TransformacaoAbstractView() : QWidget() {
	labelMovimentacao = new QLabel(this);
	labelMovimentacao->setObjectName(QString::fromUtf8("labelMovimentacao"));
	labelMovimentacao->setGeometry(QRect(30, 10, 100, 20));
	labelMovimentacao->setText(QString::fromUtf8("Movimentação"));
	frame = new QFrame(this);
	frame->setObjectName(QString::fromUtf8("frame"));
	frame->setGeometry(QRect(20, 30, 240, 130));
	frame->setFrameShape(QFrame::WinPanel);
	frame->setFrameShadow(QFrame::Sunken);
	xLabel = new QLabel(this);
	xLabel->setObjectName(QString::fromUtf8("xLabel"));
	xLabel->setGeometry(QRect(90, 50, 15, 20));
	xLabel->setText(QString::fromUtf8("X"));
	xInput = new QLineEdit(this);
	xInput->setObjectName(QString::fromUtf8("xInput"));
	xInput->setGeometry(QRect(110, 50, 70, 30));
	yLabel = new QLabel(this);
	yLabel->setObjectName(QString::fromUtf8("yLabel"));
	yLabel->setGeometry(QRect(90, 110, 15, 20));
	yLabel->setText(QString::fromUtf8("Y"));
	yInput = new QLineEdit(this);
	yInput->setObjectName(QString::fromUtf8("yInput"));
	yInput->setGeometry(QRect(110, 100, 70, 30));
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(250, 260, 100, 30));
	adicionarButton->setText(QString::fromUtf8("Adicionar"));
	QMetaObject::connectSlotsByName(this);
}

TransformacaoAbstractView::~TransformacaoAbstractView() {
	delete frame;
	delete labelMovimentacao;
	delete xInput;
	delete xLabel;
	delete yInput;
	delete yLabel;
	delete adicionarButton;
}

