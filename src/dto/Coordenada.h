/*
 * Coordenada.h
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada {
public:
	Coordenada(int x, int y);
	virtual ~Coordenada();
	int getX();
	int getY();

private:
	int x;
	int y;
};

#endif /* COORDENADA_H_ */
