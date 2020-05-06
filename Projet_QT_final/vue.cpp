#include "vue.h"
#include "dessin.h"
#include <unistd.h>

Vue::Vue(QWidget *parent): QWidget(parent)
{
    QLabel *m_texte = new QLabel();
    QLabel *m_texte2 = new QLabel();
    QLabel *m_texte3 = new QLabel();
    QLabel *m_texte4 = new QLabel();

    m_texte->setText("Bienvenue sur un jeu programmé en Qt, pour gagner il vous suffit de rammasser 150 clées le plus vite possible ! <br><U><strong>Chronomètre :</strong></U>");
    m_texte->setStyleSheet("font: 10pt;");
    m_texte2->setText("<U><strong>Meilleur temps :</strong></U>");
    m_texte2->setStyleSheet("font: 10pt;");
    m_texte3->setText("------------------------");
    m_texte4->setText("Screen ton meilleur temps !!");
    m_texte4->setStyleSheet("font: 10pt;");


    QPushButton *p3 = new QPushButton("Redémarrer le jeu",this);

    QWidget *parent1 = new QWidget(parent);

    l1->addWidget(m_texte);
    l1->addWidget(l = new QLabel(this));
    l->setText(QTime(0,0).toString());
    l1->addWidget(m_texte3);
    t.start(1000);
    startT.restart();
    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
    connect(p3,SIGNAL(clicked()),this,SLOT(stopGameLoose()));
    l1->addWidget(p3);
    l1->addWidget(m_texte4);
    l1->addWidget(m_texte2);
    parent1->setLayout(l1);
    parent1->show();
    parent1->move(620,0);
}



void Vue::updateTime() {
    l->setText(QTime(0, 0).addMSecs(startT.elapsed()).toString());
}
void Vue::stopGameLoose(){
    Modele *m = new Modele();
    jeu->setModele(m);
    startT.restart();
    close();
    jeu->getVue()->show();
}
void Vue::stopgame(){
      Modele *m = new Modele();
      jeu->setModele(m);

      if(meilleur_temps.isEmpty()||meilleur_temps>l->text()){
           meilleur_temps= l->text();
      }

      startT.restart();
      m_texte3->setText(meilleur_temps);
      m_texte3->setStyleSheet("font: 10pt;");
      l1->addWidget(m_texte3);
      close();
      jeu->getVue()->show();
}

Vue::~Vue()
{
    std::cout << ("Vue supprimee\n");
}

void Vue::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    dessin *pVisitor = new dessin(&painter);

    for(int i = jeu->getModele()->getCompteur()->indexOf(jeu->getModele()->getCompteur()->first()); i<jeu->getModele()->getCompteur()->size(); i++){
        if(jeu->getMouvementCarte()){
            jeu->getModele()->getCompteur()->at(i)->mouvBloc();
        }
    }

      for(int i = jeu->getModele()->getFond()->indexOf(jeu->getModele()->getFond()->first()); i<jeu->getModele()->getFond()->size(); i++){
            if(jeu->getMouvementCarte()){
                 jeu->fond_anim(i);
            }
            jeu->getModele()->getFond()->at(i)->valid(pVisitor);

      }

    for(int i = 0; i<jeu->getModele()->getSol()->size(); i++){
    if(jeu->getMouvementCarte()){
            jeu->getModele()->getSol()->at(i)->mouvBloc();
    }
        jeu->getModele()->getSol()->at(i)->valid(pVisitor);
    }

    for(int i = 0; i<jeu->getModele()->getClee()->size(); i++){
        jeu->ramasser_clees(i);
        if(jeu->getMouvementCarte()){
           jeu->getModele()->getClee()->at(i)->mouvBloc();
        }
        jeu->getModele()->getClee()->at(i)->setSrcRect(QRect(clee::coo_actuel, 0, jeu->getModele()->getClee()->at(i)->getRect().width(), jeu->getModele()->getClee()->at(i)->getRect().height()));
        jeu->getModele()->getClee()->at(i)->valide(pVisitor);

    }


    jeu->getModele()->getPersonnage()->valid(pVisitor);

    if(jeu->getModele()->getMsgBulle()->getAffichage()){
        jeu->getModele()->getMsgBulle()->valid(pVisitor);

    }

    painter.drawImage(jeu->getModele()->getEntete()->getRect().width() - 0, jeu->getModele()->getEntete()->getRect().height() / 8, jeu->getModele()->getEntete()->getClee());
    painter.setFont(QFont("arial", 15, 0, true));
    QString goldText = QString::number(jeu->getModele()->getPersonnage()->getNbrClee());
    painter.drawText(jeu->getModele()->getEntete()->getPositionClee(), goldText);




    painter.save();

    painter.restore();



    if(jeu->perdu()){     
        stopGameLoose();

    }
    else if(jeu->gagne()){       
        stopgame();

    }

}

//-------------------------------------------------------------------------------------------------------------------//

void Vue::keyPressEvent(QKeyEvent *event)
{
    if(!jeu->perdu()){
        if(event->key() == Qt::Key_Right)
            jeu->setMouvementDroite(true);
        else if(event->key() == Qt::Key_Left)
            jeu->setMouvementGauche(true);
        else if(event->key() == Qt::Key_Down && jeu->getSaut())
           {}
        else if(event->key() == Qt::Key_Space && jeu->collision_bas(0)){
            jeu->setSaut(true);
            jeu->set_borne_X(-100);
        }
        else
            event->ignore();
    }
    else if(event->key() == Qt::Key_Enter){

    }

    if (event->key() == Qt::Key_Escape)
    {
        jeu->stopJeu();
        qApp->exit();
    }

}

//----------------------------------------------------------------------------------------------------------------//

void Vue::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right )
        jeu->setMouvementDroite(false);
    else if(event->key() == Qt::Key_Left )
        jeu->setMouvementGauche(false);
    else
        event->ignore();
}
