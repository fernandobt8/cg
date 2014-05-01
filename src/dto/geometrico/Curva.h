/*
 * Curva.h
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#ifndef CURVA_H_
#define CURVA_H_
#include "ObjetoGeometrico.h"

class Curva : public ObjetoGeometrico{
public:
	Curva(char* nome);
	virtual ~Curva();
	void multiplyCoordenadasToCPP(Matriz matriz);
};

#endif /* CURVA_H_ */
