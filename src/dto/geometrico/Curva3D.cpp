/*
 * Curva3D.cpp
 *
 *  Created on: 24/05/2014
 *      Author: fernandobt8
 */

#include "Curva3D.h"

Curva3D::Curva3D(char* nome, list<Coordenada* >* coordenadas) : ObjetoGeometrico(nome, coordenadas){

}

void Curva3D::multiplyCoordenadasToCPP(Matriz* matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
	//list<list<Coordenada*>*>* newPontos = new list<list<Coordenada*>*>();
	list<Coordenada*>* newPontos = new list<Coordenada* >();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	advance(it, 8);
	Matriz* bezier = new MatrizBezier();
	Matriz* bezierT = new MatrizBezier();
	bezierT->invert();
	while(it != CPPcoordenadas->end()){
		advance(it, -8);
		Matriz* gX = MatrizUtils::getMatrizGeometria(it, CoordenadaUtils::returnX);
		Matriz* gY = MatrizUtils::getMatrizGeometria(it, CoordenadaUtils::returnY);
		Matriz* gZ = MatrizUtils::getMatrizGeometria(it, CoordenadaUtils::returnZ);
		Matriz* S = MatrizUtils::getMatrizCoeficienteLinha(0);
		Matriz* T = MatrizUtils::getMatrizCoeficienteLinha(0);
		T->invert();

		S->multiply(bezier);
		S->multiply(gX);
		S->multiply(bezierT);
		S->multiply(T);
		S->printAll();
		advance(it, 16);
	}
}

Curva3D::~Curva3D() {
	// TODO Auto-generated destructor stub
}

