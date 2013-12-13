/***************************************************************************
                          canvas.cpp - drawing in QPixmap
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


#include "canvas.h"
#include "palette.h"

#include <qevent.h>
#include <qpainter.h>
#include <q3toolbar.h>
#include <qtoolbutton.h>
#include <qspinbox.h>
#include <qtooltip.h>
#include <qrect.h>
#include <qpoint.h>
#include <qcolordialog.h>
#include <q3filedialog.h>
#include <qcursor.h>
#include <qimage.h>
#include <q3strlist.h>
#include <q3popupmenu.h>
#include <q3intdict.h>
#include <qpixmap.h>
//Added by qt3to4:
#include <QPaintEvent>
#include <QResizeEvent>
#include <QMouseEvent>
#include <iostream>

Canvas::Canvas( QWidget *parent, const char *name )
    : QWidget( parent, name ), pen( Qt::white, 1 ), 
      mousePressed( FALSE ), buffer( width(), height() )
{
    fgColor = 7;
    bgColor = 0;
    //this->resize(640,440);
    buffer.fill( Qt::black );
    setBackgroundMode( Qt::NoBackground );
    setCursor( Qt::crossCursor );
    dmode=plot;
    //t();
    
}

Canvas::~Canvas(){

}

void Canvas::toMatrixCoords(QPoint &a){
  int x=a.x()/fontsizeX;
  int y=a.y()/fontsizeY;
  
  if(x<0) x=0;
  if(x>79) x=79;
  if(y<0) y=0;
  if(y>24) y=24;
  
  a.setX(x);
  a.setY(y);
}


void Canvas::save( const QString &filename, const QString &format )
{
    buffer.save( filename, format.upper() );
}

void Canvas::clearScreen() {
    t.clear();
    redraw();
    //repaint( FALSE );
    update();
}

void Canvas::updateScreen(){
  redraw();
  //repaint(FALSE);
  update();
}

void Canvas::mousePressEvent( QMouseEvent *e )
{
  mousePressed=TRUE;
  startP=e->pos();
  toMatrixCoords(startP);
  execDrawMode(e,FALSE);
}


void Canvas::execDrawMode(QMouseEvent *e,bool permanent){
   switch(dmode){
    case plot:
      Plot(e);
      break;      
    case scribble:
      break;
    case dscribble:
      break;
    default: 
      drawShape(e,permanent);
    }

}

void Canvas::mouseReleaseEvent( QMouseEvent *e )
{
    stopP=e->pos();
    toMatrixCoords(stopP);
    execDrawMode(e,TRUE);
    mousePressed = FALSE; 
}

void Canvas::draw(int x, int y) {
	int X=x;
	int Y=y;
	x=x/fontsizeX;
	y=y/fontsizeY;
	if ((x>=0) && (x<=79) && (y>=0) && (y<=24)) {
		      QPainter painter;
	        painter.begin( &buffer );
	        
	        //achtergrond
	        QPixmap back(fontsizeX,fontsizeY);
	        back.fill(Palette(bgColor).getColor());

          //voorgrond
          QPixmap fore(fontsizeX,fontsizeY);
          fore.fill(Palette(fgColor).getColor());
          
          //character
          QPixmap chr(font.getChar(text));
          // aaah...  bit blits where is my amiga with that good ol' copper and blitter chip :-)
	        //bitBlt(&fore,0,0,&chr,0,0,fontsizeX,fontsizeY,  QPainter::CompositionMode_SourceOver ); //Qt::AndROP); //dit zet de foreground van de char
	        //bitBlt(&back,0,0,&chr,0,0,fontsizeX,fontsizeY,  QPainter::CompositionMode_DestinationOver );//Qt::NotAndROP); //background met zwart char
	        //bitBlt(&fore,0,0,&back,0,0,fontsizeX,fontsizeY, QPainter::CompositionMode_Xor);//Qt::OrROP); //dit zet de achtergrond van de char

          //painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
          //painter.fillRect( back.rect(), Palette(bgColor).getColor() );
          QImage charResult( fontsizeX, fontsizeY, QImage::Format_ARGB32_Premultiplied);
          QPainter p( &charResult );

          p.setCompositionMode( QPainter::CompositionMode_Source ); 
          p.fillRect(charResult.rect(), Qt::transparent);
          p.setCompositionMode(QPainter::CompositionMode_SourceOver);
          p.drawImage( 0,0, back );
          p.setCompositionMode(QPainter::CompositionMode_DestinationOver );
          p.drawImage(0,0,chr );
          //p.setCompositionMode(QPainter::CompositionMode_DestinationOver);
          //p.fillRect(charResult.rect(), Qt::white);
          p.end(); 

          painter.drawPixmap( QPoint(X,Y), QPixmap::fromImage(charResult));
          //painter.drawPixmap( QPoint(X,Y), back );
          //painter.drawPixmap( QPoint(X,Y), chr  );
          //painter.end();
          
          /*
           QPainter::CompositionMode mode = currentMode();
           QPainter painter(&resultImage);
           painter.setCompositionMode(QPainter::CompositionMode_Source);
           painter.fillRect(resultImage.rect(), Qt::transparent);
           painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
           painter.drawImage(0, 0, destinationImage);
           painter.setCompositionMode(mode);
           painter.drawImage(0, 0, sourceImage);
           painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
           painter.fillRect(resultImage.rect(), Qt::white);
           painter.end();
           resultLabel->setPixmap(QPixmap::fromImage(resultImage));
           */
	        
	        //painter.drawPixmap(QPoint(X,Y),back);
	        //painter.drawPixmap(QPoint(X,Y),chr); 
	        
	        
	        setPenColor(Palette(7-bgColor).getColor());
	        painter.setPen( pen );
	        painter.drawPoint(X,Y);
	        painter.drawPoint(X+fontsizeX,Y);
	        painter.drawPoint(X,Y+fontsizeY);
	        painter.drawPoint(X+fontsizeX,Y+fontsizeY);
	
        
	        painter.end();

	        //bitBlt( this, X, Y, &buffer, X, Y, fontsizeX, fontsizeY );
	        t.set(x, y, text, bgColor, fgColor);
          update();
	}
}




void Canvas::redraw() {
          buffer.fill(Qt::black);
		      QPainter painter;
		      painter.begin(&buffer);
		      QPixmap fore(fontsizeX,fontsizeY);
		      QPixmap back(fontsizeX,fontsizeY);
		      int oldbg=0,oldfg=7;
		      back.fill(Palette(0).getColor());
		      fore.fill(Palette(7).getColor());
	        for (int y=0;y<25;y++){
	          for (int x=0;x<80;x++){
	            int X=x*fontsizeX;
		          int Y=y*fontsizeY;
	            
	            
	            //achtergrond
	            back.fill(Palette(t.getBG(x,y)).getColor());
              oldbg=t.getBG(x,y);
              
              //voorgrond kleur
              fore.fill(Palette(t.getFG(x,y)).getColor());
              oldfg=t.getFG(x,y);
              
              QPixmap chr(font.getChar(t.get(x,y)));
              
              // aaah...  bit blits where is my amiga with that good ol' copper and blitter chip :-)
	 //           bitBlt(&fore,0,0,&chr,0,0,fontsizeX,fontsizeY,Qt::AndROP); //dit zet de foreground van de char
	  //          bitBlt(&back,0,0,&chr,0,0,fontsizeX,fontsizeY,Qt::NotAndROP); //background met zwart char
	   //         bitBlt(&fore,0,0,&back,0,0,fontsizeX,fontsizeY,Qt::OrROP); //dit zet de achtergrond van de char	        
		            bitBlt(&fore,0,0,&chr,0,0,fontsizeX,fontsizeY,  QPainter::CompositionMode_SourceOver ); //Qt::AndROP); //dit zet de foreground van de char
	              bitBlt(&back,0,0,&chr,0,0,fontsizeX,fontsizeY,  QPainter::CompositionMode_SourceOver );//Qt::NotAndROP); //background met zwart char
	              bitBlt(&fore,0,0,&back,0,0,fontsizeX,fontsizeY, QPainter::CompositionMode_DestinationOver);//Qt::OrROP); //dit zet de achtergrond van de char
	        
	            painter.drawPixmap(QPoint(X,Y),fore);
	        
	             

	            setPenColor(Palette(7-t.getBG(x,y)).getColor());
	            painter.setPen( pen );
	            painter.drawPoint(X,Y);
	            painter.drawPoint(X+fontsizeX,Y);
	            painter.drawPoint(X,Y+fontsizeY);
	            painter.drawPoint(X+fontsizeX,Y+fontsizeY);
	          }
          }
          painter.end();

	        bitBlt( this, 0, 0, &buffer, 0, 0, width(), height() );
}



void Canvas::drawChanged(Text* nt){
  //alleen chars van t die verschillen van tbackup tekenen
		      QPainter painter;
		      /*painter.begin(&buffer);*/
		      QPixmap fore(fontsizeX,fontsizeY);
		      QPixmap back(fontsizeX,fontsizeY);
		      back.fill(Palette(0).getColor());
		      fore.fill(Palette(7).getColor());
	        for (int y=0;y<25;y++){
	          for (int x=0;x<80;x++){
	            if( (t.get(x,y)!=nt->get(x,y))    ||
	               (t.getFG(x,y)!=nt->getFG(x,y)) ||
	               (t.getBG(x,y)!=nt->getBG(x,y)) ) {
	                  int X=x*fontsizeX;
		                int Y=y*fontsizeY;

      	            //achtergrond
	                  back.fill(Palette(nt->getBG(x,y)).getColor());

                    //voorgrond kleur
                    fore.fill(Palette(nt->getFG(x,y)).getColor());
                    QPixmap chr(font.getChar(nt->get(x,y)));
                    // aaah...  bit blits where is my amiga with that good ol' copper and blitter chip :-)
      	            //bitBlt(&fore,0,0,&chr,0,0,fontsizeX,fontsizeY,Qt::AndROP); //dit zet de foreground van de char
	                  //bitBlt(&fore,0,0,&back,0,0,fontsizeX,fontsizeY,Qt::OrROP); //dit zet de achtergrond van de char
	        		      bitBlt(&fore,0,0,&chr,0,0,fontsizeX,fontsizeY,  QPainter::CompositionMode_SourceOver ); //Qt::AndROP); //dit zet de foreground van de char
	                  bitBlt(&back,0,0,&chr,0,0,fontsizeX,fontsizeY,  QPainter::CompositionMode_DestinationOver );//Qt::NotAndROP); //background met zwart char
	
	                  //painter.drawPixmap(QPoint(X,Y),fore);
	                  //setPenColor(Palette(7-t.getBG(x,y)).getColor());
	                  /*painter.setPen( pen );
	                  painter.drawPoint(X,Y);
	                  painter.drawPoint(X+fontsizeX,Y);
	                  painter.drawPoint(X,Y+fontsizeY);
	                  painter.drawPoint(X+fontsizeX,Y+fontsizeY);
	                  */
                    bitBlt( this, X, Y, &fore, 0, 0, fontsizeX, fontsizeY );
              }
	          }
          }
          //painter.end();
}



void Canvas::setDrawMode(drawTypes d){
  dmode=d;  
}


// ja ik weet het deze Plot sucked ... maar ja heeft de mooby gedaan geen goesting om ze te veranderen ;-)
void Canvas::Plot(QMouseEvent *e){
    if ( mousePressed ) {
        point = e->pos();
        point.setX((point.x() / fontsizeX) * fontsizeX);
        point.setY((point.y() / fontsizeY) * fontsizeY);
        draw(point.x(), point.y());
        /*t.set(point.x(),point.y(),text,bgColor,fgColor);
        drawChanged(t);*/
    }
}

void Canvas::drawShape(QMouseEvent *e,bool permanent){
  
  if(mousePressed){
    Text* newt=new Text;
    for(int y=0;y<25;y++)
    for(int x=0;x<80;x++){
      newt->set(x,y,t.get(x,y),t.getBG(x,y),t.getFG(x,y));
    }
    //cerr<<"newt inited"<<endl;
    stopP=e->pos();
    toMatrixCoords(stopP);
    switch(dmode){
      case line: t.drawLine(startP,stopP,text,bgColor,fgColor); break;
      case box: t.drawBox(startP,stopP,text,bgColor,fgColor); break;
      case fbox: t.drawFBox(startP,stopP,text,bgColor,fgColor); break;
      case circle: t.drawCircle(startP,stopP,text,bgColor,fgColor); break;
      case fcircle: t.drawFCircle(startP,stopP,text,bgColor,fgColor); break;
      case scribble: t.drawScribble(startP,stopP,text,bgColor,fgColor); break;
      case dscribble: t.drawDScribble(startP,stopP,text,bgColor,fgColor); break;
      
      default:;
      
    }
    //cerr<<"wf"<<endl;
    redraw(); //te traag
    //drawChanged(newt);
    if(!permanent){
      for(int y=0;y<25;y++)
      for(int x=0;x<80;x++){
        t.set(x,y,newt->get(x,y),newt->getBG(x,y),newt->getFG(x,y));
      }
    } // ne gore maar plezanten truuk :)
  }
}


void Canvas::mouseMoveEvent( QMouseEvent *e )
{
  execDrawMode(e,FALSE);
}



void Canvas::resizeEvent( QResizeEvent *e )
{
    QWidget::resizeEvent( e );
    int w = 640;
    int h = 440;
    fontsizeX=8;
    fontsizeY=16;
    buffer.resize(w,h);
    redraw();
    //repaint();
    update();
}



void Canvas::paintEvent( QPaintEvent *e )
{
    QWidget::paintEvent( e );
    QRect r = e->rect();
    bitBlt( this, r.x(), r.y(), &buffer, r.x(), r.y(), r.width(), r.height() );
    update();
}

void Canvas::setText(int t) {
	text = t;
}

void Canvas::setBackground(int b) {
	bgColor = b;
}

void Canvas::setForeground(int f) {
	fgColor = f;
}
