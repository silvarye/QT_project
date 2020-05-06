#include "entete.h"

entete::entete()
{
    this->rect = QRect(0, 0, 900, 40);
    this->color = QColor(Qt::white);
    clee.load(":images/clee.png");
    this->tailleClee = clee.rect();
    this->position_clee = QPoint(this->getRect().width() + 40, this->getRect().height() - 10);
}
