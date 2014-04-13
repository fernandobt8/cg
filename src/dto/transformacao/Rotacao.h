/*
 * Rotacao.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef ROTACAO_H_
#define ROTACAO_H_
#include "Transformacao.h"
#define ORIGEM 0
#define CENTRO 1
#define PONTO  2

class Rotacao : public Transformacao {
public:
	Rotacao();
	Rotacao(double angulo, int tipoRotacao);
	virtual ~Rotacao();
	int tipoRotacao; //0-origem 1-centro 2-ponto
	double angulo;
};

#endif /* ROTACAO_H_ */
