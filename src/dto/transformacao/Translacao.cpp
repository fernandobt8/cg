/*
 * Translacao.cpp
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#include "Translacao.h"

Translacao::Translacao() : Transformacao("Translacao"){
}

Translacao::Translacao(double x, double y, double z) : Transformacao("Translacao", x, y, z){
}

Translacao::~Translacao() {
}

