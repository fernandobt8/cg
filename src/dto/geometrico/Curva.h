/*
 * Curva.h
 *
 *  Created on: 30/04/2014
 *      Author: fernandobt8
 */

#ifndef CURVA_H_
#define CURVA_H_
#include "ObjetoGeometrico.h"
#include "../../utils/MatrizUtils.h"
#include "../../utils/Utils.h"

class Curva : public ObjetoGeometrico{
public:
	Curva(char* nome, list<Coordenada*>* coordenadas);
	Curva(char* nome);
	virtual ~Curva();
	void multiplyCoordenadasToCPP(Matriz* matriz);
	Curva* clone();

};

#endif /* CURVA_H_ */
