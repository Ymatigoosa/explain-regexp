#-------------------------------------------------
#
# Project created by QtCreator 2012-05-29T16:58:25
#
#-------------------------------------------------

QT       += core
QT	 += testlib
QT       -= gui

TARGET = explain-regexp
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    node.cpp \
    variant.cpp \
    nodepattern.cpp \
    patterncontainer.cpp \
    test_description.cpp

HEADERS += \
    nodeType.h \
    node.h \
    variant.h \
    nodepattern.h \
    patterncontainer.h \
    test_description.h
