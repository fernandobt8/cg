#ifndef COORDENADAUTILS_H_
#define COORDENADAUTILS_H_
#include "../clipping/Quadrante.h"
#include <vector>

using namespace std;

class CoordenadaUtils{
public:
	static bool isVisitado(Coordenada* coordenada){
		return !coordenada->isVisitado();
	}

	static bool compareEqualYAndIsInterseccao(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getY() == coordenada2->getY() && coordenada2->isInterseccao();
	}

	static bool compareEqualXAndIsInterseccao(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getX() == coordenada2->getX() && coordenada2->isInterseccao();
	}

	static bool compareMenorY(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getY() < coordenada2->getY();
	}

	static bool compareMenorX(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getX() < coordenada2->getX();
	}

	static bool compareMaiorY(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getY() > coordenada2->getY();
	}

	static bool compareMaiorX(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getX() > coordenada2->getX();
	}

	static bool clippingCoordenada(vector<bool> RC, Coordenada *coordenadaInicial, Coordenada* coordenadaFinal, Coordenada *clippingCoordenada, Window* window){
		double m = (coordenadaFinal->getY() - coordenadaInicial->getY()) / (coordenadaFinal->getX() - coordenadaInicial->getX());
		bool clipping = false;
		if (RC[Quadrante::acima]) {
			double xCima = coordenadaInicial->getX() + 1 / m * (window->CPPend->getY() - coordenadaInicial->getY());
			if (Utils::isBetweenValues(window->CPPstart->getX(), window->CPPend->getX(), xCima)) {
				clippingCoordenada->setX(xCima);
				clippingCoordenada->setY(window->CPPend->getY());
				clipping = true;
			}
		}
		if (RC[Quadrante::abaixo]) {
			double xBaixo = coordenadaInicial->getX() + 1 / m * (window->CPPstart->getY() - coordenadaInicial->getY());
			if (Utils::isBetweenValues(window->CPPstart->getX(), window->CPPend->getX(), xBaixo)) {
				clippingCoordenada->setY(window->CPPstart->getY());
				clippingCoordenada->setX(xBaixo);
				clipping = true;
			}
		}
		if (RC[Quadrante::direita]) {
			double yDireita = m * (window->CPPend->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY();
			if (Utils::isBetweenValues(window->CPPstart->getY(), window->CPPend->getY(), yDireita)) {
				clippingCoordenada->setX(window->CPPend->getX());
				clippingCoordenada->setY(yDireita);
				clipping = true;
			}
		}
		if (RC[Quadrante::esquerda]) {
			double yEsquerda = m * (window->CPPstart->getX() - coordenadaInicial->getX()) + coordenadaInicial->getY();
			if (Utils::isBetweenValues(window->CPPstart->getY(), window->CPPend->getY(), yEsquerda)) {
				clippingCoordenada->setX(window->CPPstart->getX());
				clippingCoordenada->setY(yEsquerda);
				clipping = true;
			}
		}
		return clipping;
	}

	static vector<bool> verificarQuadranteCoordenada(Coordenada* coordenada, Window* window) {
		vector<bool> RC (4, false);
		if (coordenada->getY() > window->CPPend->getY())
			RC[Quadrante::acima] = true;
		if (coordenada->getY() < window->CPPstart->getY()) {
			RC[Quadrante::abaixo] = true;
		}
		if (coordenada->getX() > window->CPPend->getX()) {
			RC[Quadrante::direita] = true;
		}
		if (coordenada->getX() < window->CPPstart->getX()) {
			RC[Quadrante::esquerda] = true;
		}
		return RC;
	}
};
#endif
