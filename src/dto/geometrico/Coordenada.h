/*
 * Coordenada.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <string.h>
#include "../matriz/Matriz.h"

using namespace std;

class Coordenada {
public:
	Coordenada(double x, double y, double z);
	Coordenada();
	virtual ~Coordenada();
	double getX();
	double getY();
	double getZ();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	bool isInterseccao();
	bool isVisitado();
	void setInterseccao(bool isInterseccao);
	void setVisitado(bool isVisitado);
	void addCoordenada(Coordenada* coordenada);
	void multiplyByMatriz(class Matriz* matriz);
	bool equal(Coordenada* coordenada);
	Coordenada* clone();



private:
	double x;
	double y;
	double z;
	bool interseccao, visitado;
};

#endif /* COORDENADA_H_ */
