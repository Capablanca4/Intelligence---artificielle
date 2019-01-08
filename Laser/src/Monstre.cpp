#include "Monstre.h"
#include "Echiquier.h"
#include "Game.h"
#include <iostream>

namespace ecran{

Monstre::Monstre(Point& centre,int cote) :Case{centre,cote} {}

Monstre::Monstre(int x,int y,int cote): Case{x,y,cote} {}

Monstre::Monstre(Case& cas):Case{cas}{}

Monstre::~Monstre() {}

void Monstre::draw(Viewer& fenetre){
    if(fenetre.open()){
        backGround(fenetre);
        const int nbPixel = 13;

        int tab [nbPixel*nbPixel]=
        {0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,15,0,0,0,0,0,15,0,0,0,
        0,0,0,0,15,0,0,0,15,0,0,0,0,
        0,0,0,15,15,15,15,15,15,15,0,0,0,
        0,0,15,15,4,15,15,15,4,15,15,0,0,
        0,15,15,15,15,15,15,15,15,15,15,15,0,
        0,15,0,15,15,15,15,15,15,15,0,15,0,
        0,15,0,15,0,0,0,0,0,15,0,15,0,
        0,0,0,0,15,15,0,15,15,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,};

        drawTab(fenetre, tab, nbPixel);
    }
}

bool Monstre::touch(Game& Jeu,int n) {
    changement(Jeu.plateau());
    Jeu.addScore(100); /** Ajout d'un score quand le Monstre est touché*/
    return true;
}

void Monstre::changement(Echiquier& plateau){
    CaseVide* cas = new CaseVide{x(),y(),cote()};
    plateau.setCase(cas);
}

std::string Monstre::typeObjet()const {
    return "Ceci est un Monstre";
}

}
