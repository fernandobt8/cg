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
	frame->setGeometry(QRect(20, 30, 320, 100));
	frame->setFrameShape(QFrame::WinPanel);
	frame->setFrameShadow(QFrame::Sunken);
	QLabel* xLabel = new QLabel(frame);
	xLabel->setObjectName(QString::fromUtf8("xLabel"));
	xLabel->setGeometry(QRect(10, 30, 10, 25));
	xLabel->setText(QString::fromUtf8("x"));
	xInput = new QLineEdit(frame);
	xInput->setObjectName(QString::fromUtf8("xInput"));
	xInput->setGeometry(QRect(20, 30, 50, 25));
	QLabel* yLabel = new QLabel(frame);
	yLabel->setObjectName(QString::fromUtf8("yLabel"));
	yLabel->setGeometry(QRect(80, 30, 10, 25));
	yLabel->setText(QString::fromUtf8("y"));
	yInput = new QLineEdit(frame);
	yInput->setObjectName(QString::fromUtf8("yInput"));
	yInput->setGeometry(QRect(90, 30, 50, 25));
	QLabel* zLabel = new QLabel(frame);
	zLabel->setObjectName(QString::fromUtf8("label_3"));
	zLabel->setGeometry(QRect(150, 30, 10, 25));
	zLabel->setText(QString::fromUtf8("z"));
	zInput = new QLineEdit(frame);
	zInput->setObjectName(QString::fromUtf8("zTextFieldPonto"));
	zInput->setGeometry(QRect(160, 30, 50, 25));
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(280, 265, 80, 25));
	adicionarButton->setText(QString::fromUtf8("Adicionar"));
	QMetaObject::connectSlotsByName(this);
}

TransformacaoAbstractView::~TransformacaoAbstractView() {
	delete frame;
	delete labelMovimentacao;
	delete adicionarButton;
}

