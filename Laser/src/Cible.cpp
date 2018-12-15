#include "Cible.h"
#include <iostream>

namespace ecran{

Cible::~Cible() {}

Cible::Cible(Point& centre,int cote):Case{centre,cote} {}

Cible::Cible(const int x,const int y,const int cote):Case{x,y,cote} {}

void Cible::draw(Viewer& fenetre){

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()));

    line(fenetre.pixelX(this->x()),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()),
         fenetre.pixelY(this->y()+this->cote()/2));

}

bool Cible::touch(Echiquier& plateau,GameStatut& StatutJeu,int n){
    std::cout << "you win !" <<std::endl ;
    StatutJeu.setTouchTrue(n);
    return false;
}

}
