#-------------------------------------------------
#
# Project created by QtCreator 2015-03-17T06:52:04
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = program
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    form_step.cpp \
    listmodel.cpp \
    roster.cpp \
    form_add.cpp \
    thread.cpp \
    processingmanager.cpp

HEADERS  += mainwindow.h \
    form_step.h \
    listmodel.h \
    roster.h \
    form_add.h \
    thread.h \
    processingmanager.h

FORMS    += mainwindow.ui \
    form_step.ui \
    form_add.ui
