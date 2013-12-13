CONFIG      += release static
TARGET       = WMAnsiEd
HEADERS      = canvas.h font.h IBMFont.h palette.h text.h wmansied.h
SOURCES      = canvas.cpp  IBMFont.cpp  main.cpp  palette.cpp  text.cpp  wmansied.cpp
CLEAN_FILES += WMAnsiEd
QT += qt3support

#The following line was inserted by qt3to4
QT +=  
