#include "AdicionarTipoObjetoView.h"

AdicionarTipoObjetoView::AdicionarTipoObjetoView(
		OnAdicionarObjetoTipoEvent *event, Coordenada *orientation) :
		QMainWindow() {

	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("AdicionarWindow"));
	this->resize(270, 270);
	centralwidget = new QWidget(this);
	centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
	tabWindow = new QTabWidget(centralwidget);
	tabWindow->setObjectName(QString::fromUtf8("tabWindow"));
	tabWindow->setGeometry(QRect(10, 10, 250, 250));

	poligonoWidget = new QWidget();
	poligonoWidget->setObjectName(QString::fromUtf8("poligonoWidget"));
	tabWindow->addTab(new AdicionarPonto(this, event, orientation), QString("Ponto"));
	tabWindow->addTab(new AdicionarReta(this, event, orientation), QString("Reta"));
	tabWindow->addTab(poligonoWidget, QString("Poligono"));


	coordenadasList = new QListWidget(poligonoWidget);
	coordenadasList->setObjectName(QString::fromUtf8("coordenadasList"));
	coordenadasList->setGeometry(QRect(10, 10, 200, 61));
	adicionarCoordenada = new QPushButton(poligonoWidget);
	adicionarCoordenada->setObjectName(
			QString::fromUtf8("adicionarCoordenada"));
	adicionarCoordenada->setGeometry(QRect(20, 160, 201, 27));
	adicionarCoordenada->setText(
			QString::fromUtf8("Adicionar nova coordenada"));
	xTextFieldPoligono = new QLineEdit(poligonoWidget);
	xTextFieldPoligono->setObjectName(QString::fromUtf8("xTextFieldPoligono"));
	xTextFieldPoligono->setGeometry(QRect(50, 120, 50, 25));
	yTextFieldPoligono = new QLineEdit(poligonoWidget);
	yTextFieldPoligono->setObjectName(QString::fromUtf8("yTextFieldPoligono"));
	yTextFieldPoligono->setGeometry(QRect(150, 120, 50, 25));
	label_7 = new QLabel(poligonoWidget);
	label_7->setObjectName(QString::fromUtf8("label"));
	label_7->setGeometry(QRect(30, 120, 16, 17));
	label_7->setText(QString::fromUtf8("x"));
	label_8 = new QLabel(poligonoWidget);
	label_8->setObjectName(QString::fromUtf8("label_2"));
	label_8->setGeometry(QRect(130, 120, 16, 17));
	label_8->setText(QString::fromUtf8("y"));
	removerCoordenada = new QPushButton(poligonoWidget);
	removerCoordenada->setObjectName(QString::fromUtf8("removerCoordenada"));
	removerCoordenada->setGeometry(QRect(20, 80, 201, 27));
	removerCoordenada->setText(QString::fromUtf8("Remover coordenada"));
	this->setCentralWidget(centralwidget);

	tabWindow->setCurrentIndex(0);

	QMetaObject::connectSlotsByName(this);
}

void AdicionarTipoObjetoView::on_tabWindow_currentChanged(int index) {

}

ObjetoGeometrico* AdicionarTipoObjetoView::getPoligono() {
	Poligono *p = new Poligono("NomeText", &coordenadasPoligono);
	memset(&coordenadasPoligono, 0, sizeof(coordenadasPoligono));
	return p;
}

void AdicionarTipoObjetoView::on_cancelarButton_clicked() {
	this->close();
}

void AdicionarTipoObjetoView::on_removerCoordenada_clicked() {

}

void AdicionarTipoObjetoView::on_adicionarCoordenada_clicked() {
	Coordenada** coordenadas = new Coordenada*[0];
	coordenadas[0] = new Coordenada();
	//coordenadas[0]->setX(atoi(this->xTextFieldPoligono->text().toUtf8().data()) + orientation->getX());
	//coordenadas[0]->setY(atoi(this->yTextFieldPoligono->text().toUtf8().data()) + orientation->getY());
	this->coordenadasPoligono.push_back(coordenadas[0]);
	QListWidgetItem * item = new QListWidgetItem();
	char *text = new char[strlen(this->xTextFieldPoligono->text().toUtf8().data()) + strlen(this->yTextFieldPoligono->text().toUtf8().data())];
	memset(&text[0], 0, sizeof(text));
	strcat(text, this->xTextFieldPoligono->text().toUtf8().data());
	strcat(text, ",");
	strcat(text, this->yTextFieldPoligono->text().toUtf8().data());
	item->setText(text);
	this->coordenadasList->addItem(item);
}

AdicionarTipoObjetoView::~AdicionarTipoObjetoView() {

}
