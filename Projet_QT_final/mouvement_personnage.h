#ifndef MOUVEMENT_PERSONNAGE_H
#define MOUVEMENT_PERSONNAGE_H

#include <QPixmap>
#include <QImage>
#include <QRect>
#include <QString>
#include "dessin.h"

class mouvement_personnage
{
protected:
   QPixmap mouvement_droite;
   QPixmap mouvement_gauche;
   QPixmap mouvement_arret;
   QRect rect;
   QRect mon_rect;
   QRect src_mon_rect;
   bool mouv_droit;
   bool mouv_gauche;
   bool mouv_saut;
   bool mort = false;
   int sprite_dep = 0;

public:
//----------constructeur-------------//
    mouvement_personnage(int, int);

//----------destructeur-------------//
    ~mouvement_personnage();

//----------------getters---------------//
    QRect getRect(){ return rect; }
    QRect getSrcMRect(){ return src_mon_rect; }
    QPixmap getMouvDroite(){ return mouvement_droite; }
    QPixmap getMouvGauche(){ return mouvement_gauche; }
    QPixmap getStop(){ return mouvement_arret; }
    bool getIsMouvDroite(){ return mouv_droit; }
    bool getIsMouvGauche(){ return mouv_gauche; }
    bool getIsSaut(){ return mouv_saut; }
    int getSpriteDep(){ return sprite_dep; }

//-------------setters----------------//
    void setIsMouveDroite(bool content){ this->mouv_droit = content; }
    void setIsMouvGauche(bool content){ this->mouv_gauche = content; }
    void setIsSaut(bool content){ this->mouv_saut = content; }
    void setSpriteDep(int frame){ this->sprite_dep = frame; }

//--------------fonctions---------------//
    void mouvement(int , int);
    bool intersect(QRect );
    void valid(dessin *p){ p->deplacement_coo(this); }


};

#endif // MOUVEMENT_PERSONNAGE_H
