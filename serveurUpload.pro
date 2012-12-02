#-------------------------------------------------
#
# Project created by QtCreator 2012-11-18T13:09:45
#
#-------------------------------------------------

QT       += core gui \
         network    \
         sql
TARGET = serveurFinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindowservfinal.cpp \
    serveurtcp.cpp \
    media.cpp \
    medialist.cpp \
    receivethread.cpp \
    protocol.cpp

HEADERS  += mainwindowservfinal.h \
    serveurtcp.h \
    media.h \
    medialist.h \
    receivethread.h \
    serverexception.h \
    protocol.h

FORMS    += mainwindowservfinal.ui
