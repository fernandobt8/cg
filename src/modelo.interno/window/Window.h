/*
 * WindowView.h
 *
 *  Created on: 26/03/2014
 *      Author: fernandobt8
 */

#ifndef WINDOW_H_
#define WINDOW_H_
#include "../../dto/geometrico/Coordenada.h"
#include "../../dto/geometrico/ObjetoGeometrico.h"
#include "../../dto/matriz/Matriz.h"
#include "../../dto/matriz/MatrizEscalonamento.h"
#include "../../dto/matriz/MatrizRotacao.h"
#include "../../dto/matriz/MatrizTranslacao.h"
#include "../../utils/Utils.h"
#include <list>
using namespace std;

class Window{
public:
	Window();
	virtual ~Window();
	list<ObjetoGeometrico* >* getWindowObjetos();
	void addWindowObjeto(ObjetoGeometrico* objeto);
	void mutiplyCoordenadas(Matriz* matriz);
	void mutiplyCoordenadasToCPP(Matriz* matriz);
	void move(double x, double y, double z);
	void zoom(double zoomX, double zoomY);
	void rotacione(double angulo);
	double getWidth();
	double getHeight();
	double getAngulo();
	void clearWindowObjetos();
	Coordenada* getCenter();
	Coordenada* getCenterCPP();
	Coordenada* CPPstart;
	Coordenada* CPPend;

private:
	Coordenada* vectorUp;
	Coordenada* start;
	Coordenada* end;
	list<ObjetoGeometrico* >* objetos;

};

#endif /* WINDOWVIEW_H_ */
