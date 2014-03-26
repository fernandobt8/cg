/*
 * AdicionarWindow.h
 *
 *  Created on: 23/03/2014
 *      Author: alisson
 */

#ifndef ADICIONARWINDOW_H_
#define ADICIONARWINDOW_H_

#include <QtCore/QVariant>
#include <QtGui/qaction.h>
#include "QtGui/qpainter.h"
#include "QtGui/qwidget.h"
#include "QtCore/qvariant.h"
#include "QtGui/qaction.h"
#include "QtGui/qapplication.h"
#include "QtGui/qbuttongroup.h"
#include "QtGui/qheaderview.h"
#include "QtGui/qpushbutton.h"
#include "QtGui/qboxlayout.h"
#include "QtGui/qwidget.h"
#include "QtGui/qmessagebox.h"
#include "QtGui/qmainwindow.h"
#include "QtGui/qlineedit.h"
#include "QtGui/qlabel.h"
#include "../../api/OnAdicionarObjetoTipoEvent.h"
#include "../../dto/Ponto.h"
#include "../../dto/Reta.h"
#include <stdio.h>
#include <stdlib.h>

class AdicionarTipoObjetoView : public QMainWindow
{
	Q_OBJECT
public:
	 AdicionarTipoObjetoView(OnAdicionarObjetoTipoEvent *event);
	~AdicionarTipoObjetoView();

public slots:
	void on_tabWindow_currentChanged(int index);

    void on_okButton_clicked();

    void on_cancelarButton_clicked();

private:
    QWidget *centralwidget;
    QLineEdit *nomeTextField;
    QLabel *nomeLabel;
    QTabWidget *tabWindow;
    QWidget *pontoWidget;
    QLineEdit *xTextFieldPonto;
    QLineEdit *yTextFieldPonto;
    QLabel *coordenadasLabel;
    QLabel *label;
    QLabel *label_2;
    QWidget *retaWidget;
    QLabel *coordenadasLabel_2;
    QLabel *coordenadasLabel_3;
    QLineEdit *x1TextFieldReta;
    QLineEdit *y1TextFieldReta;
    QLineEdit *x2TextFieldReta;
    QLineEdit *y2TextFieldReta;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *poligonoWidget;
    QPushButton *okButton;
    QPushButton *cancelarButton;
    OnAdicionarObjetoTipoEvent *addEvent;
};


#endif /* ADICIONARWINDOW_H_ */
