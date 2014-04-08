/*
 * Matriz.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Matriz.h"
int numColunas = 3;

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

void Matriz::multiplique(Matriz* matriz)  {
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
	delete dado ;
	this->dado = resultado;
}

Matriz* Matriz::getMatrizTransformacao(Coordenada* center, list<Transformacao* >* transformacoes){
	Matriz* matriz;
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
			matriz->multiplique(Matriz::getMatrizTranslacao(trans));
		}else if(rotacao){
			matriz->multiplique(Matriz::getMatrizRotacao(center, rotacao));
		}else if(esca){
			matriz->multiplique(Matriz::getMatrizEscalonamento(center, esca));
		}
	}
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
			Translacao* trans = new Translacao();
			trans->setX(-x);
			trans->setY(-y);

			Matriz* transCenter = Matriz::getMatrizTranslacao(trans);
			transCenter->multiplique(matriz);

			trans->setX(x);
			trans->setY(y);
			transCenter->multiplique(Matriz::getMatrizTranslacao(trans));

			delete trans;
			delete matriz;
			return transCenter;
	}
	return matriz;
}

Matriz* Matriz::getMatrizEscalonamento(Coordenada* center, Escalonamento* escalonamento){
	Translacao* trans = new Translacao();
	trans->setX(-center->getX());
	trans->setY(-center->getY());
	Matriz* transCenter = Matriz::getMatrizTranslacao(trans);

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
	esca->printAll();

	transCenter->multiplique(esca);

	trans->setX(center->getX());
	trans->setY(center->getY());

	transCenter->multiplique(Matriz::getMatrizTranslacao(trans));
	delete trans;
	delete esca;
	return transCenter;
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

}

