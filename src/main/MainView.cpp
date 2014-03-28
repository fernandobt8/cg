#include "MainView.h"

MainView::MainView(MainController* controller) : QWidget(), OnAdicionarObjetoTipoEvent(){
	this->controller = controller;
	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("Widget"));
	this->resize(836, 576);
	this->renderControleWindowPanel();
	this->renderListaObjetosPanel();
	viewPort = new ViewPort(this);
	viewPort->setObjectName(QString::fromUtf8("viewPort"));
	viewPort->setGeometry(QRect(300, 25, 500, 500));

	QMetaObject::connectSlotsByName(this);
	this->setWindowTitle(QString::fromUtf8("Computação Grafica"));
}

void MainView::renderListaObjetosPanel(){
	adicionarWindow = new AdicionarTipoObjetoView(this);
	listaObjetos = new QListWidget(this);
	listaObjetos->setObjectName(QString::fromUtf8("listaObjetos"));
	listaObjetos->setGeometry(QRect(20, 30, 250, 190));
	adicionarButton = new QPushButton(this);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(100, 230, 90, 30));
	lineEdit = new QLineEdit(this);
	lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
	lineEdit->setGeometry(QRect(120, 290, 50, 25));
	passoLabel = new QLabel(this);
	passoLabel->setObjectName(QString::fromUtf8("passoLabel"));
	passoLabel->setGeometry(QRect(50, 295, 41, 16));
	adicionarButton->setText("Adicionar");
	passoLabel->setText("Passo");
}

void MainView::renderControleWindowPanel(){
	upButton = new QPushButton(this);
	upButton->setObjectName(QString::fromUtf8("upButton"));
	upButton->setGeometry(QRect(120, 340, 50, 30));
	leftButton = new QPushButton(this);
	leftButton->setObjectName(QString::fromUtf8("leftButton"));
	leftButton->setGeometry(QRect(70, 370, 50, 30));
	rightButton = new QPushButton(this);
	rightButton->setObjectName(QString::fromUtf8("rightButton"));
	rightButton->setGeometry(QRect(170, 370, 50, 30));
	downButton = new QPushButton(this);
	downButton->setObjectName(QString::fromUtf8("downButton"));
	downButton->setGeometry(QRect(120, 400, 50, 30));
	zoomInButton = new QPushButton(this);
	zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
	zoomInButton->setGeometry(QRect(75, 440, 70, 30));
	zoomInButton->setCursor(QCursor(Qt::PointingHandCursor));
	zoomOutButton = new QPushButton(this);
	zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
	zoomOutButton->setGeometry(QRect(145, 440, 70, 30));
	zoomOutButton->setCursor(QCursor(Qt::PointingHandCursor));
	upButton->setText("up");
	leftButton->setText("left");
	rightButton->setText("right");
	downButton->setText("down");
	zoomInButton->setText("zoom in");
	zoomOutButton->setText("zoom out");
}

void MainView::on_upButton_clicked() {
	printf("up\n");
}

void MainView::on_rightButton_clicked() {
	printf("right\n");
}

void MainView::on_downButton_clicked() {
	printf("down\n");
}

void MainView::on_leftButton_clicked() {
	printf("left\n");
}

void MainView::on_zoomInButton_clicked() {
	printf("in\n");
}

void MainView::on_zoomOutButton_clicked() {
	printf("out\n");
}

void MainView::on_adicionarButton_clicked() {
	adicionarWindow->show();
}

void MainView::OnAdicionarObjetoTipoClick(ObjetoGeometrico *objeto){
	controller->addObjeto(objeto);
}

MainView::~MainView(){

}
