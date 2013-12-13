/***************************************************************************
                          canvas.h - drawing in QPixmap
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


#ifndef CANVAS_H
#define CANVAS_H

#include <qpen.h>
#include <qpoint.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qstring.h>
#include <q3pointarray.h>
//Added by qt3to4:
#include <QResizeEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include "text.h"
#include "IBMFont.h"

class QMouseEvent;
class QResizeEvent;
class QPaintEvent;

enum drawTypes {plot,line,box,fbox,circle,fcircle,scribble,dscribble};


class Canvas : public QWidget
{
    Q_OBJECT
    
private:
	int fgColor, bgColor;

public:
    Text t,backupt;
    Canvas( QWidget *parent = 0, const char *name = 0 );
    ~Canvas();

    void setPenColor( const QColor &c )
    { pen.setColor( c ); }

    void setPenWidth( int w )
    { pen.setWidth( w ); }

    QColor penColor()
    { return pen.color(); }

    int penWidth()
    { return pen.width(); }

    void save( const QString &filename, const QString &format );

    void clearScreen();
    void updateScreen();

    void setText(int);
    void setBackground(int);
    void setForeground(int);

    void setDrawMode(drawTypes);
    void Plot(QMouseEvent *e);
    void drawShape(QMouseEvent *e,bool);
    

protected:
    void mousePressEvent( QMouseEvent *e );
    void mouseReleaseEvent( QMouseEvent *e );
    void mouseMoveEvent( QMouseEvent *e );
    void resizeEvent( QResizeEvent *e );
    void paintEvent( QPaintEvent *e );
    void draw(int, int);
    void redraw();
    void drawChanged(Text*);

    QPen pen;
    int text;
    QPoint point,startP,stopP;
    IBMFont font;
    
    bool mousePressed;

    QPixmap buffer;
    
    drawTypes dmode;
    int fontsizeX;
    int fontsizeY;
private:
    void execDrawMode(QMouseEvent *e,bool);
    void toMatrixCoords(QPoint&);
};

#endif

