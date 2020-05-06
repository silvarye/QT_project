#ifndef BLOC_H
#define BLOC_H

#include <QImage>
#include <QRect>
#include <QString>
#include "dessin.h"

class bloc
{

private:
    QImage image;
    bool detruit;

protected:
    QRect mon_rect;
    QPixmap clee_sprite;
    QRect sr_mon_rect;

 public:
//----------variable publique------------//
    static int temp;

//---------constructeur--------------------//
    bloc(int ,int );
    bloc(int, int , QString );

//---------destructeur----------------------//
    ~bloc();

//----------getters---------------------//
    bool isDestruit(){ return detruit;}
    QRect getRect();
    QImage & getImage();
    QPixmap getSprite(){ return clee_sprite; }   //rend visible les clées
    QRect getSrcRect(){ return sr_mon_rect; }


//-------setters------------------//
    void setRect(QRect);
    void setSrcRect(QRect srcRect){ this->sr_mon_rect = srcRect; }
    void setDetruit(bool d){this->detruit=d;}

//------------fonctions------------//
    void mouv(int ,int );
    void mouvBloc();
    void valid(dessin *p){ p->deplacement_image(this); }





};

#endif // BLOC_H
