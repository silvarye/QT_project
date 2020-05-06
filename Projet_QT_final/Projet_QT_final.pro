#-------------------------------------------------
#
# Project created by QtCreator 2020-04-20T16:45:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
QMAKE_CXXFLAGS+= -std=c++17 -O3
QMAKE_LFLAGS +=  -std=c++17

RESOURCES += \
    jeu.qrc


SOURCES += main.cpp \
    bloc.cpp \
    bulleMsg.cpp \
    clee.cpp \
    creation_du_jeu.cpp \
    dessin.cpp \
    entete.cpp \
    fond.cpp \
    modele.cpp \
    mouvement_personnage.cpp \
    personnage.cpp \
    sol.cpp \
    vue.cpp

HEADERS  += \
    bloc.h \
    bulleMsg.h \
    clee.h \
    creation_du_jeu.h \
    dessin.h \
    entete.h \
    fond.h \
    modele.h \
    mouvement_personnage.h \
    personnage.h \
    sol.h \
    vue.h

DISTFILES +=



