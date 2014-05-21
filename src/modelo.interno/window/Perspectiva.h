/*
 * Perspectiva.h
 *
 *  Created on: 20/05/2014
 *      Author: alisson
 */

#ifndef PERSPECTIVA_H_
#define PERSPECTIVA_H_

#include "Window.h"
#include "../../dto/geometrico/ObjetoGeometrico.h"

class Perspectiva {
public:
	Perspectiva(Window *window);
	virtual ~Perspectiva();
	void projetarObjeto(ObjetoGeometrico* objeto);
	Matriz* getMatrizTranslacao();
private:
	Window *window;
	double d;
};

#endif /* PERSPECTIVA_H_ */
