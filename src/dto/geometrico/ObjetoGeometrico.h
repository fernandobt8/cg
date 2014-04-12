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
	list<Coordenada*>* getWindowCoordenadas();
	void multipliqueCoordenadas(Matriz* matriz);
	void multipliqueCPPcoordenadas(Matriz* matriz);
	void printAllcoordenadas();
	void printAllCPPcoordenadas();

protected:
	const char* nome;
	list<Coordenada*>* coordenadas;
	list<Coordenada*>* CPPcoordenadas;
};

#endif /* OBJETOGEOMETRICO_H_ */
