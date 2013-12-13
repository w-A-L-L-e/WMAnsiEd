/***************************************************************************
                          main.cpp  -  description
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
#include <qapplication.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    WMAnsiEd wmansi;
    wmansi.setFixedSize( 640, 456 );
    a.setMainWidget( &wmansi );
    wmansi.show();
    return a.exec();
}
