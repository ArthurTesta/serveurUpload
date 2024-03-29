#############################################################################
# Makefile for building: serveurFinal
# Generated by qmake (2.01a) (Qt 4.8.1) on: Fri Dec 7 15:00:15 2012
# Project:  serveurUpload.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile serveurUpload.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtNetwork -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtSql -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindowservfinal.cpp \
		serveurtcp.cpp \
		media.cpp \
		medialist.cpp \
		protocol.cpp \
		receivethread.cpp moc_mainwindowservfinal.cpp \
		moc_serveurtcp.cpp \
		moc_receivethread.cpp
OBJECTS       = main.o \
		mainwindowservfinal.o \
		serveurtcp.o \
		media.o \
		medialist.o \
		protocol.o \
		receivethread.o \
		moc_mainwindowservfinal.o \
		moc_serveurtcp.o \
		moc_receivethread.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		serveurUpload.pro
QMAKE_TARGET  = serveurFinal
DESTDIR       = 
TARGET        = serveurFinal

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

all: Makefile $(TARGET)

$(TARGET): ui_mainwindowservfinal.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: serveurUpload.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtSql.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtNetwork.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile serveurUpload.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtSql.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtNetwork.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -o Makefile serveurUpload.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/serveurFinal1.0.0 || $(MKDIR) .tmp/serveurFinal1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/serveurFinal1.0.0/ && $(COPY_FILE) --parents mainwindowservfinal.h serveurtcp.h media.h medialist.h receivethread.h protocol.h exception.h .tmp/serveurFinal1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindowservfinal.cpp serveurtcp.cpp media.cpp medialist.cpp protocol.cpp receivethread.cpp .tmp/serveurFinal1.0.0/ && $(COPY_FILE) --parents mainwindowservfinal.ui .tmp/serveurFinal1.0.0/ && (cd `dirname .tmp/serveurFinal1.0.0` && $(TAR) serveurFinal1.0.0.tar serveurFinal1.0.0 && $(COMPRESS) serveurFinal1.0.0.tar) && $(MOVE) `dirname .tmp/serveurFinal1.0.0`/serveurFinal1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/serveurFinal1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindowservfinal.cpp moc_serveurtcp.cpp moc_receivethread.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindowservfinal.cpp moc_serveurtcp.cpp moc_receivethread.cpp
moc_mainwindowservfinal.cpp: serveurtcp.h \
		medialist.h \
		media.h \
		mainwindowservfinal.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindowservfinal.h -o moc_mainwindowservfinal.cpp

moc_serveurtcp.cpp: medialist.h \
		media.h \
		serveurtcp.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) serveurtcp.h -o moc_serveurtcp.cpp

moc_receivethread.cpp: medialist.h \
		media.h \
		exception.h \
		protocol.h \
		receivethread.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) receivethread.h -o moc_receivethread.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindowservfinal.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindowservfinal.h
ui_mainwindowservfinal.h: mainwindowservfinal.ui
	/usr/bin/uic-qt4 mainwindowservfinal.ui -o ui_mainwindowservfinal.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindowservfinal.h \
		serveurtcp.h \
		medialist.h \
		media.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindowservfinal.o: mainwindowservfinal.cpp mainwindowservfinal.h \
		serveurtcp.h \
		medialist.h \
		media.h \
		ui_mainwindowservfinal.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindowservfinal.o mainwindowservfinal.cpp

serveurtcp.o: serveurtcp.cpp serveurtcp.h \
		medialist.h \
		media.h \
		receivethread.h \
		exception.h \
		protocol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o serveurtcp.o serveurtcp.cpp

media.o: media.cpp media.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o media.o media.cpp

medialist.o: medialist.cpp media.h \
		medialist.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o medialist.o medialist.cpp

protocol.o: protocol.cpp receivethread.h \
		medialist.h \
		media.h \
		exception.h \
		protocol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o protocol.o protocol.cpp

receivethread.o: receivethread.cpp receivethread.h \
		medialist.h \
		media.h \
		exception.h \
		protocol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o receivethread.o receivethread.cpp

moc_mainwindowservfinal.o: moc_mainwindowservfinal.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindowservfinal.o moc_mainwindowservfinal.cpp

moc_serveurtcp.o: moc_serveurtcp.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_serveurtcp.o moc_serveurtcp.cpp

moc_receivethread.o: moc_receivethread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_receivethread.o moc_receivethread.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

