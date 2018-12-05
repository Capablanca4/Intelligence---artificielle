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
    ecran::Viewer fenetre{nbligne*cote,nbcolonne*cote};
    fenetre.openWindow();
    ecran::Echiquier plateau{nbligne,nbcolonne,cote};
    ecran::Laser las{10,390,20,ecran::Droite};
    ecran::MiroirGaucheVersBas mur{170,390,20};
    ecran::CibleHorizontale mur1{170,10,20};
    plateau.setCoordLaser({0,19});
    plateau.setCase(&las);
    plateau.setCase(&mur);
    plateau.setCase(&mur1);
    plateau.play(fenetre);
    fenetre.closeWindow();
    return 0;
}

