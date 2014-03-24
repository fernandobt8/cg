#include "AdicionarWindow.h"

AdicionarWindow::AdicionarWindow() :
		QMainWindow() {

	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("AdicionarWindow"));
	this->resize(250, 282);
	centralwidget = new QWidget(this);
	centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
	nomeTextField = new QLineEdit(centralwidget);
	nomeTextField->setObjectName(QString::fromUtf8("nomeTextField"));
	nomeTextField->setGeometry(QRect(59, 10, 171, 25));
	nomeLabel = new QLabel(centralwidget);
	nomeLabel->setObjectName(QString::fromUtf8("nomeLabel"));
	nomeLabel->setGeometry(QRect(10, 15, 40, 15));
	nomeLabel->setText(QString::fromUtf8("Nome"));
	tabWindow = new QTabWidget(centralwidget);
	tabWindow->setObjectName(QString::fromUtf8("tabWindow"));
	tabWindow->setGeometry(QRect(10, 50, 221, 171));
	pontoWidget = new QWidget();
	pontoWidget->setObjectName(QString::fromUtf8("pontoWidget"));
	retaWidget = new QWidget();
	retaWidget->setObjectName(QString::fromUtf8("retaWidget"));
	poligonoWidget = new QWidget();
	poligonoWidget->setObjectName(QString::fromUtf8("poligonoWidget"));
	tabWindow->addTab(pontoWidget, QString("Ponto"));
	tabWindow->addTab(retaWidget, QString("Reta"));
	tabWindow->addTab(poligonoWidget, QString("Poligono"));
	xTextField = new QLineEdit(pontoWidget);
	xTextField->setObjectName(QString::fromUtf8("xTextField"));
	xTextField->setGeometry(QRect(30, 40, 50, 25));
	yTextField = new QLineEdit(pontoWidget);
	yTextField->setObjectName(QString::fromUtf8("yTextField"));
	yTextField->setGeometry(QRect(130, 40, 50, 25));
	coordenadasLabel = new QLabel(pontoWidget);
	coordenadasLabel->setObjectName(QString::fromUtf8("coordenadasLabel"));
	coordenadasLabel->setGeometry(QRect(10, 10, 81, 16));
	coordenadasLabel->setText(QString::fromUtf8("Coordenadas"));
	label = new QLabel(pontoWidget);
	label->setObjectName(QString::fromUtf8("label"));
	label->setGeometry(QRect(15, 45, 21, 16));
	label->setText(QString::fromUtf8("x"));
	label_2 = new QLabel(pontoWidget);
	label_2->setObjectName(QString::fromUtf8("label_2"));
	label_2->setGeometry(QRect(110, 45, 21, 16));
	label_2->setText(QString::fromUtf8("y"));
	xTextField_2 = new QLineEdit(retaWidget);
	xTextField_2->setObjectName(QString::fromUtf8("xTextField_2"));
	xTextField_2->setGeometry(QRect(30, 40, 50, 25));
	xTextField_3 = new QLineEdit(retaWidget);
	xTextField_3->setObjectName(QString::fromUtf8("xTextField_3"));
	xTextField_3->setGeometry(QRect(130, 40, 50, 25));
	xTextField_4 = new QLineEdit(retaWidget);
	xTextField_4->setObjectName(QString::fromUtf8("xTextField_4"));
	xTextField_4->setGeometry(QRect(30, 100, 50, 25));
	xTextField_5 = new QLineEdit(retaWidget);
	xTextField_5->setObjectName(QString::fromUtf8("xTextField_5"));
	xTextField_5->setGeometry(QRect(130, 100, 50, 25));
	coordenadasLabel_2 = new QLabel(retaWidget);
	coordenadasLabel_2->setObjectName(QString::fromUtf8("coordenadasLabel_2"));
	coordenadasLabel_2->setGeometry(QRect(10, 10, 131, 16));
	coordenadasLabel_2->setText(QString::fromUtf8("Coordenadas Iniciais"));
	coordenadasLabel_3 = new QLabel(retaWidget);
	coordenadasLabel_3->setObjectName(QString::fromUtf8("coordenadasLabel_3"));
	coordenadasLabel_3->setGeometry(QRect(10, 70, 131, 16));
	coordenadasLabel_3->setText(QString::fromUtf8("Coordenadas Finais"));
	label_3 = new QLabel(retaWidget);
	label_3->setObjectName(QString::fromUtf8("label_3"));
	label_3->setGeometry(QRect(10, 45, 21, 16));
	label_3->setText(QString::fromUtf8("x1"));
	label_4 = new QLabel(retaWidget);
	label_4->setObjectName(QString::fromUtf8("label_4"));
	label_4->setGeometry(QRect(110, 45, 21, 16));
	label_4->setText(QString::fromUtf8("x2"));
	label_5 = new QLabel(retaWidget);
	label_5->setObjectName(QString::fromUtf8("label_5"));
	label_5->setGeometry(QRect(10, 105, 21, 16));
	label_5->setText(QString::fromUtf8("y1"));
	label_6 = new QLabel(retaWidget);
	label_6->setObjectName(QString::fromUtf8("label_6"));
	label_6->setGeometry(QRect(110, 105, 21, 16));
	label_6->setText(QString::fromUtf8("y2"));
	okButton = new QPushButton(centralwidget);
	okButton->setObjectName(QString::fromUtf8("okButton"));
	okButton->setGeometry(QRect(140, 230, 80, 30));
	okButton->setText(QString::fromUtf8("Ok"));
	cancelarButton = new QPushButton(centralwidget);
	cancelarButton->setObjectName(QString::fromUtf8("cancelarButton"));
	cancelarButton->setGeometry(QRect(20, 230, 80, 30));
	cancelarButton->setText(QString::fromUtf8("Cancelar"));
	this->setCentralWidget(centralwidget);

	tabWindow->setCurrentIndex(0);

	QMetaObject::connectSlotsByName(this);
}

void AdicionarWindow::on_tabWindow_currentChanged(int index) {

}

void AdicionarWindow::on_okButton_clicked() {
	this->close();
}

void AdicionarWindow::on_cancelarButton_clicked() {
	this->close();
}

AdicionarWindow::~AdicionarWindow() {

}
