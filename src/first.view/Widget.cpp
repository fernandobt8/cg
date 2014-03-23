#include "Widget.h"


Widget::Widget() : QMainWindow()
{
    if (this->objectName().isEmpty()){
        this->setObjectName(QString::fromUtf8("Widget"));
    }
    this->resize(680, 450);
    leftButton = new QPushButton(this);
    leftButton->setObjectName(QString::fromUtf8("leftButton"));
    leftButton->setGeometry(QRect(30, 330, 51, 27));
    upButton = new QPushButton(this);
    upButton->setObjectName(QString::fromUtf8("upButton"));
    upButton->setGeometry(QRect(80, 290, 51, 27));
    rightButton = new QPushButton(this);
    rightButton->setObjectName(QString::fromUtf8("rightButton"));
    rightButton->setGeometry(QRect(130, 330, 51, 27));
    downButton = new QPushButton(this);
    downButton->setObjectName(QString::fromUtf8("downButton"));
    downButton->setGeometry(QRect(80, 370, 51, 27));
    zoomInButton = new QPushButton(this);
    zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
    zoomInButton->setGeometry(QRect(10, 410, 87, 27));
    zoomInButton->setCursor(QCursor(Qt::PointingHandCursor));
    zoomOutButton = new QPushButton(this);
    zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
    zoomOutButton->setGeometry(QRect(110, 410, 87, 27));
    zoomOutButton->setCursor(QCursor(Qt::PointingHandCursor));
    verticalLayoutWidget = new QWidget(this);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(239, 19, 421, 401));



    QMetaObject::connectSlotsByName(this);
    this->setWindowTitle("Widget");
    upButton->setText("up");
    leftButton->setText("left");
    rightButton->setText("right");
    downButton->setText("down");
    zoomInButton->setText("zoom in");
    zoomOutButton->setText("zoom out");
    QObject::connect(upButton,SIGNAL(clicked()),this,SLOT(onUpClick()));
    QObject::connect(rightButton,SIGNAL(clicked()),this,SLOT(onRightClick()));
    QObject::connect(downButton,SIGNAL(clicked()),this,SLOT(onDownClick()));
    QObject::connect(leftButton,SIGNAL(clicked()),this,SLOT(onLeftClick()));

    QObject::connect(zoomInButton,SIGNAL(clicked()),this,SLOT(onZoomInClick()));
    QObject::connect(zoomOutButton,SIGNAL(clicked()),this,SLOT(onZoomOutClick()));
}

void Widget::paintEvent(QPaintEvent* e){
	QPainter *a = new QPainter(this);
	a->drawLine(10,10,50,50);
}

void Widget::onUpClick(){
	printf("up\n");
}

void Widget::onRightClick(){
	printf("right\n");
}

void Widget::onDownClick(){
	printf("down\n");
}

void Widget::onLeftClick(){
	printf("left\n");
}

void Widget::onZoomInClick(){
	printf("in\n");
}

void Widget::onZoomOutClick(){
	printf("out\n");
}

Widget::~Widget()
{

}
