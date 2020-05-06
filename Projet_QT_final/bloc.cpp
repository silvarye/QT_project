#include "bloc.h"
#include <iostream>
#include <QDebug>

bloc::bloc(int x,int y){
    detruit = false;
    mon_rect.translate(x, y);
    mon_rect.setSize(QSize(50,50));
}

bloc::bloc(int x, int y, QString picture)
{
    image.load(picture);
    detruit = false;
    mon_rect = image.rect();
    mon_rect.translate(x, y);
}

bloc::~bloc()
{
    std::cout << ("Blocs supprimes\n");
}

QRect bloc::getRect()
{
    return mon_rect;
}

void bloc::setRect(QRect rct)
{
    mon_rect = rct;
}

QImage & bloc::getImage()
{
    return image;
}

void bloc::mouvBloc()
{
    mon_rect.moveTo(mon_rect.left() - bloc::temp, mon_rect.top());
}

void bloc::mouv(int x ,int y)
{
    mon_rect.moveTo(x, y);
}


