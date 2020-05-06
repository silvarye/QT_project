#include "creation_du_jeu.h"
#include "modele.h"
#include "vue.h"
#include <unistd.h>

creation_du_jeu::creation_du_jeu(Modele *m, Vue *v) : QObject()
{

    this->modele = m;
    this->vue = v;
    this->vue->setControl(this);
    debut_partie = true;
    timer = startTimer(15);
}

int clee::coo_actuel = 0;
int bloc::temp = 4;

void creation_du_jeu::startGame(Modele *m, Vue *v){

    this->modele= m;
    this->vue= v;
    this->vue->setControl(this);
    debut_partie = true;
    timer = startTimer(15);
}

creation_du_jeu::~creation_du_jeu()
{
    killTimer(timer);
}

//-------------------------------------gestion du déroulement des évenements---------------------------------------------------------------------------//

void creation_du_jeu::timerEvent(QTimerEvent *)
{
    message();

    //afficher_message();
    mouvementPersonnage();

    deplacement_message();
    getModele()->bloc_coo();
    mouvement_sprite_clee();

    perdu();

    vue->repaint();
}

//-------------------fin du jeu------------------------//
void creation_du_jeu::stopJeu()
{
    debut_partie = false;
    //isGameOver = true;
}

//-----------------------------coordonée du déplacement------------------------------------------------//

void creation_du_jeu::mouvement_coo_perso(int y)
{
    int x=modele->getPersonnage()->getRect().x();

    if(!collision_gauche(0) && modele->getPersonnage()->getRect().x()>=2 && getMouvementGauche() )
        x -= bloc::temp;
    else if( !collision_droite(0) && modele->getPersonnage()->getRect().x()<=350  && getMouvementDroite())
        x += bloc::temp;
    if( !collision_droite(0)&& modele->getPersonnage()->getRect().x()>=350  && getMouvementDroite() ){
        map_en_mouv=true;
    }
    else
        map_en_mouv=false;
    modele->getPersonnage()->mouvement(x,y);
}

//---------------------------------mouvement du personnage----------------------------------//

void creation_du_jeu::mouvementPersonnage()
{
    int y=modele->getPersonnage()->getRect().y();

    if(getSaut()){

            for(int i=0;i<4;++i){
                Xmax += 1;
            }

        Ymax=(-0.02*(Xmax*Xmax)+200);       //----------hauteur du saut ----------//

        y = debut_saut_Y-Ymax;
        mouvement_coo_perso(y);
        modele->getPersonnage()->setSpriteDep(0);
        if(collision_haut(0)){
            Xmax=0;
            Ymax=0;
            debut_saut_Y=modele->getPersonnage()->getRect().y();
            setSaut(false);
        }
    }

    if(collision_bas(0)){
        Xmax=0;
        Ymax=0;
        debut_saut_Y=modele->getPersonnage()->getRect().y();        //------ mouvement personnage ---------//
        setSaut(false);
        mouvement_coo_perso(y);

    }

    if((!collision_bas(0) && !getSaut())){
        Ymax=(-0.02*(Xmax*Xmax));
        for(int i=0;i<4;++i){Xmax += 1;}
        y = debut_saut_Y-Ymax;
        mouvement_coo_perso(y);
        modele->getPersonnage()->setSpriteDep(0);
    }
}

//----------------------------GESTION DES COLLISIONS-------------------------------------------------------//
//------------------collision au dessus du personnage------------------//

bool creation_du_jeu::collision_haut(int i)
{
    if(i<modele->getSol()->size()){
        if(!modele->getSol()->empty() && i<modele->getSol()->size()){
            if(modele->getPersonnage()->collision_Haut(modele->getSol()->at(i)->getRect()))
                return true;
        }
    collision_haut(i+1);
    }
    else
        return false;
}
//----------------collision en dessous du personnage------------------//
bool creation_du_jeu::collision_bas(int i)
{
    if(i<modele->getSol()->size()){
        if(!modele->getSol()->empty() && i<modele->getSol()->size()){
            if(modele->getPersonnage()->collision_Bas(modele->getSol()->at(i)->getRect()))
                return true;
        }
        collision_bas(i+1);
    }
    else
        return false;

}
//--------------collision a gauche------------------------//
bool creation_du_jeu::collision_gauche(int i)
{
    if(i<modele->getSol()->size()){
    if(!modele->getSol()->empty() && i<modele->getSol()->size()){
        if(modele->getPersonnage()->collsion_gauche(modele->getSol()->at(i)->getRect()))
            return true;
    }
    collision_gauche(i+1);
    }
    else
        return false;
}
//---------------collision a droite-------------------//
bool creation_du_jeu::collision_droite(int i)
{
    if(i<modele->getSol()->size()){
        if(!modele->getSol()->empty() && i<modele->getSol()->size() ){
            if(modele->getPersonnage()->collision_droite(modele->getSol()->at(i)->getRect()))
                return true;

        }
        collision_droite(i+1);
    }
    else
        return false;
}
//-------------------- disparition du cookie quand personnage le prend + incrementation du total ------------------------------//

void creation_du_jeu::ramasser_clees(int i)
{
    if(modele->getPersonnage()->intersect(modele->getClee()->at(i)->getRect())){
        modele->getClee()->at(i)->setDetruit(true);
        modele->getPersonnage()->setNbrClee(modele->getPersonnage()->getNbrClee()+1);
    }
}

//-----------------------------------apparition message de depart -------------------------------------//
/*
void creation_du_jeu::afficher_message()
{
    if(getModel()->getSplashScreen()->getType() == SplashScreenType::GO){
        int x=model->getSplashScreen()->getRect().x();
        int y=model->getSplashScreen()->getRect().y();
        y--;
        if(model->getSplashScreen()->getRect().bottom() > 0 && model->getSplashScreen()->getIsSplashScreen())
            model->getSplashScreen()->move(x, y);
        else
            model->getSplashScreen()->setIsSplashScreen(false);
    }
}
*/

//-------------------- mouvement sprite cookie -----------------//
void creation_du_jeu::mouvement_sprite_clee()
{
    if(temp2 == 20){
        clee::coo_actuel += 40;
        if (clee::coo_actuel >= 120)            /* image de 40*120px */
            clee::coo_actuel = 0;
        temp2 = 0;
    }
    else
        temp2++;
}
//-------------------------enchainement du fond ---------------//
void creation_du_jeu::fond_anim(int i)
{
    if(fond_temp == 2){
        modele->getFond()->at(i)->mouvBloc();
        fond_temp=0;
    }
    else{
        fond_temp++;
    }
}
//-------------------mouvement message debut -------------------//
void creation_du_jeu::deplacement_message(){
    if(getModele()->getMsgBulle()->getAffichage())
        getModele()->getMsgBulle()->mouv(getModele()->getPersonnage()->getRect().x(), getModele()->getPersonnage()->getRect().y() - 100);
}
//-------------------- message de mort ------------------//
bool creation_du_jeu::perdu(){
    if(getModele()->getPersonnage()->getRect().y() > 500){
        getModele()->getMsgBulle()->setAffichage(true);
        bulle_msg_tps = 0;
      //  if(getModel()->getSplashScreen()->getType() != SplashScreenType::GAME_OVER){
          //  getModel()->createGameOver(220, 100);
       //     getModel()->getSplashScreen()->setType(SplashScreenType::GAME_OVER);

      //  }
       // model->getSplashScreen()->setIsSplashScreen(true);
        stopJeu();
        return true;
    }
    else
        return false;
}
//------------------ fin de partie -------------------------//
bool creation_du_jeu::gagne(){
    if(getModele()->getPersonnage()->getNbrClee() >= 150){
        //if(getModel()->getSplashScreen()->getType() != SplashScreenType::COMPLETED){
           // getModel()->createCompleted(360, 120);
         //   getModel()->getSplashScreen()->setType(SplashScreenType::COMPLETED);

      //  }
     //   model->getSplashScreen()->setIsSplashScreen(true);
        stopJeu();
        return true;
    }
    else
        return false;
}
//------------------ message box ----------------------------//
void creation_du_jeu::message(){
    if(getModele()->getPersonnage()->getNbrClee() == 1){
        if(getModele()->getMsgBulle()->getType() != Bulle::CLEE){
            getModele()->crea_msg(getModele()->getPersonnage()->getRect().x(), getModele()->getPersonnage()->getRect().y() - 100, ":images/messageBulle.png");
            getModele()->getMsgBulle()->setType(Bulle::CLEE);
        }
        bulle_msg_tps = 0;
        getModele()->getMsgBulle()->setAffichage(true);
    }
//---------------- Temps apparition message COOKIE -----------------------//
    if(getModele()->getMsgBulle()->getType() == Bulle::CLEE){
        if(bulle_msg_tps > 130){
            getModele()->getMsgBulle()->setAffichage(false);
            getModele()->getMsgBulle()->setType(Bulle::NONE);
        }
        else
            bulle_msg_tps++;
    }

}

