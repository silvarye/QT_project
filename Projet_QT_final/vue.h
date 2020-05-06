#ifndef VUE_H
#define VUE_H

#include <QWidget>
#include <QKeyEvent>
#include <QMutableMapIterator>
#include <QDebug>
#include <QObject>
#include <QTimer>
#include <QTime>
#include <QLabel>
#include <QElapsedTimer>
#include <QPainter>
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QRect>
#include <QVBoxLayout>
#include <QElapsedTimer>
#include <QAbstractAnimation>


#include "sol.h"
#include "personnage.h"
#include "clee.h"
#include "creation_du_jeu.h"

class creation_du_jeu;


class Vue : public QWidget
{
    Q_OBJECT
private:

    QElapsedTimer timer;
    QLabel * l;
    QTime startT;
    QTimer t;
    creation_du_jeu *jeu;
    QString meilleur_temps;
    QLabel *m_texte3 = new QLabel();
    QVBoxLayout *l1 = new QVBoxLayout();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

public:
    //--------------constructeur--------------//
    Vue(QWidget *parent = 0);

    //--------------destructeur--------------//
     ~Vue();

    //------------------getters------------//
    QTime getTime() { return QTime(0,0).addMSecs(timer.elapsed()); }

    //-------------------setters---------------//
    void setControl(creation_du_jeu *control){ this->jeu = control; }

    //----------fonctions----------------//
    void restart() { timer.restart(); }

public slots:
    void stopgame();
    void stopGameLoose();
    void updateTime();

};

#endif // VUE_H
