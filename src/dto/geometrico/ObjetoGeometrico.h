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
	ObjetoGeometrico(const char* nome, list<Coordenada*>* coordenadas);
	ObjetoGeometrico(const char* nome);
	virtual ~ObjetoGeometrico();
	const char* getNome();
	list<Coordenada*>* getWindowCoordenadas();
	list<Coordenada*>* getCoordenadas();
	void addCoordenada(Coordenada* coordenada);
	void addToAllCoordenadas(Coordenada* coordenada);
	void updateWindowCoordenadas(Coordenada* coordenada);
	Coordenada* getCenter();

protected:
	const char* nome;
	list<Coordenada*>* coordenadas;
	list<Coordenada*>* windowCoordenadas;
};

#endif /* OBJETOGEOMETRICO_H_ */
