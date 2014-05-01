/*
 * Curva.cpp
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#include "Curva.h"

Curva::Curva(char* nome) : ObjetoGeometrico(nome){

}

void Curva::multiplyCoordenadasToCPP(Matriz matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
	list<Coordenada*>* newPontos = new list<Coordenada* >();
	list<Coordenada*>::iterator it = CPPcoordenadas->begin();
	while(it != CPPcoordenadas->end()){
		Coordenada* p1 =*it;
		Coordenada* r1 = *++it;
		Coordenada* p4 = *++it;
		Coordenada* r4 = *++it;
		for(double t = 0.01; t < 1; t += 0.01){

		}
	}
}

Curva::~Curva() {
}
