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
	static void gerarPontosBlendingFunction(list<Coordenada*>* listCoordenads, Matriz* matrizTipoCurva, Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4){
		Matriz* matrizG = MatrizUtils::getMatrizGeometria(p1, p2, p3, p4);
		for(double t = 0; t < 1.00001; t += 0.05){
			Matriz* matrizBF = MatrizUtils::getMatrizBlendingFunction(t, matrizTipoCurva);
			matrizBF->multiply(matrizG);
			double** matrizR = matrizBF->getMatriz();
			listCoordenads->push_back(new Coordenada(matrizR[0][0], matrizR[0][1], matrizR[0][2]));
			delete matrizBF;
		}
	}

	static void gerarPontosForwardDifference(list<Coordenada*>* listCoordenads, Matriz* matrizTipoCurva, Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4){
		Matriz* matrizDelta = MatrizUtils::getMatrizForwardDifference(0.02, matrizTipoCurva);
		Matriz* matrizG = MatrizUtils::getMatrizGeometria(p1, p2, p3, p4);
		matrizDelta->multiply(matrizG);
		double** matrizR = matrizDelta->getMatriz();
		listCoordenads->push_back(new Coordenada(matrizR[0][0], matrizR[0][1], matrizR[0][2]));
		for (int i = 0; i < 1.0/0.02; ++i) {
			//x's
			matrizR[0][0] = matrizR[0][0] + matrizR[1][0];
			matrizR[1][0] = matrizR[1][0] + matrizR[2][0];
			matrizR[2][0] = matrizR[2][0] + matrizR[3][0];
			//y's
			matrizR[0][1] = matrizR[0][1] + matrizR[1][1];
			matrizR[1][1] = matrizR[1][1] + matrizR[2][1];
			matrizR[2][1] = matrizR[2][1] + matrizR[3][1];
			listCoordenads->push_back(new Coordenada(matrizR[0][0], matrizR[0][1], matrizR[0][2]));
		}
		delete matrizG;
		delete matrizDelta;
	}

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
