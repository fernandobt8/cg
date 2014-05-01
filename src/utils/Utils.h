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

	static void printListaCoordenada(list<Coordenada*> *lista) {
		_List_iterator<Coordenada*> it = lista->begin();
		for (; it != lista->end(); it++){
			printf("X: %f, Y: %f\n", (*it)->getX(), (*it)->getY());
		}
		printf("\n");
	}
};

#endif /* UTILS_H_ */
