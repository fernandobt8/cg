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
			Utils::gerarPontosBlendingFunction(newPontos, bezier, p1, p2, p3, p4);
		else
			Utils::gerarPontosForwardDifference(newPontos, bezier, p1, p2, p3, p4);
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
			Utils::gerarPontosBlendingFunction(newPontos, bSpline, p1, p2, p3, p4);
		else
			Utils::gerarPontosForwardDifference(newPontos, bSpline, p1, p2, p3, p4);
		advance(it, -2);
	}
	delete bSpline;
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
