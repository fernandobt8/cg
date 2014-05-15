/*
 * NormalizadorWindow.h
 *
 *  Created on: 14/05/2014
 *      Author: fernandobt8
 */

#ifndef NORMALIZADORWINDOW_H_
#define NORMALIZADORWINDOW_H_
#include "../../dto/geometrico/Coordenada.h"
#include "../../dto/matriz/MatrizRotacao.h"
#include "../../dto/matriz/MatrizTranslacao.h"
#include "../../utils/Utils.h"

class NormalizadorWindow {
public:
	NormalizadorWindow(Coordenada* windowCenter, Coordenada* vectorUp, Coordenada* VPN);
	virtual ~NormalizadorWindow();
	double anguloPlanoXY;
	double anguloCima;
	double anguloFrente;
	Matriz* getMatrizNormalizacao();
	Matriz* getMatrizDesnormalizacao();
	Matriz* getMatrizDesnormalizarAngulo();
	Matriz* getMatrizNormalizarAngulo();
	Matriz* getMatrizFullNormalizar(Matriz* matriz);
	Matriz* getMatrizFullNormalizarAngulo(Matriz* matriz);

private:
	Coordenada* windowCenter;
	Coordenada* vectorUp;
	Coordenada* VPN;

};
#endif /* NORMALIZADORWINDOW_H_ */
