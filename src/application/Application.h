/*
 * Application.h
 *
 *  Created on: 30/03/2014
 *      Author: fernandobt8
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "QtGui/qapplication.h"
#include "../main/MainController.h"

class Application : public QApplication{
	Q_OBJECT
public:
	Application(int argc, char *argv[]);
	virtual ~Application();
public slots:
	void closeApplication();
private:
	MainController* controller;
};

#endif /* APPLICATION_H_ */
