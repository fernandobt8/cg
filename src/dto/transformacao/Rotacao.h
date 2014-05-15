/*
 * Rotacao.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef ROTACAO_H_
#define ROTACAO_H_
#include "Transformacao.h"

class Rotacao : public Transformacao {
public:
	enum Tipo{
		ORIGEM,
		CENTRO,
		PONTO,
	} tipoRotacao;
	enum Around {
		AROUND_X,
		AROUND_Y,
		AROUND_Z,
	} around;
	Rotacao();
	Rotacao(double angulo, Rotacao::Tipo tipoRotacao, Rotacao::Around around);
	virtual ~Rotacao();
	double angulo;
};

#endif /* ROTACAO_H_ */
