#include "CibleHorirontale.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

CibleHorizontale::CibleHorizontale(const Cible& cib):Cible{cib}{}

CibleHorizontale::CibleHorizontale(const int x,const int y,const int cote):Cible{x,y,cote} {}

CibleHorizontale::~CibleHorizontale(){}

void CibleHorizontale::draw(Viewer& fenetre){
    line(this->x()-this->cote()/2,this->y(),this->x()+this->cote()/2,this->y());
    line(this->x()-this->cote()/2,this->y()-this->cote()/2,this->x()-this->cote()/2,this->y()+this->cote()/2);
    line(this->x()+this->cote()/2,this->y()-this->cote()/2,this->x()+this->cote()/2,this->y()+this->cote()/2);
}

bool CibleHorizontale::touch(Echiquier& plateau) const{
    Laser* las =(Laser*)plateau.plateau()[plateau.coordLas().x][plateau.coordLas().y];
    switch (las->direction()){
        case Gauche :
            std::cout << "you lose !" <<std::endl ;
            break;
        case Droite :
            std::cout << "you lose !" <<std::endl ;
            break;
        case Haut :
            std::cout << "you win !" <<std::endl ;
            break;
        case Bas :
            std::cout << "you win !" <<std::endl ;
            break;
    }
    return false;
}

coordLaser CibleHorizontale::posNextMoveLaser(Echiquier& plateau) const{
    coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
    return ret;

}
}
