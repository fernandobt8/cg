/*
 * Utils.h
 *
 *  Created on: 06/04/2014
 *      Author: fernandobt8
 */

#ifndef UTILS_H_
#define UTILS_H_
#include "../dto/geometrico/Coordenada.h"
#include <string.h>
#include <math.h>
#include <list>

#define PI 3.14159265

class Utils {
public:
	static double getAnguloPlanoXY(Coordenada* coordenada){
		double dividendo = coordenada->getY();
		double divisor = sqrt(pow(coordenada->getY(), 2) + pow(coordenada->getZ(), 2));
		double angulo = Utils::convertRaianosToGraus(acos(dividendo / divisor));
		return coordenada->getZ() > 0 ? -angulo : angulo;
	}

	static double getAnguloPlanoZY( Coordenada* coordenada){
		double dividendo = coordenada->getY();
		double divisor = sqrt(pow(coordenada->getX(), 2) + pow(coordenada->getY(), 2));
		double angulo = Utils::convertRaianosToGraus(acos(dividendo / divisor));
		return coordenada->getX() > 0 ? angulo : -angulo;
	}

	static double getAnguloPlanoYZ( Coordenada* coordenada){
		double dividendo = coordenada->getZ();
		double divisor = sqrt(pow(coordenada->getX(), 2) + pow(coordenada->getZ(), 2));
		double angulo = Utils::convertRaianosToGraus(acos(dividendo / divisor));
		return coordenada->getX() > 0 ? -angulo : angulo;
	}

	static double getAnguloPlanoXZ(Coordenada* coordenada){
		double dividendo = coordenada->getZ();
		double divisor = sqrt(pow(coordenada->getY(), 2) + pow(coordenada->getZ(), 2));
		double angulo = Utils::convertRaianosToGraus(acos(dividendo / divisor));
		return coordenada->getY() > 0 ? angulo : -angulo;
	}

	static double getAnguloBetweenVectors(Coordenada* coor1, Coordenada* coor2){
		//grau = arccos(v1 * v2) / (||v1|| * ||v2||)
		double dividendo = (coor1->getX() * coor2->getX()) + (coor1->getY() * coor2->getY()) + (coor1->getZ() * coor2->getZ());
		double divisor =  sqrt(pow(coor1->getY(), 2) + pow(coor1->getZ(), 2)) *
				sqrt(pow(coor2->getY(), 2) + pow(coor2->getZ(), 2));
		return Utils::convertRaianosToGraus(acos(dividendo / divisor));
	}

	static double convertGrausToRadianos(double graus){
		return graus * (PI / 180);
	}

	static double convertRaianosToGraus(double radianos){
		return 180 * (radianos / PI);
	}

	static char* cloneChar(const char* value) {
		char* copy = new char[strlen(value) + 1];
		strcpy(copy, value);
		return copy;
	}

	static bool isBetween(double start, double end, double value){
		return value >= start && value <= end;
	}
};

#endif /* UTILS_H_ */
