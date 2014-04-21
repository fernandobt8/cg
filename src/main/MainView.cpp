#include "MainView.h"

MainView::MainView(MainController* controller) :
	OnAdicionarObjetoTipoEvent(), OnOkTransformcaoEvent(), QWidget() {
	this->controller = controller;
	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("Widget"));
	this->resize(850, 550);
	this->renderListaObjetosPanel();
	this->renderWindowPanel();
	this->renderControleWindowPanel();
	this->renderViewPortPanel();
	QMetaObject::connectSlotsByName(this);

	QDesktopWidget *desktop = QApplication::desktop();
	this->move((desktop->width() - 850) / 2, (desktop->height() - 550) / 2);
	this->setWindowTitle(QString::fromUtf8("Computação Grafica"));
}

void MainView::renderListaObjetosPanel() {
	listObjetosFrame = new QFrame(this);
	listObjetosFrame->setObjectName(QString::fromUtf8("listFrame"));
	listObjetosFrame->setGeometry(QRect(20, 20, 250, 220));
	listObjetosFrame->setFrameShape(QFrame::WinPanel);
	listObjetosFrame->setFrameShadow(QFrame::Raised);
	QLabel* listLabel = new QLabel(listObjetosFrame);
	listLabel->setObjectName(QString::fromUtf8("listLabel"));
	listLabel->setGeometry(QRect(10, 10, 100, 15));
	listObjetosPanel = new QListWidget(listObjetosFrame);
	listObjetosPanel->setObjectName(QString::fromUtf8("listaObjetos"));
	listObjetosPanel->setGeometry(QRect(10, 30, 230, 150));
	QPushButton* adicionarButton = new QPushButton(listObjetosFrame);
	adicionarButton->setObjectName(QString::fromUtf8("adicionarButton"));
	adicionarButton->setGeometry(QRect(160, 185, 80, 25));
	adicionarButton->setText("Adicionar");
	QPushButton* transformarButton = new QPushButton(listObjetosFrame);
	transformarButton->setObjectName(QString::fromUtf8("transformarButton"));
	transformarButton->setGeometry(QRect(10, 185, 80, 25));
	transformarButton->setText("Transformar");
	listLabel->setText("Lista de objetos");
}

void MainView::renderWindowPanel() {
	WindowFrame = new QFrame(this);
	WindowFrame->setObjectName(QString::fromUtf8("WindowFrame"));
	WindowFrame->setGeometry(QRect(20, 260, 250, 260));
	WindowFrame->setFrameShape(QFrame::WinPanel);
	WindowFrame->setFrameShadow(QFrame::Raised);
	QLabel* windowLabel = new QLabel(WindowFrame);
	windowLabel->setObjectName(QString::fromUtf8("windowLabel"));
	windowLabel->setGeometry(QRect(10, 10, 57, 15));
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
	windowHeightLabel->setText("Height");
	windowWidthLabel->setText("Width");
	windowOkButton->setText("OK");
	windowLabel->setText("Window");
	windowHeightEdit->setText("500");
	windowWidthEdit->setText("500");
}

void MainView::renderControleWindowPanel() {
	QPushButton* upButton = new QPushButton(WindowFrame);
	upButton->setObjectName(QString::fromUtf8("upButton"));
	upButton->setGeometry(QRect(100, 95, 50, 30));
	QPushButton* leftButton = new QPushButton(WindowFrame);
	leftButton->setObjectName(QString::fromUtf8("leftButton"));
	leftButton->setGeometry(QRect(50, 125, 50, 30));
	QPushButton* rightButton = new QPushButton(WindowFrame);
	rightButton->setObjectName(QString::fromUtf8("rightButton"));
	rightButton->setGeometry(QRect(150, 125, 50, 30));
	QPushButton* downButton = new QPushButton(WindowFrame);
	downButton->setObjectName(QString::fromUtf8("downButton"));
	downButton->setGeometry(QRect(100, 155, 50, 30));
	QPushButton* zoomInButton = new QPushButton(WindowFrame);
	zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
	zoomInButton->setGeometry(QRect(55, 190, 70, 30));
	QPushButton* zoomOutButton = new QPushButton(WindowFrame);
	zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
	zoomOutButton->setGeometry(QRect(125, 190, 70, 30));
	QPushButton* rotacionarButton = new QPushButton(WindowFrame);
	rotacionarButton->setObjectName(QString::fromUtf8("rotacionarButton"));
	rotacionarButton->setGeometry(QRect(120, 225, 70, 25));
	windowRotacaoEdit = new QLineEdit(WindowFrame);
	windowRotacaoEdit->setObjectName(QString::fromUtf8("windowRotacaoEdit"));
	windowRotacaoEdit->setGeometry(QRect(63, 225, 50, 25));
	QLabel* grauLabel = new QLabel(WindowFrame);
	grauLabel->setObjectName(QString::fromUtf8("grauLabel"));
	grauLabel->setGeometry(QRect(20, 230, 57, 15));
	upButton->setText("up");
	leftButton->setText("left");
	rightButton->setText("right");
	downButton->setText("down");
	zoomInButton->setText("zoom in");
	zoomOutButton->setText("zoom out");
	grauLabel->setText("Graus");
	rotacionarButton->setText("rotacionar");
}

void MainView::renderViewPortPanel() {
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

void MainView::on_rotacionarButton_clicked(){
	controller->rotacioneWindow(strtod(this->windowRotacaoEdit->text().toUtf8().constData(), NULL));
}

void MainView::onOkTransformacaoClick(list<Transformacao* >* transformacoes){
	if(transformacoes->size() > 0){
		QByteArray byte = listObjetosPanel->selectedItems().first()->text().toLocal8Bit();
		char* nome = byte.data();
		controller->transformeObjeto(nome, transformacoes);
	}
	delete transformarWindow;
}

void MainView::on_windowOkButton_clicked() {
	controller->setTamanhoWindow(
			strtod(this->windowWidthEdit->text().toUtf8().constData(), NULL),
			strtod(this->windowHeightEdit->text().toUtf8().constData(), NULL));
}

void MainView::updateWindow(Window* window) {
	windowWidthEdit->setText(QString::number(window->getWidth()));
	windowHeightEdit->setText(QString::number(window->getHeight()));
	viewPort->renderWindow(window);
}

void MainView::OnAdicionarObjetoTipoClick(ObjetoGeometrico *objeto) {
	QListWidgetItem * item = new QListWidgetItem();
	item->setText(Utils::cloneChar(objeto->getNome()));
	this->listObjetosPanel->addItem(item);
	controller->addObjeto(objeto);
	delete addObjetoWindow;
}

void MainView::on_adicionarButton_clicked() {
	addObjetoWindow = new AdicionarTipoObjetoView(this);
	addObjetoWindow->show();
}

void MainView::on_transformarButton_clicked() {
	if(listObjetosPanel->selectedItems().size() == 0){
		QMessageBox::information(NULL, "Aviso", "Selecione um objeto da lista antes!");
	}else{
		transformarWindow = new TransformacaoView(this);
		transformarWindow->show();
	}
}

MainView::~MainView() {
	delete listObjetosFrame;
	delete listObjetosPanel;
	delete WindowFrame;
	delete viewPortFrame;
	delete viewPort;
}
