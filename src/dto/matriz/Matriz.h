/*
 * Matriz.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

#define PI 3.14159265
#define numColunas 3
#include "../geometrico/Coordenada.h"
#include <math.h>
#include <stdio.h>

using namespace std;
class Coordenada;

class Matriz {
public:
	Matriz();
	Matriz(int numLinhas);
	Matriz(Coordenada* coordenada);
	virtual ~Matriz();
	void multiply(Matriz* matriz);
	double** getMatriz();
	void printAll();

protected:
	int numLinhas;
	double** matriz;
	void initializeMatriz();
	void clearMatriz();
};

#endif /* MATRIZ_H_ */
