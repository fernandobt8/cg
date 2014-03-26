/*
 * Reta.cpp
 *
 *  Created on: 25/03/2014
 *      Author: alisson
 */

#include "Reta.h"

Reta::Reta(int x1, int y1, int x2, int y2) : ObjetoGeometrico(x1,y1){
	this->coordenadaFinal = new Coordenada(x2, y2);
}

Reta::~Reta() {
	// TODO Auto-generated destructor stub
}

Coordenada* Reta::getCoordenadasParaDesenho(){

}

