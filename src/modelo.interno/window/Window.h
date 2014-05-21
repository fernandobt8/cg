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
#include "../../dto/matriz/MatrizEscalonamento.h"
#include "../../dto/matriz/MatrizRotacao.h"
#include "../../dto/matriz/MatrizTranslacao.h"
#include "../../utils/Utils.h"
#include "NormalizadorWindow.h"
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
	void rotacione(double angulo, Rotacao::Round around);
	double getWidth();
	double getHeight();
	Coordenada* getCenter();
	NormalizadorWindow* getNormalizador();
	void clearWindowObjetos();
	Coordenada* CPPstart;
	Coordenada* CPPend;

private:
	Coordenada* windowCenter;
	Coordenada* vectorUp;
	Coordenada* VPN;
	Coordenada* start;
	Coordenada* end;
	list<ObjetoGeometrico* >* objetos;

};

#endif /* WINDOWVIEW_H_ */
