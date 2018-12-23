#include "Monstre.h"
#include "Echiquier.h"

namespace ecran{

Monstre::Monstre(Point& centre,int cote) :Case{centre,cote} {}

Monstre::Monstre(int x,int y,int cote): Case{x,y,cote} {}

Monstre::Monstre(Case& cas):Case{cas}{}

Monstre::~Monstre() {}

void Monstre::draw(Viewer& fenetre){
        /** Temporaire: le dessin DOIT changer */
    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()+cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()-cote()/2));
    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()+cote()/2));

}

bool Monstre::touch(Echiquier& plateau,GameStatut& StatutJeu,int n) {
    changement(plateau);
    StatutJeu.addScore(100); /** Ajout d'un score quand le Monstre est touché*/
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
