/***************************************************************************
                          WMAnsiEd.cpp  -  description
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


#include "wmansied.h"
#include "IBMFont.h"

#include <iostream>
//Added by qt3to4:
#include <QKeyEvent>
using namespace std;


#include <qevent.h>
#include <qpainter.h>
#include <q3toolbar.h>
#include <qtoolbutton.h>
#include <qtooltip.h>
#include <qrect.h>
#include <qpoint.h>
#include <qmessagebox.h>
#include <q3filedialog.h>
#include <qfiledialog.h>
#include <qcursor.h>
#include <qimage.h>
#include <q3strlist.h>
#include <q3popupmenu.h>
#include <q3intdict.h>
#include <qpixmap.h>
#include "canvas.h"
#include <qcombobox.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qmenubar.h>
#include <qcheckbox.h>
#include "palette.h"

void WMAnsiEd::keyPressEvent( QKeyEvent *e) {
	if((e->ascii()>=32)&&(e->ascii()<=255)){
	  combCHAR->setCurrentItem(e->ascii()-32);
	  canvas.setText(e->ascii());
	}
}


WMAnsiEd::WMAnsiEd( QWidget *parent, const char *name )
    : Q3MainWindow( parent, name ), canvas( this )
{
    setCentralWidget( &canvas );
    
    Q3PopupMenu *load = new Q3PopupMenu(this);
      //load->insertTearOffHandle();
      load->insertItem("Open Ansi",this,SLOT(slotLoadAnsi()));
      load->insertItem("Open Ascii",this,SLOT(slotLoadAscii()));  

    Q3PopupMenu *save = new Q3PopupMenu(this);
      //save->insertTearOffHandle();
      save->insertItem("Save as Ansi",this,SLOT(slotSaveAnsi()));
      save->insertItem("Save as Ascii",this,SLOT(slotSaveAscii()));
      
    Q3PopupMenu *file = new Q3PopupMenu(this );
    menuBar()->insertItem( "&File", file );
       file->insertItem( "&Open", load, Qt::CTRL+Qt::Key_O );
       file->insertItem( "&Save", save, Qt::CTRL+Qt::Key_S );
       file->insertItem( "&Quit", this, SLOT( slotQuit() ) , Qt::CTRL+Qt::Key_Q );
    
    Q3PopupMenu *move = new Q3PopupMenu(this);
      //move->insertTearOffHandle();
      move->insertItem("Move &Left",this,SLOT(slotMoveLeft()),Qt::CTRL+Qt::Key_L);
      move->insertItem("Move &Right",this,SLOT(slotMoveRight()),Qt::CTRL+Qt::Key_R);
      move->insertItem("Move &Up",this,SLOT(slotMoveUp()),Qt::CTRL+Qt::Key_U);
      move->insertItem("Move &Down",this,SLOT(slotMoveDown()),Qt::CTRL+Qt::Key_D);
      move->insertItem("&HCenter",this,SLOT(slotHCenter()),Qt::CTRL+Qt::Key_H);
      move->insertItem("&VCenter",this,SLOT(slotVCenter()),Qt::CTRL+Qt::Key_V);
      
      
    Q3PopupMenu *edit = new Q3PopupMenu(this );
    menuBar()->insertItem( "&Edit", edit );
       edit->insertItem( "&Clear Screen", this,SLOT(slotClear()) ,Qt::CTRL+Qt::Key_X );
       edit->insertItem("&Move",move, Qt::CTRL+Qt::Key_M);
    
    
    Q3PopupMenu *drawmode = new Q3PopupMenu(this);
      //save->insertTearOffHandle();
      drawmode->insertItem("Plot",this,SLOT(slotPlot()));
      drawmode->insertItem("Line",this,SLOT(slotLine()));
      drawmode->insertItem("Box",this,SLOT(slotBox()));
      drawmode->insertItem("Filled Box",this,SLOT(slotFBox()));
      drawmode->insertItem("Ellipse",this,SLOT(slotCircle()));
      drawmode->insertItem("Filled Ellipse",this,SLOT(slotFCircle()));
      drawmode->insertItem("Scribble",this,SLOT(slotScribble()));
      drawmode->insertItem("Double Scribble",this,SLOT(slotDScribble()));
    
    Q3PopupMenu *options = new Q3PopupMenu(this );
    menuBar()->insertItem("&Options", options );
       options->insertItem("Draw Mode", drawmode);
       //options->insertItem("&Move",move, CTRL+Key_M);
    
    
     Q3PopupMenu *help = new Q3PopupMenu( this );
     menuBar()->insertItem("&Help", help );
       help->insertItem( "&About", this, SLOT(slotAbout()), Qt::CTRL+Qt::Key_A );
    
    
    
  //toolbar met char,bgcolor,fgcolor      
    Q3ToolBar *tools = new Q3ToolBar( this );
    tools->move(0,20);
    
    /*
     deze staan nu in het menu
      bSave = new QToolButton( tools, "Save", "Save as PNG image", this, SLOT( slotSave() ), tools );
      bSave = new QToolButton(tools,SLOT(slotSave()));
      bSave->setText( "Save as..." );
  
      bClear = new QToolButton( QPixmap(), "Clear Screen", "Clear Screen", this, SLOT( slotClear() ), tools );
      bClear->setText( "Clear Screen" );
    */
    
    tools->addSeparator();
    
       
    // Character input

    IBMFont font;    
    combCHAR = new QComboBox(tools,"Character Input");
    QToolTip::add( combCHAR, "Character Input" );   
    combCHAR->setFixedSize(40,25);
    for(int i=32;i<257;i++){
      //combCHAR->insertItem(QString(QChar(i)));
      combCHAR->insertItem(font.getChar(i));
    }
        
    combCHAR->setCurrentItem(3);
    connect( combCHAR, SIGNAL( activated( int ) ), this, SLOT( slotComboCHARActivated(int ) ) );     
 

    tools->addSeparator();


    #define ADD_LABEL( str, w, h )    \
    { QLabel *label = new QLabel(str,tools); \
      label->setFixedSize(w,h);\
      label->setAlignment(Qt::AlignCenter|Qt::AlignVCenter); }
                
  //Background colors


    
    QPixmap p( 10, 15 ); // -1 ); //, QPixmap::defaultOptimization());
    ADD_LABEL("BG",30,25);
    combBG = new QComboBox(tools,"Background Color");
    //combBG->setFixedSize(40,25);
    QToolTip::add( combBG, "Background Color" );   
      
    for(int i=0;i<8;i++){
      p.fill(Palette(i).getColor());
      combBG->insertItem(p);
    }
    
    

    connect( combBG, SIGNAL( activated( int ) ), this, SLOT( slotComboBGActivated(int ) ) );   

    tools->addSeparator();


  //Foreground colors
  
    ADD_LABEL("FG",30,25);
    combFG = new QComboBox(tools,"Foreground Color");
    combFG->setFixedSize(40,25);
    QToolTip::add( combFG, "Foreground Color" );   
        
    for(int i=0;i<16;i++){
      p.fill(Palette(i).getColor());
      combFG->insertItem(p);
    }
    combFG->setCurrentItem(7);
    connect( combFG, SIGNAL( activated( int ) ), this, SLOT( slotComboFGActivated(int ) ) );   
    
  tools->addSeparator();
    
    ADD_LABEL("CLR",50,25);
    chkCLR = new QCheckBox(tools,"ClearScr Char");
    QToolTip::add( chkCLR, "Insert clearscreen code" );   
    chkCLR->setChecked(FALSE);
    
  tools->addSeparator();
    
    ADD_LABEL("HOME",60,25);
    chkHOME = new QCheckBox(tools,"Home Char");
    QToolTip::add( chkHOME, "Insert curser home code" );   
    chkHOME->setChecked(FALSE);  
  
  tools->addSeparator();
  
  
  //initiele char zetten als spatie
    canvas.setText(35);
}


void WMAnsiEd::slotComboBGActivated(int index){
  canvas.setBackground(index);
}


void WMAnsiEd::slotComboFGActivated(int index){
  canvas.setForeground(index);
}

void WMAnsiEd::slotComboCHARActivated(int index){
  //cout<<index<<endl;
  canvas.setText(index+32);
}



void WMAnsiEd::slotSaveAnsi()
{

    QString filename = Q3FileDialog::getSaveFileName( QString::null, QString( "*.%1" ).arg(QString("ansi")), this );
    if ( !filename.isEmpty() ){
        ofstream file((const char*)filename);
        canvas.t.writeAnsi(file,chkCLR->isChecked(),chkHOME->isChecked());
    }
}


void WMAnsiEd::slotSaveAscii()
{

    QString filename = Q3FileDialog::getSaveFileName( QString::null, QString( "*.%1" ).arg(QString("ascii")), this );
    if ( !filename.isEmpty() ){
        ofstream file((const char*)filename);
        canvas.t.writeAscii(file);
    }
}


void WMAnsiEd::slotLoadAscii()
{

    //QString filename = Q3FileDialog::getOpenFileName( QString(""), QString( "*.%1" ).arg(QString("ascii")), this );
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    if ( !filename.isEmpty() ){
        ifstream file((const char*)filename.toAscii().data());
        canvas.t.loadAscii(file);
        canvas.updateScreen();
    }
}


void WMAnsiEd::slotLoadAnsi()
{

    //QString filename = Q3FileDialog::getOpenFileName( QString(""), QString( "*.%1" ).arg(QString("ansi")), this );
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    if ( !filename.isEmpty() ){
        ifstream file((const char*)filename.toAscii().data());
        canvas.t.loadAnsi(file);
        chkCLR->setChecked(canvas.t.getScrClear());  
        chkHOME->setChecked(canvas.t.getScrHome());
        canvas.updateScreen();
    }
}

void WMAnsiEd::slotQuit()
{
  this->close();
}

void WMAnsiEd::slotWidth( int w )
{
    canvas.setPenWidth( w );
}

void WMAnsiEd::slotClear()
{
    canvas.clearScreen();
}

void WMAnsiEd::slotAbout()
{
   QMessageBox::about( this, "WMAnsiEd",
         "          WMAnsiEd 1.0              \n\n"
         "  Programmed by: wALLe & MoobY      \n\n"  
         "  - wALLe  (Walter Schreppers)      \n"
         "     mail: walter@sitweb.eu         \n\n" 
         "  - MoobY (Anthony Liekens)         \n"
         "     mail: anthony@liekens.net       "
         );
}



void WMAnsiEd::slotMoveLeft(){
  canvas.t.moveLeft();
  canvas.updateScreen();
}


void WMAnsiEd::slotMoveRight(){
  canvas.t.moveRight();
  canvas.updateScreen();
}



void WMAnsiEd::slotMoveUp(){
  canvas.t.moveUp();
  canvas.updateScreen();
}


void WMAnsiEd::slotMoveDown(){
  canvas.t.moveDown();
  canvas.updateScreen();
}

void WMAnsiEd::slotHCenter(){
  canvas.t.moveHCenter();
  canvas.updateScreen();
}

void WMAnsiEd::slotVCenter(){
  canvas.t.moveVCenter();
  canvas.updateScreen();
}

void WMAnsiEd::slotPlot(){
  canvas.setDrawMode(plot);
}

void WMAnsiEd::slotLine(){
  canvas.setDrawMode(line);
}
void WMAnsiEd::slotBox(){
  canvas.setDrawMode(box);
}
void WMAnsiEd::slotFBox(){
  canvas.setDrawMode(fbox);
}
void WMAnsiEd::slotCircle(){
  canvas.setDrawMode(circle);
}
void WMAnsiEd::slotFCircle(){
  canvas.setDrawMode(fcircle);
}
void WMAnsiEd::slotScribble(){
  canvas.setDrawMode(scribble);
}
void WMAnsiEd::slotDScribble(){
  canvas.setDrawMode(dscribble);
}




