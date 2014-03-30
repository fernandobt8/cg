/*
 * Application.cpp
 *
 *  Created on: 30/03/2014
 *      Author: fernandobt8
 */

#include "Application.h"

Application::Application(int argc, char *argv[]) : QApplication(argc , argv) {
	controller = new MainController();
	connect(this, SIGNAL(lastWindowClosed()), this, SLOT(closeApplication()));
}

void Application::closeApplication(){
	delete controller;
}

Application::~Application() {
}

