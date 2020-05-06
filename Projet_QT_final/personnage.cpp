#include "personnage.h"
#include <iostream>
#include <QDebug>

personnage::personnage(int x, int y ) : mouvement_personnage(x,y)
{

    this->mouvement_droite = QPixmap(":images/personnage_droite.png");
    this->mouvement_gauche = QPixmap(":images/personnage_gauche.png");
    this->mouvement_arret = QPixmap(":images/personnage_arret.png");
    this->NbrClee = 0;
    this->rect = QRect(x, y, 45, mouvement_droite.height() - 7);
    this->mon_rect = QRect(x, y, 50, mouvement_arret.height()-7);
}

personnage::~personnage()
{
    std::cout << ("Personnage supprime\n");
}

bool personnage::collision_Haut(QRect r)
{
    if(r.intersected(getRect()).width() > 7 && getRect().y() > r.y())
    {
        mouvement(getRect().x(),r.y() + 49);
        return true;
    }
    return false;
}

bool personnage::collision_Bas(QRect r)
{
    if(r.intersected(getRect()).width() > 5 && getRect().y() < r.y())
    {
        mouvement(getRect().x(),r.y() - getRect().height() + 1);
        return true;
    }
    return false;
}

bool personnage::collision_droite(QRect r)
{
    if(r.intersected(getRect()).height() > 5 && getRect().x() < r.x() )
        return true;
    return false;
}

bool personnage::collsion_gauche(QRect r)
{
    if(r.intersected(getRect()).height() > 5 && getRect().x() > r.x())
        return true;
    return false;
}

