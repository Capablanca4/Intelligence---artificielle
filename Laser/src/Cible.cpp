#include "Cible.h"


namespace ecran{
Cible::~Cible() {}

Cible::Cible(Point& centre,int cote):Case{centre,cote},Touched{false} {}

Cible::Cible(int x,int y,int cote):Case{x,y,cote},Touched{false} {}

const bool Cible::isTouched(){
    return Touched;
    }

}
