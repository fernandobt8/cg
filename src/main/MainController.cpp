/*
 * MainController.cpp
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#include "MainController.h"

MainController::MainController() {
	modelo = new ModeloInterno();
	this->view = new MainView(this);
	view->show();
}

void MainController::rotacioneWindow(double angulo){
	modelo->rotacioneWindow(angulo);
	view->updateWindow(modelo->window);
}

void MainController::transformeObjeto(char* nome, list<Transformacao*>* transformacoes){
	modelo->transformeObjeto(nome, transformacoes);
	view->updateWindow(modelo->window);
}

void MainController::setTamanhoWindow(double width, double height){
	modelo->setTamanhoWindow(width, height);
	view->updateWindow(modelo->window);
}

void MainController::addObjeto(ObjetoGeometrico* objeto) {
	modelo->addObjeto(objeto);
	view->updateWindow(modelo->window);
}

void MainController::moveWindow(int tipoMovimento) {
	switch (tipoMovimento) {
	case TipoMovimento::UP:
		modelo->moveWindow(0, 10);
		break;
	case TipoMovimento::LEFT:
		modelo->moveWindow(-10, 0);
		break;
	case TipoMovimento::DOWN:
		modelo->moveWindow(0, -10);
		break;
	case TipoMovimento::RIGHT:
		modelo->moveWindow(10, 0);
		break;
	case TipoMovimento::ZOOM_IN:
		modelo->zoomWindow(0.9);
		break;
	case TipoMovimento::ZOOM_OUT:
		modelo->zoomWindow(1.1);
		break;
	}
	view->updateWindow(modelo->window);
}

MainController::~MainController() {
	delete modelo;
	delete view;
}

