#-------------------------------------------------
#
# Project created by QtCreator 2022-02-17T12:52:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aten

TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

win32: RC_ICONS = Aten.ico
