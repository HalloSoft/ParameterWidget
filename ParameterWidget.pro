#-------------------------------------------------
#
# Project created by QtCreator 2016-12-23T20:47:57
# Scary Hallo Soft
#
#-------------------------------------------------

QT       += core gui sql widgets

CONFIG += c++11

TARGET = ParameterWidget
TEMPLATE = app


SOURCES += main.cpp\
        maindialog.cpp \
    ParameterInfoWidget.cpp \
    qsqlconnectiondialog.cpp

HEADERS  += maindialog.h \
    ParameterInfoWidget.h \
    qsqlconnectiondialog.h

FORMS    += maindialog.ui \
    ParameterInfoWidget.ui \
    qsqlconnectiondialog.ui
