#include "AdicionarTipoObjetoView.h"

AdicionarTipoObjetoView::AdicionarTipoObjetoView(
		OnAdicionarObjetoTipoEvent *event) :
		QMainWindow() {

	if (this->objectName().isEmpty())
		this->setObjectName(QString::fromUtf8("AdicionarWindow"));
	this->resize(500, 300);
	tabWindow = new QTabWidget(this);
	tabWindow->setObjectName(QString::fromUtf8("tabWindow"));
	tabWindow->setGeometry(QRect(10, 10, 480, 280));
	tabWindow->addTab(new AdicionarPonto(this, event), QString("Ponto"));
	tabWindow->addTab(new AdicionarReta(this, event), QString("Reta"));
	tabWindow->addTab(new AdicionarPoligono(this, event), QString("Poligono"));

	QDesktopWidget *desktop = QApplication::desktop();
	this->move((desktop->width() - 500) / 2, (desktop->height() - 300) / 2);
	this->setWindowTitle(QString::fromUtf8("Adicionar forma geométrica "));
}

void AdicionarTipoObjetoView::closeEvent(QCloseEvent* event){
	delete this;
}

AdicionarTipoObjetoView::~AdicionarTipoObjetoView() {
	delete tabWindow;
}

