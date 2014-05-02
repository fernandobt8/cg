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
#include "../dto/geometrico/Poligono.h"
#include "../dto/geometrico/Curva.h"
#include <stdio.h>
#include "../utils/Utils.h"
#include "../utils/ListUtils.h"
#include "../utils/CoordenadaUtils.h"
#include "Quadrante.h"

using namespace std;

class Clipping {
public:
	Clipping(Window *window);
	virtual ~Clipping();
	void clip(ObjetoGeometrico* objeto);

private:
	Window *window;

	void clippingReta(Reta* reta);
	void clippingPonto(Ponto* ponto);
	void clippingPoligonoAberto(Poligono* poligono);
	void clippingPoligonoFechado(Poligono* poligono);
	void clippingCurva(Curva *curva);

	bool clippingLine(Coordenada* inicial, Coordenada* final);
	template<typename Equals, typename Sort>
	void addListToList(list<Coordenada* >* poligonoVertices, list<Coordenada*>* windowVertices, Coordenada* coordenada, Equals equals, Sort sort);

	list<Coordenada*>* getPoligonoLista(Poligono* poligono);
	list<Coordenada*>* getWindowLista(list<Coordenada*>* poligonoVertices);
	void percorrerLista(list<Coordenada* >* followList, list<Coordenada*>* goList, list<Coordenada*>* novaLista,  _List_iterator<Coordenada*> iterator);
};

#endif /* CLIPPINGPONTO_H_ */
