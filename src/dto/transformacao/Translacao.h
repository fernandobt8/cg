/*
 * Translacao.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef TRANSLACAO_H_
#define TRANSLACAO_H_
#include "Transformacao.h"

class Translacao : public Transformacao{
public:
	Translacao();
	Translacao(double x, double y, double z);
	virtual ~Translacao();
};

#endif /* TRANSLACAO_H_ */
