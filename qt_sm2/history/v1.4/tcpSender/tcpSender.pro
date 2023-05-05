#-------------------------------------------------
#
# Project created by QtCreator 2021-03-16T09:02:58
#
#-------------------------------------------------

QT       += core gui network widgets

TARGET = tcpSender
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    aes.cpp \
    aestools.cpp

HEADERS  += widget.h \
    aes.h \
    aestools.h

FORMS    += widget.ui
