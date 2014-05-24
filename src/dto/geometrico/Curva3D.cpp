/*
 * Curva3D.cpp
 *
 *  Created on: 24/05/2014
 *      Author: fernandobt8
 */

#include "Curva3D.h"

Curva3D::Curva3D(char* nome, list<Coordenada* >* coordenadas) : ObjetoGeometrico(nome, coordenadas){
	pontosInS = new list<list<Coordenada*>*>();
	pontosInT = new list<list<Coordenada*>*>();
}

void Curva3D::multiplyCoordenadasToCPP(Matriz* matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
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
		for(double t = 0; t < 1.00001; t += 0.05){
			list<Coordenada* >* pontos = new list<Coordenada*>();
			Matriz* matrizT = MatrizUtils::getMatrizCoeficienteLinha(t);
			matrizT->invert();
			for(double s = 0; s < 1.00001; s += 0.05){
				Matriz* matrizSX = this->getMatriz(s, bezier, gX, bezierT);
				Matriz* matrizSY = this->getMatriz(s, bezier, gY, bezierT);
				Matriz* matrizSZ = this->getMatriz(s, bezier, gZ, bezierT);
				matrizSX->multiply(matrizT);
				matrizSY->multiply(matrizT);
				matrizSZ->multiply(matrizT);
				pontos->push_back(new Coordenada(matrizSX->getMatriz()[0][0], matrizSY->getMatriz()[0][0], matrizSZ->getMatriz()[0][0]));
			}
			pontosInS->push_back(pontos);
		}
		for(double s = 0; s < 1.00001; s += 0.05){
			list<Coordenada* >* pontos = new list<Coordenada*>();
			Matriz* matrizSX = this->getMatriz(s, bezier, gX, bezierT);
			Matriz* matrizSY = this->getMatriz(s, bezier, gY, bezierT);
			Matriz* matrizSZ = this->getMatriz(s, bezier, gZ, bezierT);
			for(double t = 0; t < 1.00001; t += 0.05){
				Matriz* matrizT = MatrizUtils::getMatrizCoeficienteLinha(t);
				matrizT->invert();
				matrizSX->multiply(matrizT);
				matrizSY->multiply(matrizT);
				matrizSZ->multiply(matrizT);
				pontos->push_back(new Coordenada(matrizSX->getMatriz()[0][0], matrizSY->getMatriz()[0][0], matrizSZ->getMatriz()[0][0]));
			}
			pontosInT->push_back(pontos);
		}
		advance(it, 16);
	}
}

Matriz* Curva3D::getMatriz(double s, Matriz* m, Matriz* g, Matriz* mT){
	Matriz* matrizS = MatrizUtils::getMatrizCoeficienteLinha(s);
	matrizS->multiply(m);
	matrizS->multiply(g);
	matrizS->multiply(mT);
	return matrizS;
}

list<list<Coordenada*>*>* Curva3D::getPontosInS(){
	return pontosInS;
}

list<list<Coordenada*>*>* Curva3D::getPontosInT(){
	return pontosInT;
}

Curva3D::~Curva3D() {
	// TODO Auto-generated destructor stub
}

