#include "CibleHorirontale.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

CibleHorizontale::CibleHorizontale(Point& centre,int cote):Case{centre,cote}{}

CibleHorizontale::CibleHorizontale(const int x,const int y,const int cote):Case{x,y,cote} {}

CibleHorizontale::~CibleHorizontale(){}

void CibleHorizontale::draw(Viewer& fenetre){

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()));

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2));

    line(fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2));
}

bool CibleHorizontale::touch(Echiquier& plateau,GameStatut& StatutJeu,int n){
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
            StatutJeu.setTouchTrue(n);
            break;
        case Bas :
            std::cout << "you win !" <<std::endl ;
            StatutJeu.setTouchTrue(n);
            break;
    }
    return false;
}

}
