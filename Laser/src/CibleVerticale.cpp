#include "CibleVerticale.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

CibleVerticale::CibleVerticale(Point& centre,int cote):Case{centre,cote}{}

CibleVerticale::CibleVerticale(const int x,const int y,const int cote):Case{x,y,cote} {}

CibleVerticale::~CibleVerticale(){}

void CibleVerticale::draw(Viewer& fenetre){

    line(fenetre.pixelX(this->x()),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()),
         fenetre.pixelY(this->y()+this->cote()/2));

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2));

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2));
}

bool CibleVerticale::touch(Echiquier& plateau,GameStatut& StatutJeu,int n){
    Laser* las =(Laser*)plateau.plateau()[plateau.coordLas().x][plateau.coordLas().y];
    switch (las->direction()){
        case Gauche :
            std::cout << "you win !" <<std::endl ;
            StatutJeu.setTouchTrue(n);
            break;
        case Droite :
            std::cout << "you win !" <<std::endl ;
            StatutJeu.setTouchTrue(n);
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
