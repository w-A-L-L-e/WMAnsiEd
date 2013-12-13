#include <qcolor.h>
#include "palette.h"

Palette::Palette(int i){
	index = i;
}

int Palette::getIndex() {
	return index;
}

QColor Palette::getColor() {
	switch (index) {
		case 0:  return QColor(0,0,0,QColor::Rgb);        break;
		case 1:  return QColor(135,0,0,QColor::Rgb);      break; 
		case 2:  return QColor(0,135,0,QColor::Rgb);      break;
		case 3:  return QColor(135,70,0,QColor::Rgb);     break;
		case 4:  return QColor(0,0,128,QColor::Rgb);      break;
		case 5:  return QColor(128,0,128,QColor::Rgb);    break;
		case 6:  return QColor(0,128,128,QColor::Rgb);    break;
		case 7:  return QColor(135,135,135,QColor::Rgb);  break;
		case 8:  return QColor(100,100,100,QColor::Rgb);  break;
		case 9:  return QColor(255,0,0,QColor::Rgb);      break;
		case 10: return QColor(0,255,0,QColor::Rgb);      break;
		case 11: return QColor(255,255,0,QColor::Rgb);    break;
		case 12: return QColor(0,0,255,QColor::Rgb);      break;
		case 13: return QColor(255,0,255,QColor::Rgb);    break;
		case 14: return QColor(0,255,255,QColor::Rgb);    break;
		default: return QColor(255,255,255,QColor::Rgb);  break;		
	}
}


