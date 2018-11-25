#include "../include/Mur.h"
#include <iostream>

namespace ecran{
Mur::~Mur() {}

Mur::Mur(Point& centre,int cote):Case{centre,cote} {}

Mur::Mur(int x,int y,int cote):Case{x,y,cote} {}

void Mur::draw(Viewer& fenetre){
    bar( this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2 );
}

}
