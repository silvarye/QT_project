#include "fond.h"
#include <iostream>


fond::fond(int x, int y ) : bloc(x,y, ":images/fond.png")
{
     this->mon_rect.setSize(QSize(getImage().width()+4,getImage().height()));
}

fond::~fond()
{
    std::cout << ("fond supprime\n");
}

void fond::mouvBloc()
{
    mon_rect.moveTo(mon_rect.left() - bloc::temp/2, mon_rect.top());
}
