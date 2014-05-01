/*
 * Utils.h
 *
 *  Created on: 06/04/2014
 *      Author: fernandobt8
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <string.h>
#include "../dto/geometrico/Coordenada.h"
#include "../dto/matriz/Matriz.h"
#include "../dto/matriz/MatrizEscalonamento.h"
#include "../dto/matriz/MatrizRotacao.h"
#include "../dto/matriz/MatrizTranslacao.h"
#include "MatrizUtils.h"
#include <list>

class Utils {
public:
	static char* cloneChar(const char* value) {
		char* copy = new char[strlen(value) + 1];
		strcpy(copy, value);
		return copy;
	}

	static bool isBetween(double start, double end, double value){
		return value >= start && value <= end;
	}

	static Matriz* getMatrizTransformacao(Coordenada* center, list<Transformacao*>* transformacoes) {
		Matriz* matriz = Utils::getMatrizByTransformacao(center, transformacoes->front());
		list<Transformacao*>::iterator it = _List_iterator<Transformacao*>( transformacoes->begin()._M_node->_M_next);
		for (; it != transformacoes->end(); it++) {
			Matriz* temp = Utils::getMatrizByTransformacao(center, *it);
			matriz->multiply(*temp);
			delete temp;
		}
		return matriz;
	}

	static Matriz* getMatrizByTransformacao(Coordenada* center, Transformacao* transformacao) {
		Matriz* matriz;
		Translacao* trans = dynamic_cast<Translacao*>(transformacao);
		Rotacao* rotacao = dynamic_cast<Rotacao*>(transformacao);
		Escalonamento* esca = dynamic_cast<Escalonamento*>(transformacao);
		if (trans) {
			matriz = new MatrizTranslacao(trans);
		} else if (rotacao) {
			matriz = MatrizUtils::getFullMatrizRotacao(center, rotacao);
		} else if (esca) {
			matriz = MatrizUtils::getFullMatrizEscalonamento(center, esca);
		}
		return matriz;
	}

	static void printListaCoordenada(list<Coordenada*> *lista) {
		_List_iterator<Coordenada*> it = lista->begin();
		for (; it != lista->end(); it++){
			printf("X: %f, Y: %f\n", (*it)->getX(), (*it)->getY());
		}
		printf("\n");
	}
};

#endif /* UTILS_H_ */
