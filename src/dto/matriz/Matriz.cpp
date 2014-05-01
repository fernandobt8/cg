/*
 * Matriz.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Matriz.h"

Matriz::Matriz() {
	this->numLinhas = 3;
	this->numColunas = 3;
	matriz = new double*[numLinhas];
	this->initializeMatriz();
}

Matriz::Matriz(int numLinhas, int numColunas) {
	this->numLinhas = numLinhas;
	this->numColunas = numColunas;
	matriz = new double*[numLinhas];
	this->initializeMatriz();
}

Matriz::Matriz(double t){
	this->numColunas = 1;
	this->numLinhas = 4;
	matriz = new double*[numLinhas];
	this->initializeMatriz();
	matriz[0][0] = pow(t, 3);
	matriz[1][0] = pow(t, 2);
	matriz[2][0] = t;
	matriz[3][0] = 1;
}

Matriz::Matriz(Coordenada* coordenada){
	this->numLinhas = 1;
	this->numColunas = 3;
	matriz = new double*[numLinhas];
	this->initializeMatriz();
	matriz[0][0] = coordenada->getX();
	matriz[0][1] = coordenada->getY();
	matriz[0][2] = 1;
}

void Matriz::initializeMatriz(){
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
		delete matriz[i];
	}
	delete matriz;
}

void Matriz::printAll(){
	for (int i=0; i<numLinhas; i++) {
	  for (int j=0; j<numColunas; j++) {
		printf("%f ", matriz[i][j]);
	  }
	  printf("\n");
	}
}

Matriz::~Matriz() {
	this->clearMatriz();
}
