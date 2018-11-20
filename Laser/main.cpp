#include <iostream>
#include "Viewer.h"
#include "CibleHorirontale.h"
#include "CibleVerticale.h"
#include "Mur.h"
#include "BlocLaser.h"
#include "MiroirGaucheVersHaut.h"
#include "MiroirGaucheVersBas.h"
#include "CaseVide.h"
#include "Echiquier.h"

int main()
{
    const int nbligne=20;
    const int nbcolonne=20;
    const int cote=20;
    ecran::Viewer fenetre{500,700};
    fenetre.openWindow();
    ecran::Echiquier plateau{nbligne,nbcolonne,cote};
    ecran::Laser las{10,10,20,ecran::Droite};
    ecran::BlocLaser bloc{30,10,20};
    plateau.setCoordLaser({1,1});
    plateau.move();
    plateau.setCase(&las);
    plateau.setCase(&bloc);
    plateau.draw(fenetre);
    fenetre.waitUntilButton();
    fenetre.closeWindow();
    return 0;
}

