/*
 * MainController.h
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_
#include "window/Window.h"
#include "modelo.interno/ModeloInterno.h"
#include "MainView.h"
#include "../dto/ObjetoGeometrico.h"
#include "TipoMovimento.h"

class MainController {
public:
	MainController();
	virtual ~MainController();
	void addObjeto(ObjetoGeometrico* objeto);
	void moveWindow(int tipoMovimento);
	void setTamanhoWindow(double width, double height);
private:
	Window* window;
	ModeloInterno* modelo;
	class MainView* view;
};

#endif /* MAINCONTROLLER_H_ */
