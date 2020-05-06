#ifndef DESSIN_H
#define DESSIN_H

#include <QPainter>
#include <QPaintDevice>
#include <QPaintEngine>

class mouvement_personnage;
class bloc;

class dessin
{
private:
    QPainter *paint;

public:
//------------contructeur--------------//
    dessin(QPainter *paint);

//------------destructeur--------------//
    ~dessin();

//------------getters------------//
    QPainter *getPainter(){ return paint; }

//---------fonction------------//
    void deplacement_image(bloc *e);
    void deplacement_coo(bloc *e);
    void deplacement_coo(mouvement_personnage *e);


};

#endif // DESSIN_H
