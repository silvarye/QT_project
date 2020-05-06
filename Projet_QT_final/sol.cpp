#include "sol.h"
#include <iostream>

sol::sol(int x, int y , QString picture) : bloc(x,y, picture)
{
}

sol::~sol()
{
    std::cout << ("sol supprime\n");
}
