#include "Cible.h"
#include <iostream>
#include "Game.h"

namespace ecran{

Cible::~Cible() {}

Cible::Cible(Point& centre,int cote):Case{centre,cote} {}

Cible::Cible(const int x,const int y,const int cote):Case{x,y,cote} {}

void Cible::draw(Viewer& fenetre){

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()));

    line(fenetre.pixelX(x()),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()),
         fenetre.pixelY(y()+cote()/2));

}

bool Cible::touch(Game& Jeu,int n){
    std::cout << "you win !" <<std::endl ;
    Jeu.setTouchTrue(n);
    return false;
}

std::string Cible::typeObjet()const{
    return "Ceci est une Cible";
}

}
