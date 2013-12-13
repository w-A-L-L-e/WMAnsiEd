#############################################################################
# Makefile for building: WMAnsiEd.app/Contents/MacOS/WMAnsiEd
# Generated by qmake (2.01a) (Qt 4.8.1) on: Wed Apr 18 20:07:19 2012
# Project:  WMAnsiEd.pro
# Template: app
# Command: /usr/local/bin/qmake -o Makefile WMAnsiEd.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_QT3SUPPORT_LIB -DQT3_SUPPORT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Cellar/qt/4.8.1/mkspecs/macx-g++ -I. -I/usr/local/Cellar/qt/4.8.1/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.1/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.1/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.1/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.1/lib/Qt3Support.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.1/lib/Qt3Support.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.1/include -I. -F/usr/local/Cellar/qt/4.8.1/lib
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -all_load -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/usr/local/Cellar/qt/4.8.1/lib -L/usr/local/Cellar/qt/4.8.1/lib -framework Qt3Support -L/usr/X11/lib -L/usr/local/Cellar/qt/4.8.1/lib -F/usr/local/Cellar/qt/4.8.1/lib -framework QtSql -framework QtCore -framework QtXml -framework QtGui -framework QtNetwork 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = canvas.cpp \
		IBMFont.cpp \
		main.cpp \
		palette.cpp \
		text.cpp \
		wmansied.cpp moc_canvas.cpp \
		moc_wmansied.cpp
OBJECTS       = canvas.o \
		IBMFont.o \
		main.o \
		palette.o \
		text.o \
		wmansied.o \
		moc_canvas.o \
		moc_wmansied.o
DIST          = /usr/local/Cellar/qt/4.8.1/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/g++-base.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/g++-macx.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.1/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/static.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/include_source_dir.prf \
		WMAnsiEd.pro
QMAKE_TARGET  = WMAnsiEd
DESTDIR       = 
TARGET        = WMAnsiEd.app/Contents/MacOS/WMAnsiEd

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile WMAnsiEd.app/Contents/PkgInfo WMAnsiEd.app/Contents/Resources/empty.lproj WMAnsiEd.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) WMAnsiEd.app/Contents/MacOS/ || $(MKDIR) WMAnsiEd.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: WMAnsiEd.pro  /usr/local/Cellar/qt/4.8.1/mkspecs/macx-g++/qmake.conf /usr/local/Cellar/qt/4.8.1/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/g++-base.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/common/g++-macx.conf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.1/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/static.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.1/mkspecs/features/include_source_dir.prf \
		/usr/local/Cellar/qt/4.8.1/lib/Qt3Support.framework/Qt3Support.prl \
		/usr/local/Cellar/qt/4.8.1/lib/QtSql.framework/QtSql.prl \
		/usr/local/Cellar/qt/4.8.1/lib/QtCore.framework/QtCore.prl \
		/usr/local/Cellar/qt/4.8.1/lib/QtXml.framework/QtXml.prl \
		/usr/local/Cellar/qt/4.8.1/lib/QtGui.framework/QtGui.prl \
		/usr/local/Cellar/qt/4.8.1/lib/QtNetwork.framework/QtNetwork.prl
	$(QMAKE) -o Makefile WMAnsiEd.pro
/usr/local/Cellar/qt/4.8.1/mkspecs/common/unix.conf:
/usr/local/Cellar/qt/4.8.1/mkspecs/common/mac.conf:
/usr/local/Cellar/qt/4.8.1/mkspecs/common/gcc-base.conf:
/usr/local/Cellar/qt/4.8.1/mkspecs/common/gcc-base-macx.conf:
/usr/local/Cellar/qt/4.8.1/mkspecs/common/g++-base.conf:
/usr/local/Cellar/qt/4.8.1/mkspecs/common/g++-macx.conf:
/usr/local/Cellar/qt/4.8.1/mkspecs/qconfig.pri:
/usr/local/Cellar/qt/4.8.1/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt_functions.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt_config.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/exclusive_builds.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/default_pre.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/default_pre.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/release.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/default_post.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/default_post.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/x86_64.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/objective_c.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/static.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/warn_on.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/qt.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/unix/thread.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/moc.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/rez.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/mac/sdk.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/resources.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/uic.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/yacc.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/lex.prf:
/usr/local/Cellar/qt/4.8.1/mkspecs/features/include_source_dir.prf:
/usr/local/Cellar/qt/4.8.1/lib/Qt3Support.framework/Qt3Support.prl:
/usr/local/Cellar/qt/4.8.1/lib/QtSql.framework/QtSql.prl:
/usr/local/Cellar/qt/4.8.1/lib/QtCore.framework/QtCore.prl:
/usr/local/Cellar/qt/4.8.1/lib/QtXml.framework/QtXml.prl:
/usr/local/Cellar/qt/4.8.1/lib/QtGui.framework/QtGui.prl:
/usr/local/Cellar/qt/4.8.1/lib/QtNetwork.framework/QtNetwork.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile WMAnsiEd.pro

WMAnsiEd.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) WMAnsiEd.app/Contents || $(MKDIR) WMAnsiEd.app/Contents 
	@$(DEL_FILE) WMAnsiEd.app/Contents/PkgInfo
	@echo "APPL????" >WMAnsiEd.app/Contents/PkgInfo
WMAnsiEd.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) WMAnsiEd.app/Contents/Resources || $(MKDIR) WMAnsiEd.app/Contents/Resources 
	@touch WMAnsiEd.app/Contents/Resources/empty.lproj
	
WMAnsiEd.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) WMAnsiEd.app/Contents || $(MKDIR) WMAnsiEd.app/Contents 
	@$(DEL_FILE) WMAnsiEd.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,WMAnsiEd,g" -e "s,@TYPEINFO@,????,g" /usr/local/Cellar/qt/4.8.1/mkspecs/macx-g++/Info.plist.app >WMAnsiEd.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/WMAnsiEd1.0.0 || $(MKDIR) .tmp/WMAnsiEd1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/WMAnsiEd1.0.0/ && $(COPY_FILE) --parents canvas.h font.h IBMFont.h palette.h text.h wmansied.h .tmp/WMAnsiEd1.0.0/ && $(COPY_FILE) --parents canvas.cpp IBMFont.cpp main.cpp palette.cpp text.cpp wmansied.cpp .tmp/WMAnsiEd1.0.0/ && (cd `dirname .tmp/WMAnsiEd1.0.0` && $(TAR) WMAnsiEd1.0.0.tar WMAnsiEd1.0.0 && $(COMPRESS) WMAnsiEd1.0.0.tar) && $(MOVE) `dirname .tmp/WMAnsiEd1.0.0`/WMAnsiEd1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/WMAnsiEd1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core
	-$(DEL_FILE) WMAnsiEd

####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r WMAnsiEd.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_canvas.cpp moc_wmansied.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_canvas.cpp moc_wmansied.cpp
moc_canvas.cpp: text.h \
		IBMFont.h \
		canvas.h
	/usr/local/Cellar/qt/4.8.1/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ canvas.h -o moc_canvas.cpp

moc_wmansied.cpp: text.h \
		canvas.h \
		IBMFont.h \
		wmansied.h
	/usr/local/Cellar/qt/4.8.1/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ wmansied.h -o moc_wmansied.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

canvas.o: canvas.cpp canvas.h \
		text.h \
		IBMFont.h \
		palette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o canvas.o canvas.cpp

IBMFont.o: IBMFont.cpp font.h \
		IBMFont.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o IBMFont.o IBMFont.cpp

main.o: main.cpp wmansied.h \
		text.h \
		canvas.h \
		IBMFont.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

palette.o: palette.cpp palette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o palette.o palette.cpp

text.o: text.cpp text.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o text.o text.cpp

wmansied.o: wmansied.cpp wmansied.h \
		text.h \
		canvas.h \
		IBMFont.h \
		palette.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o wmansied.o wmansied.cpp

moc_canvas.o: moc_canvas.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_canvas.o moc_canvas.cpp

moc_wmansied.o: moc_wmansied.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_wmansied.o moc_wmansied.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
