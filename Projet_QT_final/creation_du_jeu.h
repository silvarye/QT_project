#ifndef CREATION_DU_JEU_H
#define CREATION_DU_JEU_H

#include <QWidget>
#include <QObject>

#include "sol.h"
#include "personnage.h"
#include "modele.h"


class Vue;


class creation_du_jeu : QObject
{
    Q_OBJECT

protected:   
    Modele *modele;
    Vue *vue;
    bool debut_partie;
    int Xmax;
    int Ymax;
    int debut_saut_Y;
    int fond_temp;
    int temp1 = 0;
    int temp2 = 0;
    bool map_en_mouv=false;
    int bulle_msg_tps = 0;
    int timer=0;
    void timerEvent(QTimerEvent *event);

public:
    //--------------constructeur-----------//
    creation_du_jeu(Modele *m, Vue *v);

    //---------------destructeur-----------//
    ~creation_du_jeu();

    //------------getters--------------//
    bool getMouvementDroite(){ return getModele()->getPersonnage()->getIsMouvDroite(); }
    bool getMouvementGauche(){ return getModele()->getPersonnage()->getIsMouvGauche(); }
    bool getSaut(){ return getModele()->getPersonnage()->getIsSaut(); }
    bool getMouvementCarte(){return map_en_mouv;}
    Modele *getModele(){ return this->modele; }
    Vue *getVue(){ return this->vue; }
    bool getDebutPartie(){return this->debut_partie;}


    //------------setters----------------//
    void setMouvementDroite(bool is){ getModele()->getPersonnage()->setIsMouveDroite(is); }
    void setMouvementGauche(bool is){ getModele()->getPersonnage()->setIsMouvGauche(is); }
    void setSaut(bool is){ getModele()->getPersonnage()->setIsSaut(is); }
    void set_borne_X(int x){this->Xmax = x; }
    void setTimer(int a){this->timer=a;}
    void *setModele(Modele *m){ this->modele = m; }

    //-------------fonctions-------------//
    void stopJeu();
    void mouvementPersonnage();
    void mouvement_coo_perso(int );
    void deplacement_message();
    void afficher_message();
    bool perdu();
    bool gagne();
    bool collision_bas(int );
    bool collision_haut(int );
    bool collision_droite(int );
    bool collision_gauche(int );
    void ramasser_clees(int );
    void mouvement_sprite_clee();
    void fond_anim(int );
    void message();
    void startGame(Modele *m, Vue *v);

};
#endif // CREATION_DU_JEU_H
