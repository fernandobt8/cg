/*
 * MainController.h
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_
#include "../modelo.interno/window/Window.h"
#include "../modelo.interno/ModeloInterno.h"
#include "MainView.h"
#include "../dto/geometrico/ObjetoGeometrico.h"
#include "TipoMovimento.h"
#include "../dto/transformacao/Transformacao.h"

class MainController {
public:
	MainController();
	virtual ~MainController();
	void addObjeto(ObjetoGeometrico* objeto);
	void moveWindow(int tipoMovimento);
	void setTamanhoWindow(double width, double height);
	void transformeObjeto(char* nome, list<Transformacao* >* transformacoes);
	void rotacioneWindow(double angulo);

private:
	ModeloInterno* modelo;
	class MainView* view;
};

#endif /* MAINCONTROLLER_H_ */
