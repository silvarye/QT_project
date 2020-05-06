#include "clee.h"
#include <iostream>

clee::clee(int x, int y ) : bloc(x,y, ":images/clee_3.png")
{
    this->clee_sprite = QPixmap(":images/clee_3.png");
    this->setRect(QRect(x, y, clee_sprite.width()/3, clee_sprite.height()));
}

clee::~clee()
{
     std::cout << ("Clees supprimees\n");
}
