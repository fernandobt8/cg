/*
 * TransformacaoView.cpp
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#include "TransformacaoView.h"

TransformacaoView::TransformacaoView(OnOkTransformcaoEvent *event) : QMainWindow() {
	this->event = event;
	transformacoes = new list<Transformacao*>();
	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("Transformacoes"));
	this->setWindowTitle(QString::fromUtf8("Transformações"));
	this->resize(560, 400);
	transformacaoWidget = new QTabWidget(this);
	transformacaoWidget->setObjectName(QString::fromUtf8("transformacaoWidget"));
	transformacaoWidget->setGeometry(QRect(10, 10, 370, 330));
	transformacaoWidget->addTab(new TranslacaoView(this), QString::fromUtf8("Translação"));
	transformacaoWidget->addTab(new RotacaoView(this), QString::fromUtf8("Rotação"));
	transformacaoWidget->addTab(new EscalonamentoView(this), QString::fromUtf8("Escalonamento"));
	listWidget = new QListWidget(this);
	listWidget->setObjectName(QString::fromUtf8("listWidget"));
	listWidget->setGeometry(QRect(405, 39, 140, 320));
	label = new QLabel(this);
	label->setObjectName(QString::fromUtf8("label"));
	label->setGeometry(QRect(405, 17, 110, 20));
	label->setText(QString::fromUtf8("Transformações"));
	okButton = new QPushButton(this);
	okButton->setObjectName(QString::fromUtf8("okButton"));
	okButton->setGeometry(QRect(465, 370, 80, 25));
	okButton->setText(QString::fromUtf8("OK"));
	cancelarButton = new QPushButton(this);
	cancelarButton->setObjectName(QString::fromUtf8("cancelarButton"));
	cancelarButton->setGeometry(QRect(385, 370, 80, 25));
	cancelarButton->setText(QString::fromUtf8("Cancelar"));

	QDesktopWidget *desktop = QApplication::desktop();
	this->move((desktop->width() - 560) / 2, (desktop->height() - 400) / 2);
	QMetaObject::connectSlotsByName(this);
}

void TransformacaoView::onAdicionarTipoTransformacaoClick(Transformacao* transformacao){
	transformacoes->push_back(transformacao);
	QListWidgetItem * item = new QListWidgetItem();
	item->setText(QString::fromUtf8(Utils::cloneChar(transformacao->getNome())));
	this->listWidget->addItem(item);
}

void TransformacaoView::on_okButton_clicked(){
	event->onOkTransformacaoClick(transformacoes);
}

void TransformacaoView::on_cancelarButton_clicked(){
	delete this;
}

void TransformacaoView::closeEvent(QCloseEvent* event){
	delete this;
}

TransformacaoView::~TransformacaoView() {
	delete transformacaoWidget;
	delete listWidget;
	delete label;
	delete okButton;
	delete cancelarButton;
}
