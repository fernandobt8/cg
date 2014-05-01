/*
 * MatrizEscalonamento.h
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZESCALONAMENTO_H_
#define MATRIZESCALONAMENTO_H_
#include "Matriz.h"
#include "../transformacao/Escalonamento.h"
#include "MatrizTranslacao.h"

class MatrizEscalonamento : public Matriz{
public:
	MatrizEscalonamento(double x, double y);
	virtual ~MatrizEscalonamento();
};

#endif /* MATRIZESCALONAMENTO_H_ */
