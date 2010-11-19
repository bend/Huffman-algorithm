#-------------------------------------------------
#
# Project created by QtCreator 2010-11-17T12:13:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Huffman
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    fileio.cpp \
    nodetree.cpp \
    orderedlist.cpp \
    huffmancompression.cpp

HEADERS += \
    fileio.h \
    nodetree.h \
    orderedlist.h \
    Constants.h \
    huffmancompression.h
