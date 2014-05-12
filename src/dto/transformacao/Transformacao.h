/*
 * Transformacao.h
 *
 *  Created on: 05/04/2014
 *      Author: fernandobt8
 */

#ifndef TRANSFORMACAO_H_
#define TRANSFORMACAO_H_

class Transformacao {
public:
	Transformacao(char* nome);
	Transformacao(char* nome, double x, double y, double z);
	virtual ~Transformacao();
	double getX();
	double getY();
	double getZ();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	char* getNome();

protected:
	double x, y, z;
	char* nome;
};

#endif /* TRANSFORMACAO_H_ */
