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
	Coordenada* getCenter();
	void addCoordenada(Coordenada* coordenada);
	list<Coordenada*>* getCoordenadas();
	list<Coordenada*>* getWindowCoordenadas();
	void addToAllCoordenadas(Coordenada* coordenada);
	void multipliqueAllCoordenadas(Matriz* matriz);
	void subAllWindowCoordenadas(Coordenada* coordenada);
	void multipliqueAllCPPcoordenadas(Matriz* matriz);

protected:
	const char* nome;
	list<Coordenada*>* coordenadas;
	list<Coordenada*>* CPPcoordenadas;
	list<Coordenada*>* windowCoordenadas;
};

#endif /* OBJETOGEOMETRICO_H_ */
