#include "MiroirGaucheVersBas.h"

namespace ecran {

MiroirGaucheVersBas::MiroirGaucheVersBas(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersBas::MiroirGaucheVersBas(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersBas::~MiroirGaucheVersBas() {}

void MiroirGaucheVersBas::draw(Viewer& fenetre){
    line(this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2);
}

Laser MiroirGaucheVersBas::touch(Laser& las){
    switch (las.direction()){
        case Gauche :
            return Laser{this->x(),this->y()-this->cote(),this->cote(),Bas};
            break;
        case Droite :
            return Laser{this->x(),this->y()+this->cote(),this->cote(),Haut};
            break;
        case Haut:
            return Laser{this->x()+this->cote(),this->y(),this->cote(),Droite};
            break;
        case Bas:
            return Laser{this->x()-this->cote(),this->y(),this->cote(),Gauche};
            break;
    }
}

}
