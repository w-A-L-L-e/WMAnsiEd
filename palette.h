#ifndef PALETTE_H
#define PALETTE_H

#include <qcolor.h>

class Palette {
private:
	int index;
	
public:
	Palette(int);
	
	int getIndex();
	QColor getColor();
};

#endif

