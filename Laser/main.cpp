#include <iostream>
#include "Viewer.h"
#include "Echiquier.h"
#include "Game.h"

int main()
{
    const int nbligne=20;
    const int nbcolonne=20;
    const int cote=40;
    const int nbLaser=1;
    const int maxIter=200;
    ecran::Game jeu{nbligne,nbcolonne,cote,nbLaser,maxIter};
    jeu.openGame();
    jeu.test();
    jeu.draw();
    jeu.waitUntilMouseCkicked();
    /*ecran::Viewer fenetre{nbligne*cote,nbcolonne*cote/*+200};
    fenetre.openWindow();
    ecran::Echiquier plateau{nbligne,nbcolonne,cote};
    ecran::Laser las{plateau.coordVersPoint(0),plateau.coordVersPoint(19),cote,ecran::Droite};
    ecran::MiroirGaucheVersBas mur{plateau.coordVersPoint(8),plateau.coordVersPoint(19),cote};
    ecran::CibleHorizontale cible{plateau.coordVersPoint(8),plateau.coordVersPoint(0),cote};
    plateau.setCoordLaser({0,19});
    plateau.setCase(&las);
    plateau.setCase(&mur);
    plateau.setCase(&cible);
    //plateau.play(fenetre);
    plateau.draw(fenetre);
    fenetre.waitUntilButton();
    fenetre.closeWindow();*/
    return 0;
}

