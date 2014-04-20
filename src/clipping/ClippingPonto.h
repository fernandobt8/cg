/*
 * ClippingPonto.h
 *
 *  Created on: 20/04/2014
 *      Author: alisson
 */

#ifndef CLIPPINGPONTO_H_
#define CLIPPINGPONTO_H_

#include <list>
#include "../modelo.interno/window/Window.h"
#include "../dto/geometrico/Ponto.h"
#include <stdio.h>

using namespace std;

class ClippingPonto {
public:
	ClippingPonto();
	virtual ~ClippingPonto();
	void clip(Window *window, list<ObjetoGeometrico*> *objetos);
};

#endif /* CLIPPINGPONTO_H_ */
