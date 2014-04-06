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
	Transformacao();
	virtual ~Transformacao();
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);

protected:
	double x;
	double y;
};

#endif /* TRANSFORMACAO_H_ */
