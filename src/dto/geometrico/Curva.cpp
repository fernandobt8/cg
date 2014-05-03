/*
 * Curva.cpp
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#include "Curva.h"

Curva::Curva(char* nome, list<Coordenada*>* coordenadas) : ObjetoGeometrico(nome, coordenadas){
	BSplines = false;
}

Curva::Curva(char* nome) : ObjetoGeometrico(nome){
	BSplines = false;
}

void Curva::multiplyCoordenadasToCPP(Matriz* matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
	if(BSplines){
		this->forwardDifferences();
	}else{
		this->blendingFunction();
	}
}

void Curva::blendingFunction(){
	list<Coordenada*>* newPontos = new list<Coordenada* >();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	bool primeiro = true;
	while(it._M_node != CPPcoordenadas->end()._M_node->_M_prev->_M_prev){
		Coordenada* p1 = *it;
		Coordenada* p2 = *++it;
		if(!primeiro)
			CoordenadaUtils::invertVector(p1, p2);
		Coordenada* p4 = *++it;
		Coordenada* p3 = *++it;
		primeiro = false;
		Matriz* matrizG = MatrizUtils::getMatrizGeometria(p1, p2, p3, p4);
		for(double t = 0; t < 1.00001; t += 0.05){
			Matriz* matrizBF = MatrizUtils::getMatrizBlendingFunction(t);
			matrizBF->multiply(matrizG);
			newPontos->push_back(new Coordenada(matrizBF->getMatriz()[0][0], matrizBF->getMatriz()[0][1]));
			delete matrizBF;
		}
		it--;
		delete matrizG;
	}
	this->setCPPCoordenadas(newPontos);
}

void Curva::forwardDifferences(){
	list<Coordenada*>* newPontos = new list<Coordenada* >();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	while(it._M_node != CPPcoordenadas->end()._M_node->_M_prev->_M_prev->_M_prev){
		Coordenada* p1 = *it;
		Coordenada* p2 = *++it;
		Coordenada* p3 = *++it;
		Coordenada* p4 = *++it;
		Matriz* matrizDelta = new MatrizDelta(0.02);
		Matriz* matrizBS = new MatrizBSplines();
		Matriz* matrizG = MatrizUtils::getMatrizGeometria(p1, p2, p3, p4);
		matrizDelta->multiply(matrizBS);
		matrizDelta->multiply(matrizG);
		double** matrizR = matrizDelta->getMatriz();
		newPontos->push_back(new Coordenada(matrizR[0][0], matrizR[0][1]));
		for (int i = 0; i < 1.0/0.02; ++i) {
			//x's
			matrizR[0][0] = matrizR[0][0] + matrizR[1][0];
			matrizR[1][0] = matrizR[1][0] + matrizR[2][0];
			matrizR[2][0] = matrizR[2][0] + matrizR[3][0];
			//y's
			matrizR[0][1] = matrizR[0][1] + matrizR[1][1];
			matrizR[1][1] = matrizR[1][1] + matrizR[2][1];
			matrizR[2][1] = matrizR[2][1] + matrizR[3][1];
			newPontos->push_back(new Coordenada(matrizR[0][0], matrizR[0][1]));
		}
		delete matrizG;
		delete matrizBS;
		delete matrizDelta;
		advance(it, -2);
	}
	this->setCPPCoordenadas(newPontos);
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
