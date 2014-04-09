/*
 * MainController.cpp
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#include "MainController.h"

MainController::MainController() {
	window = new Window();
	modelo = new ModeloInterno(window);
	this->view = new MainView(this);
	view->show();
}

void MainController::transformeObjeto(char* nome, list<Transformacao*>* transformacoes){
	modelo->transformeObjeto(nome, transformacoes);
	modelo->updateWindow();
	view->updateWindow(window);
}

void MainController::setTamanhoWindow(double width, double height){
	window->setTamanhoWindow(width, height);
	modelo->updateWindow();
	view->updateWindow(window);
}

void MainController::addObjeto(ObjetoGeometrico* objeto) {
	modelo->addObjeto(objeto);
	view->updateWindow(window);
}

void MainController::moveWindow(int tipoMovimento) {
	switch (tipoMovimento) {
	case TipoMovimento::UP:
		window->move(0, 10);
		break;
	case TipoMovimento::LEFT:
		window->move(-10, 0);
		break;
	case TipoMovimento::DOWN:
		window->move(0, -10);
		break;
	case TipoMovimento::RIGHT:
		window->move(10, 0);
		break;
	case TipoMovimento::ZOOM_IN:
		window->zoom(-12);
		break;
	case TipoMovimento::ZOOM_OUT:
		window->zoom(12);
		break;
	}
	modelo->updateWindow();
	view->updateWindow(window);
}

MainController::~MainController() {
	delete modelo;
	delete view;
}

