/*
 * Curva.h
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#ifndef CURVA_H_
#define CURVA_H_
#include "ObjetoGeometrico.h"
#include "../../utils/MatrizUtils.h"
#include "../../utils/Utils.h"
#include "../../utils/CoordenadaUtils.h"

class Curva : public ObjetoGeometrico{
public:
	enum Desenhe{
		BLENDING_FUNCTION,
		FORWARD_DIFFERENCE,
	};
	Curva(char* nome, list<Coordenada*>* coordenadas);
	Curva(char* nome);
	virtual ~Curva();
	void multiplyCoordenadasToCPP(Matriz* matriz);
	Curva* clone();
	bool bSpline;
	Curva::Desenhe algoritmo;
	void gerarPontosBlendingFunction(list<Coordenada*>* listCoordenads, Matriz* matrizTipoCurva, Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4);
	void gerarPontosForwardDifference(list<Coordenada*>* listCoordenads, Matriz* matrizTipoCurva, Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4);
private:
	void bezier();
	void bSplines();

};

#endif /* CURVA_H_ */
