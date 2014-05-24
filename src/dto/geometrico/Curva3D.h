/*
 * Curva3D.h
 *
 *  Created on: 24/05/2014
 *      Author: fernandobt8
 */

#ifndef CURVA3D_H_
#define CURVA3D_H_
#include "ObjetoGeometrico.h"
#include "../matriz/MatrizBezier.h"
#include "../../utils/CoordenadaUtils.h"
#include "../../utils/MatrizUtils.h"

class Curva3D : public ObjetoGeometrico{
public:
	Curva3D(char* nome, list<Coordenada* >* coordenadas);
	void multiplyCoordenadasToCPP(Matriz* matriz);
	Matriz* getMatriz(double s, Matriz* m, Matriz* g, Matriz* mT);
	list<list<Coordenada*>*>* getPontosInS();
	list<list<Coordenada*>*>* getPontosInT();
	virtual ~Curva3D();
private:
	list<list<Coordenada*>*>* pontosInS;
	list<list<Coordenada*>*>* pontosInT;
};

#endif /* CURVA3D_H_ */
