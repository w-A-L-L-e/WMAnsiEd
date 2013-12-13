#include "font.h"
#include "IBMFont.h"
#include <qpaintdevice.h>
#include <qpixmap.h>

IBMFont::IBMFont(){
  QPixmap *f= new QPixmap (font_xpm);
  
  for(int i=32;i<256;i++){
    if(i==127){
      QPixmap l(8,16);
      int x=0;
      int y=0;
      QPixmap letter = QPixmap(8,16);
      bitBlt(&letter,0,0,f,x,y,8,16);
      letters.push_back(letter);
    }
    else{
      QPixmap l(8,16);
      int x=((i-32)%32)*8;
      int y=((i-32)/32)*16;
      QPixmap letter = QPixmap(8,16);
      bitBlt(&letter,0,0,f,x,y,8,16);
      letters.push_back(letter);
    }
  }
}


IBMFont::~IBMFont(){
 /* while(letters.size()>0){
    letters.pop_back();
  }*/
  letters.clear();
}


QPixmap IBMFont::getChar(int pos){
  QPixmap p;
  if ( pos-32 < (int)letters.size() ){
    p = letters[pos-32];
  }
  return p;
}


