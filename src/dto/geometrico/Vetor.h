/*
 * Vetor.h
 *
 *  Created on: 15/05/2014
 *      Author: alisson
 */

#ifndef VETOR_H_
#define VETOR_H_

#include "Coordenada.h"

class Vetor {
public:
	Vetor(Coordenada *inicial, Coordenada *final);
	virtual ~Vetor();
	Coordenada *getCoordenadaInicial();
	Coordenada *getCoordenadaFinal();

private:
	Coordenada *inicial, *final;
};

#endif /* VETOR_H_ */
