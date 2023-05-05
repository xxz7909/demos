#-------------------------------------------------
#
# Project created by QtCreator 2021-03-16T09:43:04
#
#-------------------------------------------------

QT       += core gui network widgets

TARGET = tcpReceiver
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    aes.cpp \
    aestools.cpp

HEADERS  += widget.h \
    aes.h \
    aestools.h

FORMS    += widget.ui
