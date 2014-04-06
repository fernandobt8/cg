/*
 * Utils.h
 *
 *  Created on: 06/04/2014
 *      Author: fernandobt8
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <string.h>

class Utils {
public:
	static char* cloneChar(const char* value){
		char* copy = new char[strlen(value)+1];
		strcpy(copy, value);
		return copy;
	}
};

#endif /* UTILS_H_ */
