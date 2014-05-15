/*
 * MatrizRotacao.h
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZROTACAO_H_
#define MATRIZROTACAO_H_
#include "Matriz.h"
#include "MatrizTranslacao.h"
#include "../transformacao/Rotacao.h"
#include "../../utils/Utils.h"

class Utils;

class MatrizRotacao : public Matriz {
public:
	MatrizRotacao(double angulo, Rotacao::Around around);
	virtual ~MatrizRotacao();
};

#endif /* MATRIZROTACAO_H_ */
