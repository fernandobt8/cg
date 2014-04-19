/*
 * Matriz.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Matriz.h"

Matriz::Matriz() {
	this->numLinhas = 3;
	this->initializeMatriz();
}

Matriz::Matriz(int numLinhas){
	this->numLinhas = numLinhas;
	this->initializeMatriz();
}

Matriz::Matriz(Coordenada* coordenada){
	this->numLinhas = 1;
	this->initializeMatriz();
	matriz[0][0] = coordenada->getX();
	matriz[0][1] = coordenada->getY();
	matriz[0][2] = 1;
}

void Matriz::initializeMatriz(){
	matriz = new double*[numLinhas];
	for(int i = 0; i < numLinhas; i++){
		matriz[i] = new double[numColunas];
	}
}

void Matriz::multiply(Matriz* matriz)  {
	double** resultado = new double*[numLinhas];
	for (int i = 0; i < numLinhas; i++) {
		resultado[i] = new double[numColunas];
		for (int j = 0; j < numColunas; j++) {
			resultado[i][j] = 0;
			for (int k = 0; k < numColunas; k++) {
				resultado[i][j] = resultado[i][j] + (this->matriz[i][k] * matriz->getMatriz()[k][j]);
			}
		}
	}
	this->clearMatriz();
	this->matriz = resultado;
}

void Matriz::printAll(){
	 for (int i=0; i<numLinhas; i++) {
	  for (int j=0; j<numColunas; j++) {
		printf("%f ", matriz[i][j]);
	  }
	  printf("\n");
	}
}

double** Matriz::getMatriz() {
	return matriz;
}

void Matriz::clearMatriz(){
	for(int i = 0; i < numLinhas; i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}

Matriz::~Matriz() {
	this->clearMatriz();
}
