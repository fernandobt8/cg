/*
 * MatrizTranslacao.h
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZTRANSLACAO_H_
#define MATRIZTRANSLACAO_H_
#include "Matriz.h"
#include "../transformacao/Translacao.h"

class MatrizTranslacao : public Matriz{
public:
	MatrizTranslacao(Translacao* translacao);
	MatrizTranslacao(double x, double y, double z);
	virtual ~MatrizTranslacao();

private:
	void initialize(double x, double y, double z);
};

#endif /* MATRIZTRANSLACAO_H_ */
