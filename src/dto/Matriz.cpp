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

Matriz* Matriz::multiplique(Matriz* matriz)  {
	Matriz* resultado = new Matriz(numLinhas);
	for (int i = 0; i < numLinhas; i++) {
		for (int j = 0; j < numColunas; j++) {
			for (int k = 0; k < numColunas; k++) {
				resultado->getMatriz()[i][j] = resultado->getMatriz()[i][j] + (this->dado[i][k] * matriz->getMatriz()[k][j]);
			}
		}
	}
	return resultado;
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

	return 0;
}

Matriz* Matriz::getMatrizRotacao(Coordenada* center, Rotacao* rotacao){

	return 0;
}

Matriz* Matriz::getMatrizEscalonamento(Coordenada* center, Escalonamento* escalonamento){

	return 0;
}

Matriz* Matriz::getMatrizByCoordenada(Coordenada* coordenada){
	Matriz* matriz = new Matriz(1);
	matriz->getMatriz()[0][0] = coordenada->getX();
	matriz->getMatriz()[0][1] = coordenada->getY();
	matriz->getMatriz()[0][2] = 1;
	return matriz;
}

double** Matriz::getMatriz() {
	return dado;
}

Matriz::~Matriz() {

}

