
#include <QApplication>
#include <QtWidgets>

#include "modele.h"
#include "vue.h"
#include "creation_du_jeu.h"


void centrer_vue(QWidget &widget)
{
    int x, y;
    int largeur;
    int hauteur;

    QDesktopWidget *desktop = QApplication::desktop();

    largeur = desktop->width();
    hauteur = desktop->height();

    x = (largeur - Modele::Longueur) / 2;
    y = (hauteur - Modele::Hauteur) / 2;

    widget.setGeometry(x, y, Modele::Longueur, Modele::Hauteur);
    widget.setFixedSize(Modele::Longueur, Modele::Hauteur);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Modele m;
    Vue v;
    creation_du_jeu window(&m,&v);
    v.setWindowTitle("jeu");
    v.show();
    centrer_vue(v);
    return app.exec();
}


