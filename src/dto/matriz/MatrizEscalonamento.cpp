/*
 * MatrizEscalonamento.cpp
 *
 *  Created on: 19/04/2014
 *      Author: fernandobt8
 */

#include "MatrizEscalonamento.h"

MatrizEscalonamento::MatrizEscalonamento(double x, double y) : Matriz(){
	matriz[0][0] = x;
	matriz[0][1] = 0;
	matriz[0][2] = 0;

	matriz[1][0] = 0;
	matriz[1][1] = y;
	matriz[1][2] = 0;

	matriz[2][0] = 0;
	matriz[2][1] = 0;
	matriz[2][2] = 1;
}

MatrizEscalonamento::~MatrizEscalonamento(){

}

