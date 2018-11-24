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
    ecran::Laser las{10,10,20,ecran::Haut};
    plateau.setCoordLaser({0,0});
    plateau.setCase(&las);
    for(int i =0; i< 19;i++) plateau.move();
    plateau.draw(fenetre);
    fenetre.waitUntilButton();
    fenetre.closeWindow();
    return 0;
}

