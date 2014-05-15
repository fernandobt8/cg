/*
 * RotacaoView.h
 *
 *  Created on: 05/04/2014
 *      Author: alisson
 */

#ifndef ROTACAOVIEW_H_
#define ROTACAOVIEW_H_

#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include "../../../api/OnAdicionarTipoTransformacaoEvent.h"
#include "../../../dto/transformacao/Rotacao.h"
#include <list>

using namespace std;

class RotacaoView: public QWidget {
Q_OBJECT
public:
	RotacaoView(OnAdicionarTipoTransformacaoEvent* event);
	virtual ~RotacaoView();
	void getAround(Rotacao *rotacao, int indice);


public slots:
	void on_pontoButton_toggled(bool checked);
	void on_adicionarButton_clicked();

private:
	QFrame *frame;
	QRadioButton *origemButton;
	QRadioButton *centroButton;
	QRadioButton *pontoButton;
	QLineEdit *anguloXInput;
	QLineEdit *anguloYInput;
	QLineEdit *anguloZInput;
	QLineEdit *xInput;
	QLineEdit *yInput;
	QLineEdit *zInput;
	QLabel *pontoLabel;
	QLabel *xLabel;
	QLabel *yLabel;
	QLabel *zLabel;
	QPushButton *adicionarButton;
	OnAdicionarTipoTransformacaoEvent* event;
};

#endif /* ROTACAOVIEW_H_ */
