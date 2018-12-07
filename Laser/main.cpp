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
    const int cote=40;
    ecran::Viewer fenetre{nbligne*cote,nbcolonne*cote};
    fenetre.openWindow();
    ecran::Echiquier plateau{nbligne,nbcolonne,cote};
    ecran::Laser las{plateau.coordVersPoint(0),plateau.coordVersPoint(19),cote,ecran::Droite};
    ecran::MiroirGaucheVersBas mur{plateau.coordVersPoint(8),plateau.coordVersPoint(19),cote};
    ecran::CibleHorizontale mur1{plateau.coordVersPoint(8),plateau.coordVersPoint(0),cote};
    ecran::Mur mur2{plateau.coordVersPoint(18),plateau.coordVersPoint(10),cote};
    plateau.setCoordLaser({0,19});
    plateau.setCase(&las);
    plateau.setCase(&mur);
    plateau.setCase(&mur1);
    plateau.setCase(&mur2);
    plateau.play(fenetre);
    fenetre.closeWindow();
    return 0;
}
