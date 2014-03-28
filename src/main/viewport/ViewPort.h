/*
 * ViewPort.h
 *
 *  Created on: 28/03/2014
 *      Author: fernandobt8
 */

#ifndef VIEWPORT_H_
#define VIEWPORT_H_
#include "QtGui/qwidget.h"
#include "QtGui/qpalette.h"

class ViewPort : public QWidget{
	Q_OBJECT
public:
	ViewPort(QWidget* parent);
	virtual ~ViewPort();
};

#endif /* VIEWPORT_H_ */
