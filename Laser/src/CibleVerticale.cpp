#include "CibleVerticale.h"
#include <iostream>

namespace ecran{

CibleVerticale::CibleVerticale(const Cible& cib):Cible{cib}{}

CibleVerticale::CibleVerticale(const int x,const int y,const int cote):Cible{x,y,cote} {}

CibleVerticale::~CibleVerticale(){}

void CibleVerticale::draw(Viewer& fenetre){
    line(this->x(),this->y()-this->cote()/2,this->x(),this->y()+this->cote()/2);
    line(this->x()-this->cote()/2,this->y()-this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2);
    line(this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()+this->cote()/2);
}

bool CibleVerticale::touch(Echiquier& plateau) const{
    Laser* las =(Laser*)plateau.plateau()[plateau.coordLas().x][plateau.coordLas().y];
    switch (las->direction()){
        case Gauche :
            std::cout << "you win !" <<std::endl ;
            break;
        case Droite :
            std::cout << "you win !" <<std::endl ;
            break;
        case Haut :
            std::cout << "you lose !" <<std::endl ;
            break;
        case Bas :
            std::cout << "you lose !" <<std::endl ;
            break;
    }
    return false;
}

}
