/*
 * Matriz.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Matriz.h"
int numColunas = 3;

Matriz::Matriz(double** matriz, int numLinhas) {
	dado = matriz;
	this->numLinhas = numLinhas;
}

Matriz* Matriz::operator*(Matriz* matriz) {
	double** dado2 = matriz->getMatriz();
	double** dado3 = new double*[numColunas];
	for (int i = 0; i < numLinhas; i++) {
		for (int j = 0; j < numColunas; j++) {
			dado3 = new double[numLinhas];
			for (int k = 0; k < numColunas; k++) {
				dado3[i][j] = dado3[i][j] + (dado[i][k] * dado2[k][j]);
			}
		}
	}
	return new Matriz(dado3);
}

double** Matriz::getMatriz() {
	return dado;
}

Matriz::~Matriz() {

}

