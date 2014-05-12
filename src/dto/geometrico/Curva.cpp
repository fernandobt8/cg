/*
 * Curva.cpp
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#include "Curva.h"

Curva::Curva(char* nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas){
	bSpline = false;
	algoritmo = Curva::BLENDING_FUNCTION;
}

Curva::Curva(char* nome) : ObjetoGeometrico(nome){
	bSpline = false;
	algoritmo = Curva::BLENDING_FUNCTION;
}

void Curva::multiplyCoordenadasToCPP(Matriz* matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
	if(bSpline){
		this->bSplines();
	}else{
		this->bezier();
	}
}

void Curva::bezier(){
	list<Coordenada*>* newPontos = new list<Coordenada* >();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	bool primeiro = true;
	Matriz* bezier = new MatrizBezier();
	while(it._M_node != CPPcoordenadas->end()._M_node->_M_prev->_M_prev){
		Coordenada* p1 = *it;
		Coordenada* p2 = *++it;
		if(!primeiro)
			CoordenadaUtils::invertVector(p1, p2);
		Coordenada* p4 = *++it;
		Coordenada* p3 = *++it;
		primeiro = false;
		if(algoritmo == Curva::BLENDING_FUNCTION)
			Curva::gerarPontosBlendingFunction(newPontos, bezier, p1, p2, p3, p4);
		else
			Curva::gerarPontosForwardDifference(newPontos, bezier, p1, p2, p3, p4);
		it--;
	}
	delete bezier;
	this->setCPPCoordenadas(newPontos);
}

void Curva::bSplines(){
	list<Coordenada*>* newPontos = new list<Coordenada* >();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	Matriz* bSpline = new MatrizBSplines();
	while(it._M_node != CPPcoordenadas->end()._M_node->_M_prev->_M_prev->_M_prev){
		Coordenada* p1 = *it;
		Coordenada* p2 = *++it;
		Coordenada* p3 = *++it;
		Coordenada* p4 = *++it;
		if(algoritmo == Curva::BLENDING_FUNCTION)
			Curva::gerarPontosBlendingFunction(newPontos, bSpline, p1, p2, p3, p4);
		else
			Curva::gerarPontosForwardDifference(newPontos, bSpline, p1, p2, p3, p4);
		advance(it, -2);
	}
	delete bSpline;
	this->setCPPCoordenadas(newPontos);
}

void Curva::gerarPontosBlendingFunction(list<Coordenada*>* listCoordenads, Matriz* matrizTipoCurva, Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4){
	Matriz* matrizG = MatrizUtils::getMatrizGeometria(p1, p2, p3, p4);
	for(double t = 0; t < 1.00001; t += 0.05){
		Matriz* matrizT = new Matriz(t);
		matrizT->multiply( matrizTipoCurva);
		matrizT->multiply(matrizG);
		double** matrizR = matrizT->getMatriz();
		listCoordenads->push_back(new Coordenada(matrizR[0][0], matrizR[0][1], matrizR[0][2]));
		delete matrizT;
	}
}

void Curva::gerarPontosForwardDifference(list<Coordenada*>* listCoordenads, Matriz* matrizTipoCurva, Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4){
	Matriz* matrizDelta = new MatrizDelta(0.02);
	matrizDelta->multiply( matrizTipoCurva);
	Matriz* matrizG = MatrizUtils::getMatrizGeometria(p1, p2, p3, p4);
	matrizDelta->multiply(matrizG);
	double** matrizR = matrizDelta->getMatriz();
	listCoordenads->push_back(new Coordenada(matrizR[0][0], matrizR[0][1], matrizR[0][2]));
	for (int i = 0; i < 1.0/0.02; ++i) {
		//x's
		matrizR[0][0] = matrizR[0][0] + matrizR[1][0];
		matrizR[1][0] = matrizR[1][0] + matrizR[2][0];
		matrizR[2][0] = matrizR[2][0] + matrizR[3][0];
		//y's
		matrizR[0][1] = matrizR[0][1] + matrizR[1][1];
		matrizR[1][1] = matrizR[1][1] + matrizR[2][1];
		matrizR[2][1] = matrizR[2][1] + matrizR[3][1];
		//z's
		matrizR[0][2] = matrizR[0][2] + matrizR[1][2];
		matrizR[1][2] = matrizR[1][2] + matrizR[2][2];
		matrizR[2][2] = matrizR[2][2] + matrizR[3][2];
		listCoordenads->push_back(new Coordenada(matrizR[0][0], matrizR[0][1], matrizR[0][2]));
	}
	delete matrizG;
	delete matrizDelta;
}

Curva* Curva::clone(){
	Curva *curva = new Curva(Utils::cloneChar(nome));
	list<Coordenada* >* newList = new list<Coordenada*>();
	for(list<Coordenada*>::iterator it = CPPcoordenadas->begin(); it != CPPcoordenadas->end(); it++){
		newList->push_back((*it)->clone());
	}
	curva->setCPPCoordenadas(newList);
	return curva;
}

Curva::~Curva() {
}
