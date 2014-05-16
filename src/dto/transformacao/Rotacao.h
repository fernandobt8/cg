/*
 * Rotacao.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef ROTACAO_H_
#define ROTACAO_H_
#include "Transformacao.h"
#include "../geometrico/Coordenada.h"

class Rotacao : public Transformacao {
public:
	enum Tipo{
		CENTRO,
		PONTO,
	} tipoRotacao;
	enum Round {
		AROUND_X,
		AROUND_Y,
		AROUND_Z,
	} around;
	Rotacao();
	Rotacao(double angulo, Rotacao::Tipo tipoRotacao, Rotacao::Round around);
	virtual ~Rotacao();
	void setXFinal(double final);
	void setYFinal(double final);
	void setZFinal(double final);
	Coordenada* getCoordenadaFinal();
	double angulo;
	Coordenada* coordenadaFinal;
};

#endif /* ROTACAO_H_ */
