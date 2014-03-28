/*
 * ObjetoGeometrico.h
 *
 *  Created on: 24/03/2014
 *      Author: fernandobt8
 */

#ifndef OBJETOGEOMETRICO_H_
#define OBJETOGEOMETRICO_H_

#include "Coordenada.h"
#include <list>

using namespace std;

class ObjetoGeometrico {
public:
	ObjetoGeometrico(char* nome, list<Coordenada*>* coordenadas);
	ObjetoGeometrico(char* nome);
	virtual ~ObjetoGeometrico();
	char* getNome();
	list<Coordenada*>* getCoordenadas();
	void addToAllCoordenadas(Coordenada* coordenada);
	void addCoordenada(Coordenada* coordenada);
	bool isAfterCoordenada(Coordenada* coordenada);

protected:
	char* nome;
	list<Coordenada*>* coordenadas;
};

#endif /* OBJETOGEOMETRICO_H_ */
