#include "MainView.h"

MainView::MainView(MainController* controller) : QWidget(), OnAdicionarObjetoTipoEvent(){
	this->controller = controller;
	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("Widget"));
	this->resize(850, 550);
	this->renderControleWindowPanel();
	this->renderListaObjetosPanel();
	this->renderWindowPanel();
	viewPortFrame = new QFrame(this);
	viewPortFrame->setObjectName(QString::fromUtf8("listFrame"));
	viewPortFrame->setGeometry(QRect(320, 10, 500, 520));
	viewPortFrame->setFrameShape(QFrame::WinPanel);
	viewPortFrame->setFrameShadow(QFrame::Raised);
	QLabel* viewPortLabel = new QLabel(viewPortFrame);
	viewPortLabel->setObjectName(QString::fromUtf8("listLabel"));
	viewPortLabel->setGeometry(QRect(10, 10, 100, 15));
	viewPortLabel->setText("ViewPort");
	viewPort = new ViewPort(viewPortFrame);
	viewPort->setObjectName(QString::fromUtf8("viewPort"));
	viewPort->setGeometry(QRect(10, 30, 480, 480));

	QMetaObject::connectSlotsByName(this);
	this->setWindowTitle(QString::fromUtf8("Computação Grafica"));
}

void MainView::renderWindowPanel(){
	WindowFrame = new QFrame(this);
	WindowFrame->setObjectName(QString::fromUtf8("WindowFrame"));
	WindowFrame->setGeometry(QRect(20, 300, 250, 95));
	WindowFrame->setFrameShape(QFrame::WinPanel);
	WindowFrame->setFrameShadow(QFrame::Raised);
	windowWidthEdit = new QLineEdit(WindowFrame);
	windowWidthEdit->setObjectName(QString::fromUtf8("windowWidthEdit"));
	windowWidthEdit->setGeometry(QRect(63, 30, 113, 25));
	windowHeightEdit = new QLineEdit(WindowFrame);
	windowHeightEdit->setObjectName(QString::fromUtf8("windowHeightEdit"));
	windowHeightEdit->setGeometry(QRect(63, 60, 113, 25));
	QLabel* windowWidthLabel = new QLabel(WindowFrame);
	windowWidthLabel->setObjectName(QString::fromUtf8("windowWidthLabel"));
	windowWidthLabel->setGeometry(QRect(20, 35, 41, 16));
	QLabel* windowHeightLabel = new QLabel(WindowFrame);
	windowHeightLabel->setObjectName(QString::fromUtf8("windowHeightLabel"));
	windowHeightLabel->setGeometry(QRect(20, 65, 57, 15));
	QPushButton* windowOkButton = new QPushButton(WindowFrame);
	windowOkButton->setObjectName(QString::fromUtf8("windowOkButton"));
	windowOkButton->setGeometry(QRect(180, 60, 60, 25));
	QLabel* windowLabel = new QLabel(WindowFrame);
	windowLabel->setObjectName(QString::fromUtf8("windowLabel"));
	windowLabel->setGeometry(QRect(10, 10, 57, 15));
	windowHeightLabel->setText("Height");
	windowWidthLabel->setText("Width");
	windowOkButton->setText("OK");
	windowLabel->setText("Window");
}

void MainView::renderListaObjetosPanel() {
	listFrame = new QFrame(this);
	listFrame->setObjectName(QString::fromUtf8("listFrame"));
	listFrame->setGeometry(QRect(20, 20, 250, 220));
	listFrame->setFrameShape(QFrame::WinPanel);
	listFrame->setFrameShadow(QFrame::Raised);
	QLabel* listLabel = new QLabel(listFrame);
	listLabel->setObjectName(QString::fromUtf8("listLabel"));
	listLabel->setGeometry(QRect(10, 10, 100, 15));
	listaObjetos = new QListWidget(listFrame);
	listaObjetos->setObjectName(QString::fromUtf8("listaObjetos"));
	listaObjetos->setGeometry(QRect(10, 30, 230, 150));
	QPushButton* adicionarButton = new QPushButton(listFrame);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(10, 185, 80, 25));
	adicionarButton->setText("Adicionar");
	listLabel->setText("Lista de objetos");
}

void MainView::renderControleWindowPanel(){
	upButton = new QPushButton(this);
	upButton->setObjectName(QString::fromUtf8("upButton"));
	upButton->setGeometry(QRect(120, 400, 50, 30));
	leftButton = new QPushButton(this);
	leftButton->setObjectName(QString::fromUtf8("leftButton"));
	leftButton->setGeometry(QRect(70, 430, 50, 30));
	rightButton = new QPushButton(this);
	rightButton->setObjectName(QString::fromUtf8("rightButton"));
	rightButton->setGeometry(QRect(170, 430, 50, 30));
	downButton = new QPushButton(this);
	downButton->setObjectName(QString::fromUtf8("downButton"));
	downButton->setGeometry(QRect(120, 460, 50, 30));
	zoomInButton = new QPushButton(this);
	zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
	zoomInButton->setGeometry(QRect(75, 500, 70, 30));
	zoomInButton->setCursor(QCursor(Qt::PointingHandCursor));
	zoomOutButton = new QPushButton(this);
	zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
	zoomOutButton->setGeometry(QRect(145, 500, 70, 30));
	zoomOutButton->setCursor(QCursor(Qt::PointingHandCursor));
	upButton->setText("up");
	leftButton->setText("left");
	rightButton->setText("right");
	downButton->setText("down");
	zoomInButton->setText("zoom in");
	zoomOutButton->setText("zoom out");
}

void MainView::on_upButton_clicked() {
	controller->moveWindow(TipoMovimento::UP);
}

void MainView::on_rightButton_clicked() {
	controller->moveWindow(TipoMovimento::RIGHT);
}

void MainView::on_downButton_clicked() {
	controller->moveWindow(TipoMovimento::DOWN);
}

void MainView::on_leftButton_clicked() {
	controller->moveWindow(TipoMovimento::LEFT);
}

void MainView::on_zoomInButton_clicked() {
	controller->moveWindow(TipoMovimento::ZOOM_IN);
}

void MainView::on_zoomOutButton_clicked() {
	controller->moveWindow(TipoMovimento::ZOOM_OUT);
}

void MainView::on_adicionarButton_clicked() {
	adicionarWindow = new AdicionarTipoObjetoView(this);
	adicionarWindow->show();
}

void MainView::on_windowOkButton_clicked(){
	controller->setWindow(atoi(this->windowWidthEdit->text().toUtf8().constData()), atoi(this->windowHeightEdit->text().toUtf8().constData()));
}

void MainView::updateWindow(Window* window){
	viewPort->renderWindow(window);
}

void MainView::OnAdicionarObjetoTipoClick(ObjetoGeometrico *objeto) {
	delete adicionarWindow;
	controller->addObjeto(objeto);
	QListWidgetItem * item = new QListWidgetItem();
	item->setText(objeto->getNome());
	this->listaObjetos->addItem(item);
}

MainView::~MainView() {
	delete upButton;
	delete leftButton;
	delete rightButton;
	delete downButton;
	delete zoomInButton;
	delete zoomOutButton;
	delete listaObjetos;
	delete viewPort;
	delete WindowFrame;
}
