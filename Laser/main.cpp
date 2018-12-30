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
    const int cote=35;
    ecran::Viewer fenetre{nbligne*cote,nbcolonne*cote};
    fenetre.openWindow();
    ecran::Echiquier plateau{nbligne,nbcolonne,cote};
    ecran::Laser las{plateau.coordVersPoint(0),plateau.coordVersPoint(19),cote,ecran::Droite};
    ecran::BlocLaser mur{plateau.coordVersPoint(8),plateau.coordVersPoint(19),cote};
    ecran::CibleHorizontale cible{plateau.coordVersPoint(8),plateau.coordVersPoint(0),cote};
    plateau.setCoordLaser({0,19});
    plateau.setCase(&las);
    plateau.setCase(&mur);
    plateau.setCase(&cible);
    plateau.play(fenetre);
    fenetre.closeWindow();
    return 0;
}

