#include "dessin.h"
#include "mouvement_personnage.h"
#include "bloc.h"
#include <QDebug>

dessin::dessin(QPainter *painter)
{
    this->paint = painter;
}

void dessin::deplacement_image(bloc *e){
    getPainter()->drawImage(e->getRect(),e->getImage());
}

void dessin::deplacement_coo(mouvement_personnage *e){
    if(e->getIsMouvDroite())
        getPainter()->drawPixmap(e->getRect(), e->getMouvDroite(), e->getSrcMRect());
    else if(e->getIsMouvGauche())
        getPainter()->drawPixmap(e->getRect(), e->getMouvGauche(), e->getSrcMRect());
    else
        getPainter()->drawPixmap(e->getRect(), e->getStop(), e->getSrcMRect());
}

void dessin::deplacement_coo(bloc *e){
        getPainter()->drawPixmap(e->getRect(), e->getSprite(), e->getSrcRect());
}

