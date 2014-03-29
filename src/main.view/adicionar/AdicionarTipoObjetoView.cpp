#include "AdicionarTipoObjetoView.h"

AdicionarTipoObjetoView::AdicionarTipoObjetoView(
		OnAdicionarObjetoTipoEvent *event, Coordenada *orientation) :
		QMainWindow() {

	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("AdicionarWindow"));
	this->resize(270, 400);
	centralwidget = new QWidget(this);
	centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
	tabWindow = new QTabWidget(centralwidget);
	tabWindow->setObjectName(QString::fromUtf8("tabWindow"));
	tabWindow->setGeometry(QRect(10, 10, 250, 380));
	tabWindow->addTab(new AdicionarPonto(this, event, orientation),
			QString("Ponto"));
	tabWindow->addTab(new AdicionarReta(this, event, orientation),
			QString("Reta"));
	tabWindow->addTab(new AdicionarPoligono(this, event, orientation),
			QString("Poligono"));

	this->setCentralWidget(centralwidget);
}

AdicionarTipoObjetoView::~AdicionarTipoObjetoView() {

}

