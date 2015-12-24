QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = app1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    interface.h

FORMS    += mainwindow.ui
