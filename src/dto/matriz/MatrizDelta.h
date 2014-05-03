/*
 * MatrizDelta.h
 *
 *  Created on: 03/05/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZDELTA_H_
#define MATRIZDELTA_H_
#include "Matriz.h"

class MatrizDelta : public Matriz {
public:
	MatrizDelta(double delta);
	virtual ~MatrizDelta();
};

#endif /* MATRIZDELTA_H_ */
