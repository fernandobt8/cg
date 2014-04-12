/*
 * ModeloInterno.h
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#ifndef MODELOINTERNO_H_
#define MODELOINTERNO_H_

#include "../dto/geometrico/ObjetoGeometrico.h"
#include "../dto/transformacao/Transformacao.h"
#include "../dto/transformacao/Rotacao.h"
#include "../dto/transformacao/Translacao.h"
#include "../dto/Matriz.h"
#include "window/Window.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class ModeloInterno {
public:
	ModeloInterno();
	virtual ~ModeloInterno();
	void updateCPPcoordenadas();
	void updateWindowCoordenadas();
	void addObjeto(ObjetoGeometrico *objeto);
	void transformeObjeto(char* nome, list<Transformacao* >* transformacoes);
	void setTamanhoWindow(double width, double height);
	void moveWindow(double x, double y);
	void zoomWindow(double value);
	void printAll();
	class Window* window;

private:
	list<ObjetoGeometrico*> *objetos;
};

#endif /* MODELOINTERNO_H_ */
