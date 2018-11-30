#include "../include/Mur.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{
Mur::~Mur() {}

Mur::Mur(Point& centre,int cote):Case{centre,cote} {}

Mur::Mur(int x,int y,int cote):Case{x,y,cote} {}

void Mur::draw(Viewer& fenetre){
    bar( fenetre.pixelX(this->x()-this->cote()/2),fenetre.pixelY(this->y()+this->cote()/2),fenetre.pixelX(this->x()+this->cote()/2),fenetre.pixelY(this->y()-this->cote()/2 ));
}

bool Mur::touch(Echiquier& plateau) const {
return false ;
}

coordLaser Mur::posNextMoveLaser(Echiquier& plateau) const{
    coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
    return ret;
}

}
