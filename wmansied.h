/***************************************************************************
                          WMAnsiEd.h  -  The widgets and menu's etc...
                             -------------------
    begin                : Mon Apr 17 17:11:17 CEST 2000
    copyright            : (C) 2000 by Walter Schreppers
    email                : walle@easynet.be
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/



#ifndef WMANSIED_H
#define WMANSIED_H

#include <q3mainwindow.h>
#include <qpen.h>
#include <qpoint.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qstring.h>
#include <q3pointarray.h>
//Added by qt3to4:
#include <QResizeEvent>
#include <QKeyEvent>
#include "text.h"
#include "canvas.h"
#include "IBMFont.h"

class QKeyEvent;
class QResizeEvent;
class QToolButton;
class QCheckBox;
class QComboBox;
class QDialog;
class QMenuBar;

using namespace std;

class WMAnsiEd : public Q3MainWindow
{
    Q_OBJECT

public:
    WMAnsiEd( QWidget *parent = 0, const char *name = 0 );
    //IBMFont font;
  
protected:
    Canvas canvas;
    void keyPressEvent( QKeyEvent *e );

    QMenuBar *menu;
    QToolButton *bPColor, *bSave, *bClear;
    QComboBox *combBG, *combFG, *combCHAR;
    QCheckBox *chkCLR, *chkHOME;
    
    //QDialog *dlgDraw;

protected slots:

    void slotComboBGActivated(int);
    void slotComboFGActivated(int);
    void slotComboCHARActivated(int);
    
    void slotSaveAnsi();
    void slotSaveAscii();
    
    void slotLoadAnsi();
    void slotLoadAscii();

    void slotQuit();
    
    void slotWidth( int );
    void slotClear();
    void slotAbout();
    
    void slotMoveRight();
    void slotMoveLeft();
    void slotMoveUp();
    void slotMoveDown(); 
    void slotHCenter();
    void slotVCenter();
    
    void slotPlot();
    void slotLine();
    void slotBox();
    void slotFBox();
    void slotCircle();
    void slotFCircle();
    void slotScribble();
    void slotDScribble();

};

#endif
