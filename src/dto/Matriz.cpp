/*
 * Matriz.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Matriz.h"

Matriz::Matriz(double** matriz, int numLinhas) {
	dado = matriz;
	this->numLinhas = numLinhas;
}

Matriz::Matriz(int numLinhas){
	this->numLinhas = numLinhas;
	dado = new double*[numLinhas];
	for(int i = 0; i < numLinhas; i++){
		dado[i] = new double[numColunas];
	}
}

void Matriz::multiply(Matriz* matriz)  {
	double** resultado = new double*[numLinhas];
	for (int i = 0; i < numLinhas; i++) {
		resultado[i] = new double[numColunas];
		for (int j = 0; j < numColunas; j++) {
			resultado[i][j] = 0;
			for (int k = 0; k < numColunas; k++) {
				resultado[i][j] = resultado[i][j] + (this->dado[i][k] * matriz->getMatriz()[k][j]);
			}
		}
	}
	this->clear();
	this->dado = resultado;
}

Matriz* Matriz::getMatrizTransformacao(Coordenada* center, list<Transformacao* >* transformacoes){
	Matriz* matriz;
	Matriz* temp;
	Translacao* trans = dynamic_cast<Translacao* >(*transformacoes->begin());
	Rotacao* rotacao = dynamic_cast<Rotacao* >(*transformacoes->begin());
	Escalonamento* esca = dynamic_cast<Escalonamento* >(*transformacoes->begin());
	if(trans){
		matriz = Matriz::getMatrizTranslacao(trans);
	}else if(rotacao){
		matriz = Matriz::getMatrizRotacao(center, rotacao);
	}else if(esca){
		matriz = Matriz::getMatrizEscalonamento(center, esca);
	}
	list<Transformacao* >::iterator it = _List_iterator<Transformacao* >(transformacoes->begin()._M_node->_M_next);
	for(;it != transformacoes->end(); it++){
		Translacao* trans = dynamic_cast<Translacao* >(*it);
		Rotacao* rotacao = dynamic_cast<Rotacao* >(*it);
		Escalonamento* esca = dynamic_cast<Escalonamento* >(*it);
		if(trans){
			temp = Matriz::getMatrizTranslacao(trans);
		}else if(rotacao){
			temp = Matriz::getMatrizRotacao(center, rotacao);
		}else if(esca){
			temp = Matriz::getMatrizEscalonamento(center, esca);
		}
		matriz->multiply(temp);
		delete temp;
	}
	return matriz;
}

Matriz* Matriz::getMatrizTranslacao(double x, double y){
	Translacao* trans = new Translacao(x, y);
	Matriz* matriz = Matriz::getMatrizTranslacao(trans);
	delete trans;
	return matriz;
}

Matriz* Matriz::getMatrizTranslacao(Translacao* translacao){
	Matriz* matriz = new Matriz(3);
	matriz->getMatriz()[0][0] = 1;
	matriz->getMatriz()[0][1] = 0;
	matriz->getMatriz()[0][2] = 0;

	matriz->getMatriz()[1][0] = 0;
	matriz->getMatriz()[1][1] = 1;
	matriz->getMatriz()[1][2] = 0;

	matriz->getMatriz()[2][0] = translacao->getX();
	matriz->getMatriz()[2][1] = translacao->getY();
	matriz->getMatriz()[2][2] = 1;
	return matriz;
}

Matriz* Matriz::getMatrizRotacao(Coordenada* center, Rotacao* rotacao){
	Matriz* matriz = new Matriz(3);
	matriz->getMatriz()[0][0] = cos(rotacao->angulo*(PI/180));
	matriz->getMatriz()[0][1] = -sin(rotacao->angulo*(PI/180));
	matriz->getMatriz()[0][2] = 0;

	matriz->getMatriz()[1][0] = sin(rotacao->angulo*(PI/180));
	matriz->getMatriz()[1][1] = cos(rotacao->angulo*(PI/180));
	matriz->getMatriz()[1][2] = 0;

	matriz->getMatriz()[2][0] = 0;
	matriz->getMatriz()[2][1] = 0;
	matriz->getMatriz()[2][2] = 1;
	if(rotacao->tipoRotacao != ORIGEM){
		double x;
		double y;
		if(rotacao->tipoRotacao == CENTRO){
			x = center->getX();
			y = center->getY();
		} else if(rotacao->tipoRotacao == PONTO){
			x = rotacao->getX();
			y = rotacao->getY();
		}
			Matriz* transCenter = Matriz::getMatrizTranslacao(-x, -y);
			transCenter->multiply(matriz);

			Matriz* transCenterBack = Matriz::getMatrizTranslacao(x, y);
			transCenter->multiply(transCenterBack);

			delete matriz;
			delete transCenterBack;
			return transCenter;
	}
	return matriz;
}

Matriz* Matriz::getMatrizEscalonamento(Coordenada* center, Escalonamento* escalonamento){
	Matriz* transCenter = Matriz::getMatrizTranslacao(-center->getX(), -center->getY());
	Matriz* esca = Matriz::getMatrizEscalonamento(escalonamento);
	transCenter->multiply(esca);
	Matriz* transCenterBack = Matriz::getMatrizTranslacao(center->getX(), center->getY());
	transCenter->multiply(transCenterBack);
	delete transCenterBack;
	delete esca;
	return transCenter;
}

Matriz* Matriz::getMatrizEscalonamento(Escalonamento* escalonamento){
	Matriz* esca = new Matriz(3);
	esca->getMatriz()[0][0] = escalonamento->getX();
	esca->getMatriz()[0][1] = 0;
	esca->getMatriz()[0][2] = 0;

	esca->getMatriz()[1][0] = 0;
	esca->getMatriz()[1][1] = escalonamento->getY();
	esca->getMatriz()[1][2] = 0;

	esca->getMatriz()[2][0] = 0;
	esca->getMatriz()[2][1] = 0;
	esca->getMatriz()[2][2] = 1;
	return esca;
}

Matriz* Matriz::getMatrizByCoordenada(Coordenada* coordenada){
	Matriz* matriz = new Matriz(1);
	matriz->getMatriz()[0][0] = coordenada->getX();
	matriz->getMatriz()[0][1] = coordenada->getY();
	matriz->getMatriz()[0][2] = 1;
	return matriz;
}

void Matriz::printAll(){
	 for (int i=0; i<numLinhas; i++) {
	  for (int j=0; j<numColunas; j++) {
		printf("%f ", dado[i][j]);
	  }
	  printf("\n");
	}
}

double** Matriz::getMatriz() {
	return dado;
}

Matriz::~Matriz() {
	this->clear();
}

void Matriz::clear(){
	for(int i = 0; i < numLinhas; i++){
		delete[] dado[i];
	}
	delete[] dado;
}
