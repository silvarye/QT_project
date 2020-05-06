#ifndef MODELE_H
#define MODELE_H

#include <QMap>
#include <QMutableMapIterator>
#include <QFile>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QChar>
#include "entete.h"
#include "fond.h"
#include "bulleMsg.h"


class sol;
class personnage;
class bloc;
class clee;
class Modele

{

private:
    QList<QChar> l1;
    QList<QChar> l2;
    QList<QChar> l3;
    QList<QChar> l4;
    QList<QChar> l5;
    QList<QChar> l6;
    QList<sol*> *sol1;
    QList<bloc*> *compteur;
    QList<fond*> *fond1;
    QList<clee*> *clee1;
    personnage *personnage1;
    entete *entete1;
    bulleMsg *msg_bulle;
    QPushButton *p1;
    int carte_pos = 7;
    int speed = 4;

public:
    //--------------constructeur----------------//
    Modele();

    //--------------destructeur----------------//
    ~Modele();

    static int const tailleBloc = 50;                    //-------------taille 50*50 brique---------//
    static int const Hauteur = 500;                     //-------------hauteur du fond--------------//
    static int const Longueur = 1000;                   //-------------longueur du fond--------------//
    static int const NbrBlocVisible = 20;              //---------------nbr de brique visible a l'ecran 20*50 = 1000 (longueur) --------------//
    bool isCreateMessage = false;

    //--------------getters----------------//
    personnage *getPersonnage(){ return personnage1; }
    entete *getEntete(){ return entete1; }
    QPushButton *getBoutton(){return p1;}
    QList<bloc*> *getCompteur(){ return compteur; }
    QList<sol*> *getSol(){ return sol1; }
    QList<fond*> *getFond(){ return fond1; }
    QList<clee*> *getClee(){ return clee1; }
    bulleMsg *getMsgBulle(){ return msg_bulle; }

    //---------------fonctions------------//
    void crea_bloc(QList<QChar> ,int ,int );
    void stoppJeu();
    void bloc_coo();
    void crea_msg(int x, int y, QString image);
    void resetGame();



};

#endif // MODELE_H
