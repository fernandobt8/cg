#include "Widget.h"

Widget::Widget() :
		QMainWindow() {
	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("Widget"));
	this->resize(836, 576);
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
	verticalLayoutWidget = new QWidget(this);
	verticalLayoutWidget->setObjectName(
			QString::fromUtf8("verticalLayoutWidget"));
	verticalLayoutWidget->setGeometry(QRect(300, 20, 501, 441));
	verticalLayout = new QVBoxLayout(verticalLayoutWidget);
	verticalLayout->setSpacing(6);
	verticalLayout->setContentsMargins(11, 11, 11, 11);
	verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
	verticalLayout->setContentsMargins(0, 0, 0, 0);
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

	QMetaObject::connectSlotsByName(this);
	this->setWindowTitle("Widget");
	upButton->setText("up");
	leftButton->setText("left");
	rightButton->setText("right");
	downButton->setText("down");
	zoomInButton->setText("zoom in");
	zoomOutButton->setText("zoom out");
	adicionarButton->setText("Adicionar");
	passoLabel->setText("Passo");
	QObject::connect(upButton, SIGNAL(clicked()), this, SLOT(onUpClick()));
	QObject::connect(rightButton, SIGNAL(clicked()), this,
			SLOT(onRightClick()));
	QObject::connect(downButton, SIGNAL(clicked()), this, SLOT(onDownClick()));
	QObject::connect(leftButton, SIGNAL(clicked()), this, SLOT(onLeftClick()));

	QObject::connect(zoomInButton, SIGNAL(clicked()), this,
			SLOT(onZoomInClick()));
	QObject::connect(zoomOutButton, SIGNAL(clicked()), this,
			SLOT(onZoomOutClick()));
	QObject::connect(adicionarButton, SIGNAL(clicked()), this, SLOT(onAdicionarButtonClicked()));
}

void Widget::paintEvent(QPaintEvent* e) {
	QPainter *a = new QPainter(this);
	a->drawLine(10, 10, 50, 50);
}

void Widget::onUpClick() {
	printf("up\n");
}

void Widget::onRightClick() {
	printf("right\n");
}

void Widget::onDownClick() {
	printf("down\n");
}

void Widget::onLeftClick() {
	printf("left\n");
}

void Widget::onZoomInClick() {
	printf("in\n");
}

void Widget::onZoomOutClick() {
	printf("out\n");
}

void Widget::onAdicionarButtonClicked() {
	adicionarWindow.show();
}

Widget::~Widget() {

}
