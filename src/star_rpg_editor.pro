#-------------------------------------------------
#
# Project created by QtCreator 2013-02-12T22:41:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = star_rpg_editor
TEMPLATE = app

CONFIG += console
SOURCES += *.cpp
HEADERS += *.h \
    maptreeview.h \
    mapview.h
FORMS   += *.ui

RESOURCES += \
    main.qrc
