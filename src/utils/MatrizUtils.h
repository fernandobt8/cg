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

class MatrizUtils{
public:
	static Matriz* getMatrizBlendingFunction(double t){
		Matriz matrizT = Matriz(t);

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
};




#endif /* MATRIZUTILS_H_ */
