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

class RotacaoView: public QWidget {
Q_OBJECT
public:
	RotacaoView();
	virtual ~RotacaoView();

	QFrame *frame;
	QLabel *operacoesLabel;
	QLabel *anguloLabel;
	QLabel *grausLabel;
	QRadioButton *origemButton;
	QRadioButton *centroButton;
	QRadioButton *pontoButton;
	QLineEdit *anguloInput;
	QLineEdit *pontoInput;
	QLabel *pontoLabel;
	QPushButton *adicionarButton;

public slots:
	void on_pontoButton_toggled(bool checked);
	void on_adicionarButton_clicked();

};

#endif /* ROTACAOVIEW_H_ */
