/*
 * Matriz.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_
#include <list>

using namespace std;

class Matriz {
public:
	Matriz(double** matriz, int numLinhas);
	virtual ~Matriz();
	Matriz* operator*(Matriz* matriz);
	double** getMatriz();

private:
	double** dado;
	int numLinhas;
};

#endif /* MATRIZ_H_ */
