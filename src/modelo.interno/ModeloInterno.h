/*
 * ModeloInterno.h
 *
 *  Created on: 26/03/2014
 *      Author: alisson
 */

#ifndef MODELOINTERNO_H_
#define MODELOINTERNO_H_

#include "../dto/geometrico/ObjetoGeometrico.h"
#include "../dto/matriz/Matriz.h"
#include "../dto/matriz/MatrizRotacao.h"
#include "../dto/matriz/MatrizTranslacao.h"
#include "../utils/Utils.h"
#include "window/Window.h"
#include "../clipping/Clipping.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

class ModeloInterno {
public:
	ModeloInterno();
	virtual ~ModeloInterno();
	void addObjeto(ObjetoGeometrico *objeto);
	void transformeObjeto(char* nome, list<Transformacao* >* transformacoes);
	void setTamanhoWindow(double width, double height);
	void rotacioneWindow(double angulo);
	void moveWindow(double x, double y);
	void zoomWindow(double zoomX, double zoomY);
	void printAll();
	list<ObjetoGeometrico*>* getObjetos();
	class Window* window;

private:
	Clipping* clipping;
	list<ObjetoGeometrico*> *objetos;
	Matriz* getMatrizToWorldCoordinates();
	void updateCPPCoordenadas();

};

#endif /* MODELOINTERNO_H_ */
