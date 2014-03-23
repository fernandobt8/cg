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
    verticalLayout = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout->setSpacing(6);
    verticalLayout->setContentsMargins(11, 11, 11, 11);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    QMetaObject::connectSlotsByName(this);
    this->setWindowTitle("Widget");
    upButton->setText("up");
    leftButton->setText("left");
    rightButton->setText("right");
    downButton->setText("down");
    zoomInButton->setText("zoom in");
    zoomOutButton->setText("zoom out");
    QObject::connect(upButton,SIGNAL(clicked()),this,SLOT(clickedSlot()));
    QObject::connect(rightButton,SIGNAL(clicked()),this,SLOT(clicked()));
    QObject::connect(downButton,SIGNAL(clicked()),this,SLOT(clickeds()));
}
void Widget::clickedSlot(){
	QMessageBox* msgBox = new QMessageBox();
	msgBox->setWindowTitle("Hello");
	msgBox->setText("I love you");
	msgBox->exec();
}
void Widget::clicked(){
	QMessageBox* msgBox = new QMessageBox();
		msgBox->setWindowTitle("Hello");
		msgBox->setText("work");
		msgBox->exec();
}
void Widget::clickeds(){
	QMessageBox* msgBox = new QMessageBox();
		msgBox->setWindowTitle("Hello");
		msgBox->setText("worksss");
		msgBox->exec();
}
Widget::~Widget()
{

}
