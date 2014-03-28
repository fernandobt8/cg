/*
 * ViewPort.cpp
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#include "ViewPort.h"

ViewPort::ViewPort(QWidget* parent): QWidget(parent)  {
	QPalette pale(palette());
	pale.setColor(QPalette::Background, Qt::white);
	this->setAutoFillBackground(true);
	this->setPalette(pale);
}

ViewPort::~ViewPort() {
}

