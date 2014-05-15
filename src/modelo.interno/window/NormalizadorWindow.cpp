/*
 * NormalizadorWindow.cpp
 *
 *  Created on: 14/05/2014
 *      Author: fernandobt8
 */

#include "NormalizadorWindow.h"

NormalizadorWindow::NormalizadorWindow(Coordenada* windowCenter, Coordenada* vectorUp, Coordenada* VPN) {
	this->windowCenter = windowCenter;
	this->vectorUp = vectorUp;
	this->VPN = VPN;
	anguloPlanoXY = Utils::getAnguloPlanoXY(vectorUp);
	MatrizRotacao matrizXY(anguloPlanoXY, Rotacao::AROUND_X);
	vectorUp->multiplyByMatriz(&matrizXY);

	anguloCima = Utils::getAnguloPlanoZY(vectorUp);
	MatrizRotacao matrizZY(anguloCima, Rotacao::AROUND_Z);

	matrizXY.multiply(&matrizZY);
	VPN->multiplyByMatriz(&matrizXY);

	anguloFrente = Utils::getAnguloPlanoYZ(VPN);
}

Matriz* NormalizadorWindow::getMatrizNormalizacao(){
	Matriz* transOrigem = new MatrizTranslacao(-windowCenter->getX(), -windowCenter->getY(), -windowCenter->getZ());
	Matriz* normaAngulo = this->getMatrizNormalizarAngulo();
	transOrigem->multiply(normaAngulo);
	delete normaAngulo;
	return transOrigem;
}

Matriz* NormalizadorWindow::getMatrizDesnormalizacao(){
	Matriz* matrizYZ = this->getMatrizDesnormalizarAngulo();
	MatrizTranslacao trans(windowCenter->getX(), windowCenter->getY(), windowCenter->getZ());
	matrizYZ->multiply(&trans);
	return matrizYZ;
}

Matriz* NormalizadorWindow::getMatrizNormalizarAngulo(){
	Matriz* matrizXY = new MatrizRotacao(anguloPlanoXY, Rotacao::AROUND_X);
	MatrizRotacao matrizZY(anguloCima, Rotacao::AROUND_Z);
	MatrizRotacao matrizYZ(anguloFrente, Rotacao::AROUND_Y);
	matrizXY->multiply(&matrizZY);
	matrizXY->multiply(&matrizYZ);
	return matrizXY;
}

Matriz* NormalizadorWindow::getMatrizDesnormalizarAngulo(){
	Matriz* matrizYZ = new MatrizRotacao(-anguloFrente, Rotacao::AROUND_Y);
	MatrizRotacao matrizZY(-anguloCima, Rotacao::AROUND_Z);
	MatrizRotacao matrizXY(-anguloPlanoXY, Rotacao::AROUND_X);
	matrizYZ->multiply(&matrizZY);
	matrizYZ->multiply(&matrizXY);
	return matrizYZ;
}

Matriz* NormalizadorWindow::getMatrizFullNormalizar(Matriz* matriz){
	Matriz* matrizNorma = this->getMatrizNormalizacao();
	Matriz* matrizDesnorma = this->getMatrizDesnormalizacao();
	matrizNorma->multiply(matriz);
	matrizNorma->multiply(matrizDesnorma);
	delete matrizDesnorma;
	return matrizNorma;
}

Matriz* NormalizadorWindow::getMatrizFullNormalizarAngulo(Matriz* matriz){
	Matriz* matrizNorma = this->getMatrizNormalizarAngulo();
	Matriz* matrizDesnorma = this->getMatrizDesnormalizarAngulo();
	matrizNorma->multiply(matriz);
	matrizNorma->multiply(matrizDesnorma);
	delete matrizDesnorma;
	return matrizNorma;
}

NormalizadorWindow::~NormalizadorWindow() {
	delete VPN;
	delete vectorUp;
	delete windowCenter;
}
