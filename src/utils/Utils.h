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
#include <list>

class Utils {
public:
	static char* cloneChar(const char* value) {
		char* copy = new char[strlen(value) + 1];
		strcpy(copy, value);
		return copy;
	}

	template<typename T>
	static void destroyList(list<T*> *lista) {
		T* c = lista->front();
		while (!lista->empty()) {
			delete c;
			lista->pop_front();
			c = lista->front();
		}
		delete lista;
	}

	template<typename Sort, typename Equal>
	static void montListByConditionAndOrder(list<Coordenada* >* origem, list<Coordenada* > *destino, Coordenada* equalAThis, Equal equalCondition, Sort sortList){
		list<Coordenada* >::iterator it = origem->begin();
		for(; it != origem->end(); it++){
			if(equalCondition(equalAThis, *it)){
				destino->push_back(*it);
			}
		}
		destino->sort(sortList);
	}

	static void splice(list<Coordenada* >* destino, list<Coordenada* >* origem, Coordenada* afterPosition){
		list<Coordenada* >::iterator pos = destino->begin();
		for(; pos != destino->end(); pos++){
			if(afterPosition == *pos){
				break;
			}
		}
		pos++;
		list<Coordenada* >::iterator it = origem->begin();
		for(; it != origem->end(); it++){
			destino->insert(pos, *it);
		}
	}

	static bool compareEqualY(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getY() == coordenada2->getY();
	}

	static bool compareEqualX(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getX() == coordenada2->getX();
	}

	static bool compareMenorY(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getY() < coordenada2->getY();
	}

	static bool compareMenorX(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getX() < coordenada2->getX();
	}

	static bool compareMaiorY(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getY() > coordenada2->getY();
	}

	static bool compareMaiorX(Coordenada* coordenada1, Coordenada* coordenada2){
		return coordenada1->getX() > coordenada2->getX();
	}

	static Matriz* getMatrizTransformacao(Coordenada* center,
			list<Transformacao*>* transformacoes) {
		Matriz* matriz = Utils::getMatrizByTransformacao(center,
				transformacoes->front());
		list<Transformacao*>::iterator it = _List_iterator<Transformacao*>(
				transformacoes->begin()._M_node->_M_next);
		for (; it != transformacoes->end(); it++) {
			Matriz* temp = Utils::getMatrizByTransformacao(center, *it);
			matriz->multiply(temp);
			delete temp;
		}
		return matriz;
	}

	static Matriz* getMatrizByTransformacao(Coordenada* center,
			Transformacao* transformacao) {
		Matriz* matriz;
		Translacao* trans = dynamic_cast<Translacao*>(transformacao);
		Rotacao* rotacao = dynamic_cast<Rotacao*>(transformacao);
		Escalonamento* esca = dynamic_cast<Escalonamento*>(transformacao);
		if (trans) {
			matriz = new MatrizTranslacao(trans);
		} else if (rotacao) {
			matriz = new MatrizRotacao(center, rotacao);
		} else if (esca) {
			matriz = new MatrizEscalonamento(center, esca);
		}
		return matriz;
	}

	template<typename T>
	static int getIndexObject(list<T*> *lista, T* object) {
		_List_iterator<T*> it = lista->begin();
		int count = 0;
		for (; it != lista->end(); it++, count++) {
			if (object == (*it)) {
				return count;
			}
		}
		return -1;
	}

	template<typename T>
	static _List_iterator<T*> getIteratorInObject(list<T*> *lista, T* object) {
		_List_iterator<T*> it = lista->begin();
		for (; it != lista->end(); it++){
			if (object == (*it)) {
				return it;
			}
		}
		throw "object not found";
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
