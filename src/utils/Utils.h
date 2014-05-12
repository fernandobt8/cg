/*
 * Utils.h
 *
 *  Created on: 06/04/2014
 *      Author: fernandobt8
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <string.h>
#include <list>

#define PI 3.14159265

class Utils {
public:
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
