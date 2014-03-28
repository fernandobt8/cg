/*
 * Coordenada.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <string.h>

class Coordenada {
public:
	Coordenada(int x, int y);
	Coordenada();
	virtual ~Coordenada();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	char* toString();

private:
	int x;
	int y;
};

#endif /* COORDENADA_H_ */
