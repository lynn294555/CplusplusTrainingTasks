#-------------------------------------------------
#
# Project created by QtCreator 2017-10-27T11:47:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myfirstqtdemo
TEMPLATE = app


SOURCES += \
    mainwindow.cpp \
    viewwidget.cpp

HEADERS  += \
    viewwidget.h \
    mainwindow.h
QMAKE_CXXFLAGS += -std=c++0x

RESOURCES += \
    res.qrc
