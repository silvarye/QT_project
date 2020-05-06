#ifndef FOND_H
#define FOND_H

#include "bloc.h"

class fond : public bloc
{
public:
//----------------constructeur----------//
    fond(int, int);

//----------------destructeur----------//
    ~fond();

//---------------fonction--------------//
    void mouvBloc();


};

#endif // FOND_H
