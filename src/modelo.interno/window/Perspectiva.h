/*
 * Perspectiva.h
 *
 *  Created on: 20/05/2014
 *      Author: alisson
 */

#ifndef PERSPECTIVA_H_
#define PERSPECTIVA_H_

#include "Window.h"
#include "../../dto/geometrico/Coordenada.h"
#include "../../dto/geometrico/ObjetoGeometrico.h"

class Perspectiva {
public:
	Perspectiva();
	virtual ~Perspectiva();
	double projetar(Coordenada *cop, Window *window);
	void transladeOrigem(Coordenada *cop, Window* window);
	void transladeBack(Coordenada *cop, Window *window);
	void alinharPlanoZ(Window *window);
	void alinharPlanoXY(Window *window);
	void projetarObjeto(ObjetoGeometrico* objeto);
	void normalizar(Coordenada *cop, Window *window);

private:
	double d, anguloX, anguloY;
};

#endif /* PERSPECTIVA_H_ */
