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
#include <stdio.h>
#include "../utils/Utils.h"

#define acima 0
#define abaixo 1
#define direita 2
#define esquerda 3

using namespace std;

class Clipping {
public:
	Clipping(Window *window);
	virtual ~Clipping();
	void clip(ObjetoGeometrico* objeto);

private:
	Window *window;
	bool verificarPonto(double x, double y);

	void clippingReta(Reta* reta);
	void clippingPonto(Ponto* ponto);
	void clippingPoligonoAberto(Poligono* poligono);
	void clippingPoligonoFechado(Poligono* poligono);

	bool clippingLine(Coordenada* inicial, Coordenada* final);
	bool clippingCoordenada(bool* RC,Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *novaCoordenada);
	void verificarQuadrante(Coordenada *coordenada, bool* RC);

	list<Coordenada*>* preencherPoligonoLista(Poligono* poligono);
	list<Coordenada*>* preencherWindowLista(Poligono* poligono, list<Coordenada*>* poligonoVertices);
	void percorrerListaPoligono(list<Coordenada*> *poligonoVertices, list<Coordenada*> *windowVertices, list<Coordenada*> *novosVertices, int index);
	void percorrerListaWindow(list<Coordenada*> *poligonoVertices, list<Coordenada*> *windowVertices, list<Coordenada*> *novosVertices, int index);
};

#endif /* CLIPPINGPONTO_H_ */
