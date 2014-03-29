/*
 * Coordenada.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

#include <string.h>

using namespace std;

class Coordenada {
public:
	Coordenada(int x, int y);
	Coordenada();
	virtual ~Coordenada();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void addToX(int x);
	void addToY(int y);
	char* toString();
private:
	int x;
	int y;
};

#endif /* COORDENADA_H_ */
