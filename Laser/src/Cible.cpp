#include "Cible.h"


namespace ecran{
Cible::~Cible() {}

Cible::Cible(Point& centre,int cote):Case{centre,cote} {}

Cible::Cible(int x,int y,int cote):Case{x,y,cote} {}

}
