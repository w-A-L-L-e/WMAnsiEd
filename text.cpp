/***************************************************************************
                          text.cpp - drawing functions and screen storage
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


#include "text.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

extern "C"{
  #include <stdio.h>
}



Text::Text() {
	for (int y = 0;y < 25; y++)
	for (int x = 0;x < 80; x++) {
		contents[y][x] = 32;
		fg[y][x] = 0;
		bg[y][x] = 0;
	}
}

Text::~Text(){

}

Text::Text(const Text& tex){
  if(&tex !=this){
    for (int y = 0;y < 25; y++)
	  for (int x = 0;x < 80; x++) {
		  contents[y][x] = tex.contents[y][x];
		  fg[y][x] = tex.fg[y][x];
		  bg[y][x] = tex.bg[y][x];
	  }
	  scrClear=tex.scrClear;
	  scrHome=tex.scrHome;
  }
}

Text& Text::operator=(const Text& tex){
    for (int y = 0;y < 25; y++)
	  for (int x = 0;x < 80; x++) {
		  contents[y][x] = tex.contents[y][x];
		  fg[y][x] = tex.fg[y][x];
		  bg[y][x] = tex.bg[y][x];
	  }
	  scrClear=tex.scrClear;
	  scrHome=tex.scrHome;                
  return *this;
}

void Text::clear(){
  for(int y=0;y<25;y++){
    for(int x=0;x<80;x++){
      set(x,y,32,0,7); //32 = ascii waarde voor spatie
    }
  }

}


void Text::set(int x, int y, int character, int bgc, int fgc) {
	contents[y][x] = character;
	fg[y][x] = fgc;
	bg[y][x] = bgc;
}

int Text::get(int x, int y) {
	return contents[y][x];
}

int Text::getBG(int x, int y) {
	return bg[y][x];
}

int Text::getFG(int x, int y) {
	return fg[y][x];
}


void Text::moveRight(){
  for(int y=0;y<25;y++){
    for(int x=79;x>0;x--){
      set(x,y,get(x-1,y),getBG(x-1,y),getFG(x-1,y));
    }
  }
  for(int y=0;y<25;y++){
    set(0,y,32,0,7);
  }
}

void Text::moveLeft(){
  for(int y=0;y<25;y++){
    for(int x=0;x<79;x++){
      set(x,y,get(x+1,y),getBG(x+1,y),getFG(x+1,y));
    }
  }
  for(int y=0;y<25;y++){
    set(79,y,32,0,7);
  }
}
void Text::moveUp(){
  for(int y=0;y<24;y++){
    for(int x=0;x<80;x++){
      set(x,y,get(x,y+1),getBG(x,y+1),getFG(x,y+1));
    }
  }
  for(int x=0;x<80;x++){
    set(x,24,32,0,7);
  }
}

void Text::moveDown(){
  for(int y=24;y>0;y--){
    for(int x=0;x<80;x++){
      set(x,y,get(x,y-1),getBG(x,y-1),getFG(x,y-1));
    }
  }
  for(int x=0;x<80;x++){
    set(x,0,32,0,7);
  }
}

void Text::moveHCenter(){
  int minLeft=79,maxRight=0;
  int x;
  for(int y=0;y<25;y++){
    x=0;
    while(x<80){
      if((get(x,y)!=32)||(getBG(x,y)!=0)){
        if(x<minLeft){ 
          minLeft=x;
        }
      }
      x++;
    }
    x=79;
    while(x>=0){
      if((get(x,y)!=32)||(getBG(x,y)!=0)){
        if(x>maxRight){ 
          maxRight=x;
        }
      }
      x--;
    }
  }
  for(int i=0;i<((79-maxRight)-minLeft)/2;i++) moveRight();
  for(int i=0;i<(minLeft-(79-maxRight))/2;i++) moveLeft();
}

void Text::moveVCenter(){
  int minUp=24,maxDown=0;
  int y;
  for(int x=0;x<80;x++){
    y=0;
    while(y<25){
      if((get(x,y)!=32)||(getBG(x,y)!=0)){
        if(y<minUp){ 
          minUp=y;
        }
      }
      y++;
    }
    y=24;
    while(y>=0){
      if((get(x,y)!=32)||(getBG(x,y)!=0)){
        if(y>maxDown){ 
          maxDown=y;
        }
      }
      y--;
    }
  }
  for(int i=1;i<((24-maxDown)-minUp)/2;i++) moveDown();
  for(int i=0;i<(minUp-(24-maxDown))/2;i++) moveUp();

}


void Text::print() {
	cout << "\n";
	for (int y = 0;y < 25; y++) {
		for (int x = 0;x < 80; x++)
			cout << (char)get(x,y);
		cout << "\n";
	}	
}



int Text::nonSpaceCharsC(int linenr){
  int xpos=0,x=80;
  while((xpos==0)&&(x!=0)){
    x--;
    if((get(x,linenr)!=32)||(getBG(x,linenr)!=0)){
      xpos=x;
    }
  }
  return xpos;
}

int Text::yEndC(){

  int y=25,ypos=-1;
  while((y!=0)&&(ypos==-1)){
    y--;
    if(nonSpaceCharsC(y)!=0) ypos=y;
  }
  return ypos;
}

int Text::nonSpaceChars(int linenr){
  int xpos=0,x=80;
  while((xpos==0)&&(x!=0)){
    x--;
    if(get(x,linenr)!=32) xpos=x;
  }
  return xpos;
}

int Text::yEnd(){

  int y=25,ypos=-1;
  while((y!=0)&&(ypos==-1)){
    y--;
    if(nonSpaceChars(y)!=0) ypos=y;
  }
  return ypos;
}


void Text::writeAnsi(ofstream& outfile,bool bClr,bool bHome){
  
  int oldfg=-1,oldbg=-1;
  
  
  if (bClr) outfile<<"[2J";  //wis scherm code
  if (bHome) outfile<<"[0;0H"; //zet cursor op pos 0,0
  
  outfile<<"(U"; //speciaal karakter om dos ascii te kunnen tonen

  outfile<<"[0m"; //normale modus
	for (int y = 0;y <=yEndC(); y++) {
		for (int x = 0;x <= nonSpaceCharsC(y); x++) {
		    if((getFG(x,y)==oldfg)&&(getBG(x,y)==oldbg)){
		      outfile<<(char)get(x,y);
		    }
		    else{
		      if(getFG(x,y)>7){
		        outfile<<"[1m"<<"[3"<< getFG(x,y)-8;
          }
          else{
            if(oldfg>7){
              outfile<< "[0m"<< "[3" <<getFG(x,y);
            }
            else{
              outfile<< "[3" <<getFG(x,y);
            }
          }		      
		      outfile<< ";4" <<getBG(x,y) << "m";
			    outfile<< (char)get(x,y);
			    oldfg=getFG(x,y);
			    oldbg=getBG(x,y);
			  }
			}
		  outfile <<"[0m" <<"\n";
		  oldfg=-1;
		  oldbg=-1;
	}
	outfile<<"[0m";
}

void Text::writeAscii(ofstream& outfile){
	for (int y = 0;y <=yEnd(); y++) {
		for (int x = 0;x <= nonSpaceChars(y); x++) {
			outfile << (char)get(x,y);
	  }
	  outfile<<endl;
	}
}


void Text::parseEsc(int& x, int& y,ifstream& infile,int& bgcolor,int& fgcolor,bool& bold){ 
  scrHome=0;
  scrClear=0;
  bool done=0;
  string str="";
  bool fgset=0;
  bool bgset=0;
  int c=' ';
  
  //this will get the numbers from escape sequence ex: 34;41 from input and puts them in str
  if(!infile.eof()) c=infile.get();
  if(c=='['){
    while(!infile.eof()&&!done){
      c=infile.get();
      if(!isalpha((char)c)){
        str+=(char)c;
      }
      else{
        done=1;
      }
    }
  }
  else if(c=='('){ 
      //voor (U special linux code to set terminal to dos ansi
      if(!infile.eof()) c=infile.get();
  }
  else{
    cerr<<"skipping unsupported escape sequence\n";
  }
  
  //cerr<<"number string  "<<str<<endl;
  //cerr<<"char after str "<<(char)c<<endl;
  
  
  //check what action has to be done with the numbers in str
  if(c=='m'){
    string::size_type i=0;
    while( i < str.length() ){
      switch(str[i]){
        case('0'): bold=0; break;
        case('1'): bold=1; break;
        case('3'): if(i+1<str.length()){i++;fgcolor=(int)(str[i])-48;} fgset=1;break;
        case('4'): if(i+1<str.length()){i++;bgcolor=(int)(str[i])-48;} bgset=1;break;
        case(';'): break;
        default: cerr<<"unsupported escape sequence "<<str<<"\n";
      }
      i++;
    }
    if(fgset&&!bgset) bgcolor=0; //some people actually use this
    //gset&&!fgset) fgcolor=0;
  }
  else if(c=='J'){
    if(str[0]=='2'){
      scrClear=1;
    }
    else{
      cerr<<"unknown sequence"<<str<<(char) c<<endl;
    }
  }
  else if((c=='H')||(c=='f')){
    if(str=="0;0"){
      scrHome=1;
    }
    else{
      cerr<<"Only cursor move 0;0 supported !";
    }
  }
  else if(c=='A'){ // cursor up
    int val=0;
    int basis=1;
    for(int n=str.length()-1;n>=0;n--){
      val+=((int)str[n]-48)*basis;
      basis=basis*10;
    }
    if(val==0) val=1;
    y-=val;
  }
  else if(c=='B'){ // cursor down
    int val=0;
    int basis=1;
    for(int n=str.length()-1;n>=0;n--){
      val+=((int)str[n]-48)*basis;
      basis=basis*10;
    }
    if(val==0) val=1;
    y+=val;
  }
  else if(c=='C'){ // cursor forward
    int val=0;
    int basis=1;
    for(int n=str.length()-1;n>=0;n--){
      val+=((int)str[n]-48)*basis;
      basis=basis*10;
    }
    if(val==0) val=1;
    x+=val;
    /*for(int n=0;n<val;n++){
      x++;
      if(x>79){
        x=0;
        y++;
      }
    }*/
  }
  else if(c=='D'){ // cursor back
    int val=0;
    int basis=1;
    for(int n=str.length()-1;n>=0;n--){
      val+=((int)str[n]-48)*basis;
      basis=basis*10;
    }
    if(val==0) val=1;
    x-=val;
    /*for(int n=0;n<val;n++){
      x--;
      if(x<0){
        x=79;
        y--;
      }
    }*/
  }
  else{
    if(c!='U') cerr<<"Unsupported escape sequence: "<<str<<(char) c<<" skipped"<<endl;
  }
}



void Text::loadAnsi(ifstream& infile){
  clear();
  int x=-1,y=0;
  int c;
  int bgcolor=0,fgcolor=7;
  bool bold=0;
  scrClear=0;
  scrHome=0;
  //set(0,0,(int)'#',0,7);
  while(!infile.eof()&&(y<25)){
    //set(0,0,(int)'X',0,7);
    c=infile.get();
    if(!infile.eof()){ 
      x++;
      if(c=='\n'){
        y++;
        x=-1;
      }
      else if(c==13){} //Stupid dos newline fuck THAT SHIT!
      else if(c==''){
        x--;
        parseEsc(x,y,infile,bgcolor,fgcolor,bold);
      }
      else if((y<25)&&(x<80)&&(x>=0)&&(y>=0)){
        if(!bold) set(x,y,c,bgcolor,fgcolor);
        else set(x,y,c,bgcolor,fgcolor+8);
      }
    }
  }
}	

void Text::loadAscii(ifstream& infile){
  clear();
  int x=-1,y=0;
  int c;
  //set(0,0,(int)'#',0,7);
  while(!infile.eof()&&(y<25)){
    //set(0,0,(int)'X',0,7);
    c=infile.get();
    x++;
    if(c=='\n'){
      y++;
      x=-1;
    }
    else if((y<25)&&(x<80)){
      set(x,y,c,0,7);
    }
  }
}

void Text::swap(int& a,int& b){
  int temp=a;
  a=b;
  b=temp;
}

void Text::drawFBox(const QPoint& a, const QPoint& b,int chr,int bgcol,int fgcol){

  int xa=a.x(),ya=a.y(),xb=b.x(),yb=b.y();
  if(xa>xb) swap(xa,xb);
  if(ya>yb) swap(ya,yb);
  for(int y=ya;y<=yb;y++){
    for(int x=xa;x<=xb;x++){
      set(x,y,chr,bgcol,fgcol);
    }  
  }  
}


void Text::drawBox(const QPoint& a, const QPoint& b,int chr,int bgcol,int fgcol){

  int xa=a.x(),ya=a.y(),xb=b.x(),yb=b.y();
  if(xa>xb) swap(xa,xb);
  if(ya>yb) swap(ya,yb);
  for(int y=ya;y<=yb;y++){ 
    set(xa,y,chr,bgcol,fgcol);
    set(xb,y,chr,bgcol,fgcol);
  }
  for(int x=xa;x<=xb;x++){
    set(x,ya,chr,bgcol,fgcol);
    set(x,yb,chr,bgcol,fgcol);
  }  
}


void Text::drawClipped(int x,int y,int chr,int bgcol,int fgcol){
  if ((x>=0) && (x<80) && (y>=0) && (y<25)) set(x,y,chr,bgcol,fgcol);
}


/* 

een klein bonusje
ik was moe en heb circle geimplementeerd maar achteraf toch maar ellipse gemaakt
en dan werd circle overbodig .... ben te lui om de naam te veranderen...

void Text::CirclePoints(int x,int y, int chr, int bgcol, int fgcol,int cx,int cy){
  drawClipped(x+cx,y+cy,chr,bgcol,fgcol);
  drawClipped(y+cx,x+cy,chr,bgcol,fgcol);
  drawClipped(x+cx,-y+cy,chr,bgcol,fgcol);
  drawClipped(y+cx,-x+cy,chr,bgcol,fgcol);
  drawClipped(-x+cx,y+cy,chr,bgcol,fgcol);
  drawClipped(-y+cx,x+cy,chr,bgcol,fgcol);
  drawClipped(-x+cx,-y+cy,chr,bgcol,fgcol);
  drawClipped(-y+cx,-x+cy,chr,bgcol,fgcol);
}
void Text::drawCircle(const QPoint& a, const QPoint& b,int chr,int bgcol,int fgcol){
  int x=0;
  int radius=sqrt(abs(b.x()-a.x())*abs(b.x()-a.x())+abs(b.y()-a.y())*abs(b.y()-a.y()));
  int y= radius;
  int d=1-radius;
  CirclePoints(x,y,chr,bgcol,fgcol,a.x(),a.y());
  
  while(y>x){
    if(d<0){
      d+=2*x+3;
    }
    else{
      d+=2*(x-y)+5;
      y--;
    }
    x++;
    CirclePoints(x,y,chr,bgcol,fgcol,a.x(),a.y());
  }
}
void Text::drawFCircle(const QPoint& a, const QPoint& b,int chr,int bgcol,int fgcol){
  int x=0;
  int radius=abs(b.x()-a.x());
  int y= radius;
  int d=1-radius;
  CirclePoints(x,y,chr,bgcol,fgcol,a.x(),a.y());
  
  while(y>x){
    if(d<0){
      d+=2*x+3;
    }
    else{
      d+=2*(x-y)+5;
      y--;
    }
    x++;
    CirclePoints(x,y,chr,bgcol,fgcol,a.x(),a.y());
  }
}
*/




void Text::CirclePoints(int x,int y, int chr, int bgcol, int fgcol,int cx,int cy){
  drawClipped(x+cx,y+cy,chr,bgcol,fgcol);
  drawClipped(x+cx,-y+cy,chr,bgcol,fgcol);
  drawClipped(-x+cx,y+cy,chr,bgcol,fgcol);
  drawClipped(-x+cx,-y+cy,chr,bgcol,fgcol);
}

void Text::CircleLines(int x,int y, int chr, int bgcol, int fgcol,int cx,int cy){
  QPoint a,b;
  a.setX(x+cx); a.setY(y+cy);
  b.setX(x+cx); b.setY(-y+cy);
  drawLine(a,b,chr,bgcol,fgcol);
  
  a.setX(-x+cx); a.setY(y+cy);
  b.setX(-x+cx); b.setY(-y+cy);
  drawLine(a,b,chr,bgcol,fgcol);

}

void Text::drawCircle(const QPoint& ap, const QPoint& bp,int chr,int bgcol,int fgcol){
  int a=abs(ap.x()-bp.x());
  int b=abs(ap.y()-bp.y());
  int x=0;
  int y=b;
  double d1=b*b-(a*a*b)+(0.25*a*a);
  CirclePoints(x,y,chr,bgcol,fgcol,ap.x(),ap.y());    
  while(a*a*(y-0.5)>b*b*(x+1)){
    if(d1<0)
      d1+=b*b*(2*x+3);
    else{
      d1+=b*b*(2*x+3)+a*a*(-2*y+2);
      y--; 
    }
    x++;
    CirclePoints(x,y,chr,bgcol,fgcol,ap.x(),ap.y());
  }
  double d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
  while(y>0){
    if(d2<0){
      d2+=b*b*(2*x+2)+a*a*(-2*y+3);
      x++;
    }
    else
      d2+=a*a*(-2*y+3);
    y--;
    CirclePoints(x,y,chr,bgcol,fgcol,ap.x(),ap.y());
  }
}

void Text::drawFCircle(const QPoint& ap, const QPoint& bp,int chr,int bgcol,int fgcol){
  int a=abs(ap.x()-bp.x());
  int b=abs(ap.y()-bp.y());
  int x=0;
  int y=b;
  double d1=b*b-(a*a*b)+(0.25*a*a);
  CircleLines(x,y,chr,bgcol,fgcol,ap.x(),ap.y());    
  while(a*a*(y-0.5)>b*b*(x+1)){
    if(d1<0)
      d1+=b*b*(2*x+3);
    else{
      d1+=b*b*(2*x+3)+a*a*(-2*y+2);
      y--; 
    }
    x++;
    CircleLines(x,y,chr,bgcol,fgcol,ap.x(),ap.y());
  }
  double d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
  while(y>0){
    if(d2<0){
      d2+=b*b*(2*x+2)+a*a*(-2*y+3);
      x++;
    }
    else
      d2+=a*a*(-2*y+3);
    y--;
    CircleLines(x,y,chr,bgcol,fgcol,ap.x(),ap.y());
  }
}









int Text::abs(int i){
  if (i<0) i=-i;
  return i;
}

void Text::vLine(int xa,int ya,int yb,int chr,int bgcol,int fgcol){
  if (ya>yb) swap(ya,yb);
  for(int y=ya;y<=yb;y++){
    drawClipped(xa,y,chr,bgcol,fgcol);    
  }
}

void Text::hLine(int xa,int xb,int ya,int chr,int bgcol,int fgcol){
  if (xa>xb) swap(xa,xb);
  for(int x=xa;x<=xb;x++){
    drawClipped(x,ya,chr,bgcol,fgcol);    
  }
}



void Text::drawLine(const QPoint& a, const QPoint& b,int chr,int bgcol,int fgcol){
  int xa=a.x(),ya=a.y(),xb=b.x(),yb=b.y();
  float x,y,m;
  int dx,dy,inc;
  dx= xb-xa;
  dy= yb-ya;
  if(dx==0){
    vLine(xa,ya,yb,chr,bgcol,fgcol);
  }
  else if(dy==0){  
    hLine(xa,xb,ya,chr,bgcol,fgcol);
  }
  else if(abs(dx)>=abs(dy)){
    m=(float)dy/(float)dx;
    inc=1;
    if(dx<0){
      inc=-1;
      m=-m;
    }
    y=ya*1.00001;
    drawClipped(xa,(int)(y+0.5),chr,bgcol,fgcol);
    while(xa!=xb){
      y=y+m;
      xa+=inc;
      drawClipped(xa,(int)(y+0.5),chr,bgcol,fgcol);
      //cerr<<"dx>=dy "<<xa<<" "<<y<<endl;
    }    
  }
  else{
    m=(float)dx/(float)dy;
    inc=1;
    if(dy<0){
      inc=-1;
      m=-m;
    }
    x=xa*1.00001;
    drawClipped((int)(x+0.5),ya,chr,bgcol,fgcol);
    while(ya!=yb){
      x=x+m;
      ya+=inc;
      drawClipped((int)(x+0.5),ya,chr,bgcol,fgcol);
      //cerr<<x<<ya<<endl;
    }    
  }   

}

void Text::drawScribble (const QPoint& , const QPoint& ,int ,int ,int ){}
void Text::drawDScribble(const QPoint& , const QPoint& ,int ,int ,int ){}

bool Text::getScrClear(){
  return scrClear;
}

bool Text::getScrHome(){
  return scrHome;
}


