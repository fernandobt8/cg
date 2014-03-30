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

void MainController::setWindow(double width, double height){
	window->setTamanhoWindow(width, height);
	window->update();
	view->updateWindow(window);
}

void MainController::addObjeto(ObjetoGeometrico* objeto) {
	objeto->addToAllCoordenadas(window->getStart());
	modelo->addObjeto(objeto);
	window->update();
	view->updateWindow(window);
}

void MainController::moveWindow(int tipoMovimento) {
	switch (tipoMovimento) {
	case TipoMovimento::UP:
		window->move(0, 5);
		break;
	case TipoMovimento::LEFT:
		window->move(-5, 0);
		break;
	case TipoMovimento::DOWN:
		window->move(0, -5);
		break;
	case TipoMovimento::RIGHT:
		window->move(5, 0);
		break;
	case TipoMovimento::ZOOM_IN:
		window->zoom(-6);
		break;
	case TipoMovimento::ZOOM_OUT:
		window->zoom(6);
		break;
	}
	window->update();
	view->updateWindow(window);
}

MainController::~MainController() {
	delete modelo;
	delete window;
	delete view;
}

