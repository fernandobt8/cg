/*
 * Matriz.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#include "../geometrico/Coordenada.h"
#include <math.h>
#include <stdio.h>

using namespace std;
class Coordenada;

class Matriz {
public:
	Matriz();
	Matriz(int numLinhas, int numColunas);
	Matriz(Coordenada* coordenada);
	virtual ~Matriz();
	void multiply(Matriz* matriz);
	void invert();
	double** getMatriz();
	void printAll();
	Matriz* clone();

protected:
	int numLinhas;
	int numColunas;
	double** matriz;
	void initializeMatriz();
	void clearMatriz();
};

#endif /* MATRIZ_H_ */
