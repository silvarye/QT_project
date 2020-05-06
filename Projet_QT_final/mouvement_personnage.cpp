#include "mouvement_personnage.h"
#include <iostream>
#include <QDebug>
#include <QRect>

mouvement_personnage::mouvement_personnage(int x, int y)
{
    rect.translate(x, y);
    mort = false;
    mouv_droit=false;
    mouv_gauche=false;
    mouv_saut=false;
}

mouvement_personnage::~mouvement_personnage()
{
    std::cout << ("mouvement personnage supprime\n");
}


void mouvement_personnage::mouvement(int x ,int y)
{
    rect.moveTo(x, y);
}

bool mouvement_personnage::intersect(QRect r)
{
    if(r.intersects(getRect()))
       return true;
    else
        return false;
}
