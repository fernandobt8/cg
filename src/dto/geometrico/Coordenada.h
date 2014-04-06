/*
 * Coordenada.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <string.h>
#include "../Matriz.h"

using namespace std;

class Coordenada {
public:
	Coordenada(double x, double y);
	Coordenada();
	virtual ~Coordenada();
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	void addToX(double x);
	void addToY(double y);
	void vezesMatriz(class Matriz* matriz);
	Coordenada* clone();
private:
	double x;
	double y;
};

#endif /* COORDENADA_H_ */
