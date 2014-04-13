/*
 * Escalonamento.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef ESCALONAMENTO_H_
#define ESCALONAMENTO_H_
#include "Transformacao.h"

class Escalonamento : public Transformacao{
public:
	Escalonamento();
	Escalonamento(double x, double y);
	virtual ~Escalonamento();
};

#endif /* ESCALONAMENTO_H_ */
