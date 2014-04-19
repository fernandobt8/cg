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

class MatrizRotacao : public Matriz {
public:
	MatrizRotacao(Coordenada* center, Rotacao* rotacao);
	MatrizRotacao(double angulo);
	virtual ~MatrizRotacao();

private:
	void initialize(double angulo);
};

#endif /* MATRIZROTACAO_H_ */
