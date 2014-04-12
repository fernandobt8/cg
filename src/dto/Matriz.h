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

#include "geometrico/Coordenada.h"
#include "transformacao/Transformacao.h"
#include "transformacao/Rotacao.h"
#include "transformacao/Translacao.h"
#include "transformacao/Escalonamento.h"
#include <math.h>

#include <stdio.h>
#include <list>

using namespace std;
class Coordenada;

class Matriz {
public:
	Matriz(double** matriz, int numLinhas);
	Matriz(int numLinhas);
	virtual ~Matriz();
	void multiplique(Matriz* matriz);
	double** getMatriz();
	void printAll();
	static Matriz* getMatrizTransformacao(Coordenada* center, list<Transformacao* >* transformacoes);
	static Matriz* getMatrizByCoordenada(Coordenada* coordenada);
	static Matriz* getMatrizTranslacao(Translacao* translacao);
	static Matriz* getMatrizTranslacao(double x, double y);
	static Matriz* getMatrizRotacao(Coordenada* center, Rotacao* rotacao);
	static Matriz* getMatrizEscalonamento(Coordenada* center, Escalonamento* escalonamento);
	int numLinhas;

private:
	double** dado;
	void clear();
};

#endif /* MATRIZ_H_ */
