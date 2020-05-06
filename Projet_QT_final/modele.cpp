#include "modele.h"
#include "bloc.h"
#include "clee.h"
#include "personnage.h"
#include "sol.h"
#include "entete.h"
#include "bulleMsg.h"
#include <QDebug>

Modele::Modele()
{
    QFile fichier(":ModelMap.txt");
    this->isCreateMessage=false;
    this->fond1 = new QList<fond *>;
    this->sol1 = new QList<sol *>;
    this->clee1 = new QList<clee *>;
    this->fond1 = new QList<fond *>;
    this->entete1 = new entete();
    this->compteur = new QList<bloc*> ;
    this->personnage1 = new personnage(200, 340);
    this->msg_bulle = new bulleMsg(0,0, "");
    this->p1 = new QPushButton("start");
    getMsgBulle()->setType(Bulle::NONE);

    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream in (&fichier);
        while(!in.atEnd())
        {
            QString stock = in.readLine();
            if (stock.left(6)=="LIGNEa")
            {
                for(int i=0;i<stock.size();++i){
                    if(stock.at(i).isDigit() || stock.at(i).isLetter()){
                        l1.append(stock.at(i));
                    }
                }
            }
            else if (stock.left(6)=="LIGNEb")
            {
                for(int i=0;i<stock.size();++i){
                    if(stock.at(i).isDigit() || stock.at(i).isLetter()){
                        l2.append(stock.at(i));
                    }
                }
            }
            else if (stock.left(6)=="LIGNEc")
            {
                for(int i=0;i<stock.size();++i){
                    if(stock.at(i).isDigit() || stock.at(i).isLetter()){
                        l3.append(stock.at(i));
                    }
                }
            }
            else if (stock.left(6)=="LIGNEd")
            {
                for(int i=0;i<stock.size();++i){
                    if(stock.at(i).isDigit() || stock.at(i).isLetter()){
                        l4.append(stock.at(i));
                    }
                }
            }
            else if (stock.left(6)=="LIGNEe")
            {
                for(int i=0;i<stock.size();++i){
                    if(stock.at(i).isDigit() || stock.at(i).isLetter()){
                        l5.append(stock.at(i));
                    }
                }
            }
            else if (stock.left(6)=="LIGNEf")
            {
                for(int i=0;i<stock.size();++i){
                    if(stock.at(i).isDigit() || stock.at(i).isLetter()){
                        l6.append(stock.at(i));
                    }
                }
            }
        }
        fichier.close();
    }

//-------------------------------creation_plateforme debut de jeu----------------------------//

    for (int i=0; i<NbrBlocVisible; i++) {
        sol *s= new sol(i*tailleBloc, Hauteur-tailleBloc, QString(":images/sol.jpg"));
        sol1->append(s);
        sol *s2= new sol(i*tailleBloc, Hauteur-2*tailleBloc, QString(":images/sol_haut.png"));
        sol1->append(s2);
    }
    for (int i=0; i<NbrBlocVisible; i++) {
        bloc *b=new bloc(i*tailleBloc,Hauteur+tailleBloc);
        compteur->append(b);
    }
    for (int i=0; i<2; i++) {
        fond* b = new fond(i*Modele::Longueur, 0);
        fond1->append(b);
    }
}

//--------------------------------------------------------------------------------------------------------//

Modele::~Modele()
{
    sol1->clear();
    delete sol1;
    compteur->clear();
    delete compteur;
    fond1->clear();
    delete fond1;
    clee1->clear();
    delete clee1;
    delete personnage1;
}

//-----------------------------------------------------------------------------------------------------------------//

void Modele::crea_bloc(QList<QChar> l ,int num ,int x){

    QChar myChar = l.at(carte_pos);

    if(myChar == '0')
        return;
    else if(myChar == '1'){
        sol *s= new sol(x+tailleBloc,Hauteur-num*tailleBloc, QString(":images/sol.jpg"));
        sol1->append(s);
        return;
    }

    else if(myChar == '2'){
        clee* c= new clee(x+tailleBloc, Hauteur-num*tailleBloc);
        clee1->append(c);
        return;
    }

    else if(myChar == '3'){
        sol *s= new sol(x+tailleBloc,Hauteur-num*tailleBloc , QString(":images/sol_haut.png"));
        sol1->append(s);
        return;
    }
    else if(myChar == '4'){
        sol *s= new sol(x+tailleBloc,Hauteur-num*tailleBloc , QString(":images/sol_droite.png"));
        sol1->append(s);
        return;
    }
    else if(myChar == '5'){
        sol *s= new sol(x+tailleBloc,Hauteur-num*tailleBloc , QString(":images/sol_gauche.png"));
        sol1->append(s);
        return;
    }
}

//----------------------------------------------------------------------------------------------------------------//

void Modele::bloc_coo()
{
    for(int i = 0; i<fond1->size(); i++){
        if(fond1->at(i)->getRect().x() < - fond1->at(i)->getRect().width() + 2){
            fond1->removeAt(i);
            fond* f = new fond(1000,0);
            fond1->append(f);
        }
    }
    if(compteur->last()->getRect().x()<((NbrBlocVisible)*tailleBloc)){
        crea_bloc(l1,1,compteur->last()->getRect().x());
        crea_bloc(l2,2,compteur->last()->getRect().x());
        crea_bloc(l3,3,compteur->last()->getRect().x());
        crea_bloc(l4,4,compteur->last()->getRect().x());
        crea_bloc(l5,5,compteur->last()->getRect().x());
        crea_bloc(l6,6,compteur->last()->getRect().x());
        bloc *b=new bloc(compteur->last()->getRect().x()+tailleBloc,Hauteur+tailleBloc);
        compteur->append(b);
        carte_pos++;
    }

    if (compteur->first()->getRect().x()<=-tailleBloc){
        compteur->removeAt(compteur->indexOf(compteur->first()));
    }

    for(int i = 0; i<sol1->size(); i++){
        if (sol1->at(i)->getRect().x()<=-tailleBloc || sol1->at(i)->isDestruit()){
            sol1->removeAt(i);
        }
    }

    for(int i = 0; i<clee1->size(); i++){
        if (clee1->at(i)->getRect().x()<=-tailleBloc || clee1->at(i)->isDestruit()){
            clee1->removeAt(i);
        }
    }
}

void Modele::crea_msg(int x, int y, QString image){
    this->msg_bulle = new bulleMsg(x, y, image);
}
