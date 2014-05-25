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
	tipoCuva = SPLINES;
}

void Curva3D::multiplyCoordenadasToCPP(Matriz* matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
	this->clearPontos();
	if(tipoCuva == Curva3D::BEZIER){
		this->bezier();
	}else if(tipoCuva == Curva3D::SPLINES){
		this->splines();
	}
}

void Curva3D::bezier(){
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	advance(it, 8);
	Matriz* bezier = new MatrizBezier();
	bool first = true;
	while(it != CPPcoordenadas->end()){
		advance(it, -8);
		if(!first){
			this->invertPontosControle(it);
		}
		Matriz* gX = MatrizUtils::getMatrizGeometriaBezier(it, CoordenadaUtils::returnX);
		Matriz* gY = MatrizUtils::getMatrizGeometriaBezier(it, CoordenadaUtils::returnY);
		Matriz* gZ = MatrizUtils::getMatrizGeometriaBezier(it, CoordenadaUtils::returnZ);
		this->blendingFunction(bezier, gX, gY, gZ);
		delete gX;
		delete gY;
		delete gZ;
		first = false;
		advance(it, 16);
	}
	delete bezier;
}

void Curva3D::splines(){
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	advance(it, 12);
	Matriz* splines = new MatrizBSplines();
	while(it != CPPcoordenadas->end()){
		advance(it, -12);
		Matriz* gX = MatrizUtils::getMatrizGeometriaSplines(it, CoordenadaUtils::returnX);
		Matriz* gY = MatrizUtils::getMatrizGeometriaSplines(it, CoordenadaUtils::returnY);
		Matriz* gZ = MatrizUtils::getMatrizGeometriaSplines(it, CoordenadaUtils::returnZ);
		this->blendingFunction(splines, gX, gY, gZ);
		delete gX;
		delete gY;
		delete gZ;
		advance(it, 16);
	}
	delete splines;
}

void Curva3D::blendingFunction(Matriz* M, Matriz* gX, Matriz* gY, Matriz* gZ){
	Matriz* MT = M->clone();
	MT->invert();
	for(double t = 0; t < 1.00001; t += 0.05){
		list<Coordenada* >* pontos = new list<Coordenada*>();
		Matriz* matrizT = MatrizUtils::getMatrizCoeficienteLinha(t);
		matrizT->invert();
		for(double s = 0; s < 1.00001; s += 0.05){
			Matriz* matrizSX = this->getMatrizS(s, M, gX, MT);
			Matriz* matrizSY = this->getMatrizS(s, M, gY, MT);
			Matriz* matrizSZ = this->getMatrizS(s, M, gZ, MT);
			matrizSX->multiply(matrizT);
			matrizSY->multiply(matrizT);
			matrizSZ->multiply(matrizT);
			pontos->push_back(new Coordenada(matrizSX->getMatriz()[0][0],
					matrizSY->getMatriz()[0][0], matrizSZ->getMatriz()[0][0]));
			delete matrizSX;
			delete matrizSY;
			delete matrizSZ;
		}
		delete matrizT;
		pontosInS->push_back(pontos);
	}
	for(double s = 0; s < 1.00001; s += 0.05){
		list<Coordenada* >* pontos = new list<Coordenada*>();
		Matriz* matrizSX = this->getMatrizS(s, M, gX, MT);
		Matriz* matrizSY = this->getMatrizS(s, M, gY, MT);
		Matriz* matrizSZ = this->getMatrizS(s, M, gZ, MT);
		for(double t = 0; t < 1.00001; t += 0.05){
			Matriz* matrizSXC = matrizSX->clone();
			Matriz* matrizSYC = matrizSY->clone();
			Matriz* matrizSZC = matrizSZ->clone();
			Matriz* matrizT = MatrizUtils::getMatrizCoeficienteLinha(t);
			matrizT->invert();
			matrizSXC->multiply(matrizT);
			matrizSYC->multiply(matrizT);
			matrizSZC->multiply(matrizT);
			pontos->push_back(new Coordenada(matrizSXC->getMatriz()[0][0],
					matrizSYC->getMatriz()[0][0], matrizSZC->getMatriz()[0][0]));
			delete matrizSXC;
			delete matrizSYC;
			delete matrizSZC;
			delete matrizT;
		}
		delete matrizSX;
		delete matrizSY;
		delete matrizSZ;
		pontosInT->push_back(pontos);
	}

}

Matriz* Curva3D::getMatrizS(double s, Matriz* m, Matriz* g, Matriz* mT){
	Matriz* matrizS = MatrizUtils::getMatrizCoeficienteLinha(s);
	matrizS->multiply(m);
	matrizS->multiply(g);
	matrizS->multiply(mT);
	return matrizS;
}

void Curva3D::invertPontosControle(_List_iterator<Coordenada*> it){
	it--;
	for(int i = 0; i < 4; i++){
		Coordenada* c = *++it;
		CoordenadaUtils::invertVector(c, (*++it));
	}
}

void Curva3D::clearPontos(){
	list<list<Coordenada*>*>::iterator itS = pontosInS->begin();
	for( ; itS != pontosInS->end(); itS++){
		ListUtils::destroyList((*itS));
	}
	delete pontosInS;
	pontosInS = new list<list<Coordenada*>*>();
	list<list<Coordenada*>*>::iterator itT = pontosInT->begin();
	for( ; itT != pontosInT->end(); itT++){
		ListUtils::destroyList((*itT));
	}
	delete pontosInT;
	pontosInT = new list<list<Coordenada*>*>();
}

list<list<Coordenada*>*>* Curva3D::getPontosInS(){
	return pontosInS;
}

list<list<Coordenada*>*>* Curva3D::getPontosInT(){
	return pontosInT;
}

Curva3D::~Curva3D() {
}

