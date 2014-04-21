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
#include "../dto/geometrico/Reta.h"
#include <stdio.h>

using namespace std;

class Clipping {
public:
	Clipping(Window *window, list<ObjetoGeometrico*> *objetos);
	virtual ~Clipping();
	void clip();
	void clippingPonto(Ponto* ponto);
	void clippingReta(Reta* reta);
	Window *window;
	list<ObjetoGeometrico*> *objetos;
	list<ObjetoGeometrico*> *novaLista;
	void verificarQuadrante(Coordenada *coordenada, bool* RC);
	Coordenada* retaParcial(bool* RC,Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *novaCoordenada);
};

#endif /* CLIPPINGPONTO_H_ */
