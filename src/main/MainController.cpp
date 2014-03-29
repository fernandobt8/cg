/*
 * MainController.cpp
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#include "MainController.h"

MainController::MainController() {
	modelo = new ModeloInterno();
	window = new Window(modelo);
	this->view = new MainView(this);
	view->show();
}

void MainController::addObjeto(ObjetoGeometrico* objeto){
	objeto->addToAllCoordenadas(window->getStart());
	modelo->addObjeto(objeto);
	window->update();
	view->repaint();
}

MainController::~MainController() {
}

