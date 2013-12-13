/***************************************************************************
                          text.h - drawing functions and screen storage
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


#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<fstream>
#include<qpoint.h>

using namespace std;

class Text {
private:
	int contents [25][80];
	int bg [25][80];
	int fg [25][80];
	
public:
	Text();
	~Text();	
	Text(const Text&); //copy constructor
	void set(int,int,int,int,int);
	
	
	Text& operator=(const Text&);
	//Text& operator=(Text*);
	int get(int, int);
	int getBG(int, int);
	int getFG(int, int);
	
	void print();
	
	void clear();
	
	void writeAnsi(ofstream&,bool,bool);
	void writeAscii(ofstream&);
	
	void loadAnsi(ifstream&);
	void loadAscii(ifstream&);
  
  void moveRight();
  void moveLeft();
  void moveUp();
  void moveDown();
  
  void moveHCenter();
  void moveVCenter();
  bool getScrClear();
  bool getScrHome();
  void drawBox(const QPoint& ,const QPoint&,int,int,int);
  void drawFBox(const QPoint& ,const QPoint&,int,int,int);
  void drawLine(const QPoint& ,const QPoint&,int,int,int);
  void drawCircle(const QPoint& ,const QPoint&,int,int,int);
  void drawFCircle(const QPoint& ,const QPoint&,int,int,int);
  void drawScribble(const QPoint& ,const QPoint&,int,int,int);
  void drawDScribble(const QPoint& ,const QPoint&,int,int,int);
  

private:
  void parseEsc(int&,int&,ifstream&,int&,int&,bool&);
  int nonSpaceCharsC(int);
  int nonSpaceChars(int);
  void hLine(int,int,int,int,int,int);
  void vLine(int,int,int,int,int,int);
  int abs(int);
  
  int yEndC();
  int yEnd();
  void swap(int&,int&);
  void drawClipped(int,int,int,int,int);
  void CirclePoints(int,int,int,int,int,int,int);
  void CircleLines(int,int,int,int,int,int,int);
  bool scrClear;
  bool scrHome;
  bool IbmFont;
};

#endif

