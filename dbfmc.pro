#-------------------------------------------------
#
# Project created by QtCreator 2014-01-27T21:22:06
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = dbfmc
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    client.cpp

HEADERS += include/nzmqt/nzmqt.hpp \
    client.h

INCLUDEPATH += include

macx {
    # please create a symbol link of libzmq.a
    LIBS += $$system(pwd)/libzmq.a
}

linux {
    LIBS += -lzmq
}
