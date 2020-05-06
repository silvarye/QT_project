#ifndef BULLEMSG_H
#define BULLEMSG_H

#include "bloc.h"
#include <QString>

enum struct Bulle {CLEE, NONE};

class bulleMsg : public bloc
{

private:
    bool aff = false;
    Bulle type;

public:
//--------------contructeur--------------//
    bulleMsg(int, int, QString);

//--------------destructeur--------------//
    ~bulleMsg();

//--------------getters--------------//
    bool getAffichage(){ return aff; }
    Bulle getType(){ return this->type; }

//--------------setters--------------//
    void setType(Bulle type){ this->type = type; }
    void setAffichage(bool aff){ this->aff = aff; }

};

#endif // BULLEMSG_H
