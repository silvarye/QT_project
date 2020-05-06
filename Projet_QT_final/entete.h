#ifndef ENTETE_H
#define ENTETE_H

#include <QMainWindow>
#include <QRect>
#include <QColor>
#include <QString>
#include <QImage>
#include <QWidget>
#include <QPushButton>


class entete
{
private:

    QRect rect;
    QColor color;
    QString text;
    QImage clee;
    QRect tailleClee;
    QPoint position_clee;

public:
//---------------Constructeur------------//
    entete();

//--------getters--------------------//
    QRect getRect(){ return rect; }
    QImage getClee(){ return clee; }
    QPoint getPositionClee(){ return position_clee; }


};

#endif // ENTETE_H
