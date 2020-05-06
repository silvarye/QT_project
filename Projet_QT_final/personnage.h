#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QDebug>
#include "mouvement_personnage.h"

class personnage : public mouvement_personnage
{
private:
    int NbrClee;
    bool isHurted = false;

public:
//------------constructeur------------//
    personnage(int, int);

//------------destructeur------------//
    ~personnage();

//---------getters-----------//
    int getNbrClee(){ return NbrClee; }

//---------setters-----------//
    void setNbrClee(int nbrclee){ this->NbrClee = nbrclee; }

//------------fonctions------------//
    bool collision_Haut(QRect );
    bool collision_Bas(QRect );
    bool collision_droite(QRect );
    bool collsion_gauche(QRect );


};

#endif // PERSONNAGE_H
