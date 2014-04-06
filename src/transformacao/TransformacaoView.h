/*
 * TransformacaoView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef TRANSFORMACAOVIEW_H_
#define TRANSFORMACAOVIEW_H_

#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>
#include "tipos/rotacao/RotacaoView.h"
#include "tipos/escalonamento/EscalonamentoView.h"
#include "tipos/translacao/TranslacaoView.h"

class TransformacaoView : public QWidget {
public:
	TransformacaoView(QWidget *parent);
	virtual ~TransformacaoView();

	QTabWidget *transformacaoWidget;
	QListWidget *listWidget;
	QLabel *label;
	QPushButton *okButton;
	QPushButton *cancelarButton;
};
#endif /* TRANSFORMACAOVIEW_H_ */
