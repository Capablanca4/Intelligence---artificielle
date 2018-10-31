#include "Cible.h"


namespace ecran{
Cible::Cible(Point& centre):Case{centre},Touched{false} {}

Cible::Cible(int x,int y):Case{x,y},Touched{false} {}

const bool Cible::isTouched(){
    return Touched;
    }

void Cible::draw(Viewer& fenetre){
    line((Point)(*this).x(),(Point)(*this).y()-(Case)(*this).cote(),(Point)(*this).x(),(Point)(*this).y()+(Case)(*this).cote())
}
}
