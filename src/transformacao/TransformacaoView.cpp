/*
 * TransformacaoView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "TransformacaoView.h"

TransformacaoView::TransformacaoView(QWidget *parent) :
		QWidget() {
	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("Transformacoes"));
	this->setWindowTitle(QString::fromUtf8("Transformacoes"));
	this->resize(560, 420);
	transformacaoWidget = new QTabWidget(this);
	transformacaoWidget->setObjectName(
			QString::fromUtf8("transformacaoWidget"));
	transformacaoWidget->setGeometry(QRect(10, 20, 370, 330));
	transformacaoWidget->addTab(new TranslacaoView(), QString::fromUtf8("Translação"));
	transformacaoWidget->addTab(new RotacaoView(), QString::fromUtf8("Rotação"));
	transformacaoWidget->addTab(new EscalonamentoView(),
			QString::fromUtf8("Escalonamento"));
	listWidget = new QListWidget(this);
	listWidget->setObjectName(QString::fromUtf8("listWidget"));
	listWidget->setGeometry(QRect(400, 40, 141, 321));
	label = new QLabel(this);
	label->setObjectName(QString::fromUtf8("label"));
	label->setGeometry(QRect(400, 20, 111, 17));
	label->setText(QString::fromUtf8("Transformações"));
	okButton = new QPushButton(this);
	okButton->setObjectName(QString::fromUtf8("okButton"));
	okButton->setGeometry(QRect(440, 370, 100, 30));
	okButton->setText(QString::fromUtf8("OK"));
	cancelarButton = new QPushButton(this);
	cancelarButton->setObjectName(QString::fromUtf8("cancelarButton"));
	cancelarButton->setGeometry(QRect(10, 370, 100, 30));
	cancelarButton->setText(QString::fromUtf8("Cancelar"));

	QMetaObject::connectSlotsByName(this);
}

TransformacaoView::~TransformacaoView() {
}
