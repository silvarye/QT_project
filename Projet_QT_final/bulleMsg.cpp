#include "bulleMsg.h"
#include <QString>

bulleMsg::bulleMsg(int x, int y, QString image) : bloc(x, y, image)
{
    setAffichage(true);
}

