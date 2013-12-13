#ifndef IBMFONT_H
#define IBMFONT_H

#include "qpixmap.h"
#include <vector>
using std::vector;

//class QPixmap;


class IBMFont{

 public:
  QPixmap *let,*f;
  IBMFont();
  ~IBMFont();
  
  QPixmap getChar(int);
  
 private: 
  vector<QPixmap> letters;

};

#endif
