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
	void clippingPonto(Ponto* ponto);
	bool verificarPonto(double x, double y);
	void clippingReta(Reta* reta);
	void clippingPoligonoAberto(Poligono* poligono);
	void clippingPoligonoFechado(Poligono* poligono);
	void preencherListas(list<Coordenada*> *windowVertices,	list<Coordenada*> *poligonoVertices, Poligono* poligono);
	void verificarInterseccaoWindow(Coordenada* atual, list<Coordenada*> *windowVertices);
	bool clippingLine(Coordenada* inicial, Coordenada* final);
	void verificarQuadrante(Coordenada *coordenada, bool* RC);
	bool clippingCoordenada(bool* RC,Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *novaCoordenada);
	void percorrerListaPoligono();
	void percorrerListaWindow();
};

#endif /* CLIPPINGPONTO_H_ */