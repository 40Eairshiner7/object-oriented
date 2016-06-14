#-------------------------------------------------
#
# Project created by QtCreator 2016-06-05T17:50:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calculatorPlus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Calculation.cpp \
    Scan.cpp \
    Print.cpp

HEADERS  += mainwindow.h \
    Calculation.h \
    Scan.h \
    Print.h

FORMS    += mainwindow.ui
