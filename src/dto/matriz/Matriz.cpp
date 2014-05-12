/*
 * Matriz.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Matriz.h"

Matriz::Matriz() {
	this->numLinhas = 4;
	this->numColunas = 4;
	this->initializeMatriz();
}

Matriz::Matriz(int numLinhas, int numColunas) {
	this->numLinhas = numLinhas;
	this->numColunas = numColunas;
	this->initializeMatriz();
}

Matriz::Matriz(double t){
	this->numColunas = 4;
	this->numLinhas = 1;
	this->initializeMatriz();
	matriz[0][0] = pow(t, 3);
	matriz[0][1] = pow(t, 2);
	matriz[0][2] = t;
	matriz[0][3] = 1;
}

Matriz::Matriz(Coordenada* coordenada){
	this->numLinhas = 1;
	this->numColunas = 4;
	this->initializeMatriz();
	matriz[0][0] = coordenada->getX();
	matriz[0][1] = coordenada->getY();
	matriz[0][2] = coordenada->getZ();
	matriz[0][3] = 1;
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
		resultado[i] = new double[matriz->numColunas];
		for (int j = 0; j < matriz->numColunas; j++) {
			resultado[i][j] = 0;
			for (int k = 0; k < numColunas; k++) {
				resultado[i][j] = resultado[i][j] + (this->matriz[i][k] * matriz->getMatriz()[k][j]);
			}
		}
	}
	this->clearMatriz();
	this->numColunas = matriz->numColunas;
	this->matriz = resultado;
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

void Matriz::printAll(){
	for (int i=0; i<numLinhas; i++) {
	  for (int j=0; j<numColunas; j++) {
		printf("%f ", matriz[i][j]);
	  }
	  printf("\n");
	}
	printf("\n");
}

Matriz::~Matriz() {
	this->clearMatriz();
}
