#ifndef CLEE_H
#define CLEE_H

#include <QPixmap>
#include <QRect>
#include <QString>

#include "bloc.h"
class clee : public bloc
{

public:

  static int coo_actuel;

//-----------constructeur-----------//
  clee(int, int);

//-----------destructeur-------------//
  ~clee();

//-----------fonctions----------//
  void valide(dessin *p){ p->deplacement_coo(this); }



};

#endif // CLEE_H
