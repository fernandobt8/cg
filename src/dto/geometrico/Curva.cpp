/*
 * Curva.cpp
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#include "Curva.h"

Curva::Curva(char* nome) : ObjetoGeometrico(nome){

}

void Curva::multiplyCoordenadasToCPP(Matriz* matriz){
	ObjetoGeometrico::multiplyCoordenadasToCPP(matriz);
	//atualizar cpp com pontos gerados pela equaçoes parametricas
}

Curva::~Curva() {
}
