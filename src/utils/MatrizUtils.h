/*
 * MatrizUtils.h
 *
 *  Created on: 01/05/2014
 *      Author: fernandobt8
 */

#ifndef MATRIZUTILS_H_
#define MATRIZUTILS_H_
#include "../dto/matriz/MatrizEscalonamento.h"
#include "../dto/matriz/MatrizRotacao.h"
#include "../dto/matriz/MatrizTranslacao.h"
#include "../dto/matriz/MatrizBezier.h"

class MatrizUtils{
public:
	static Matriz* getMatrizBlendingFunction(double t){
		Matriz* matrizT = new Matriz(t);
		Matriz* matrizB = new MatrizBezier();
		matrizT->multiply( matrizB);
		delete matrizB;
		return matrizT;
	}

	static Matriz* getMatrizGeometria(Coordenada* p1, Coordenada* p2, Coordenada* p3, Coordenada* p4){
		Matriz* matriz = new Matriz(4, 2);
		matriz->getMatriz()[0][0] = p1->getX();
		matriz->getMatriz()[1][0] = p2->getX();
		matriz->getMatriz()[2][0] = p3->getX();
		matriz->getMatriz()[3][0] = p4->getX();

		matriz->getMatriz()[0][1] = p1->getY();
		matriz->getMatriz()[1][1] = p2->getY();
		matriz->getMatriz()[2][1] = p3->getY();
		matriz->getMatriz()[3][1] = p4->getY();
		return matriz;
	}

	static Matriz* getFullMatrizRotacao(Coordenada* center, Rotacao* rotacao){
		MatrizRotacao* matrizRotacao = new MatrizRotacao(rotacao->angulo);
		if(rotacao->tipoRotacao != Rotacao::ORIGEM){
			double x, y;
			if(rotacao->tipoRotacao == Rotacao::CENTRO){
				x = center->getX();
				y = center->getY();
			} else if(rotacao->tipoRotacao == Rotacao::PONTO){
				x = rotacao->getX();
				y = rotacao->getY();
			}
				Matriz* transCenter = new MatrizTranslacao(-x, -y);
				transCenter->multiply(matrizRotacao);
				MatrizTranslacao transCenterBack(x, y);
				transCenter->multiply(&transCenterBack);
				delete matrizRotacao;
				return transCenter;
		}
		return matrizRotacao;
	}

	static Matriz* getFullMatrizEscalonamento(Coordenada* center, Escalonamento* escalonamento){
		Matriz* transCenter = new MatrizTranslacao(-center->getX(), -center->getY());
		MatrizEscalonamento matrizEscalonamento(escalonamento->getX(), escalonamento->getY());
		transCenter->multiply(&matrizEscalonamento);
		MatrizTranslacao transCenterBack(center->getX(), center->getY());
		transCenter->multiply(&transCenterBack);
		return transCenter;
	}

	static Matriz* getMatrizTransformacao(Coordenada* center, list<Transformacao*>* transformacoes) {
		Matriz* matriz = MatrizUtils::getMatrizByTransformacao(center, transformacoes->front());
		list<Transformacao*>::iterator it = _List_iterator<Transformacao*>( transformacoes->begin()._M_node->_M_next);
		for (; it != transformacoes->end(); it++) {
			Matriz* temp = MatrizUtils::getMatrizByTransformacao(center, *it);
			matriz->multiply(temp);
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
};




#endif /* MATRIZUTILS_H_ */
