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
    ecran::Viewer fenetre{500,700};
    fenetre.openWindow();
    /*ecran::CibleHorizontale cible1{250,250,20};
    //ecran::Laser las1{270,270,20};
    ecran::MiroirGaucheVersHaut mir1{270,270,20};
    ecran::MiroirGaucheVersBas mir2{290,270,20};
    ecran::Mur mur1{290,290,20}; // error ?
    ecran::BlocLaser Bloc(310,310,20);
    ecran::CaseVide cas1{330,330,20};
    Bloc.setDirection(ecran::Gauche);
    ecran::Laser las1{Bloc.shoot()};
    las1.move();
    las1.move();
    mir1.draw(fenetre);
    mir2.draw(fenetre);
    Bloc.draw(fenetre);
    cible1.draw(fenetre);
    mur1.draw(fenetre);
    cas1.draw(fenetre);
    las1.draw(fenetre);*/
    ecran::Echiquier plateau{20,20,20};
    plateau.draw(fenetre);
    fenetre.waitUntilButton();
    fenetre.closeWindow();
    return 0;
}

