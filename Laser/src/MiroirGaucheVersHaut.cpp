#include "MiroirGaucheVersHaut.h"

namespace ecran{

MiroirGaucheVersHaut::MiroirGaucheVersHaut(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersHaut::MiroirGaucheVersHaut(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersHaut::~MiroirGaucheVersHaut(){}

void MiroirGaucheVersHaut::draw(Viewer& fenetre){
    line(this->x()-this->cote()/2,this->y()-this->cote()/2,this->x()+this->cote()/2,this->y()+this->cote()/2);
}
Laser MiroirGaucheVersHaut::touch(Laser& las){
    switch (las.direction()){
        case Gauche :
            return Laser{this->x(),this->y()+this->cote(),this->cote(),Haut};
            break;
        case Droite :
            return Laser{this->x(),this->y()-this->cote(),this->cote(),Bas};
            break;
        case Haut:
            return Laser{this->x()-this->cote(),this->y(),this->cote(),Gauche};
            break;
        case Bas:
            return Laser{this->x()+this->cote(),this->y(),this->cote(),Droite};
            break;
        }
    }
}
