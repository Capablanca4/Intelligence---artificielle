#include "CibleHorirontale.h"
#include <iostream>
#include "Echiquier.h"
#include "Game.h"

namespace ecran{

CibleHorizontale::CibleHorizontale(Point& centre,int cote):Case{centre,cote}{}

CibleHorizontale::CibleHorizontale(const int x,const int y,const int cote):Case{x,y,cote} {}

CibleHorizontale::~CibleHorizontale(){}

void CibleHorizontale::draw(Viewer& fenetre){

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()));

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()+cote()/2));

    line(fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()+cote()/2));
}

bool CibleHorizontale::touch(Game& Jeu,int n){
    Laser* las =(Laser*)Jeu.plateau().emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Gauche :
            //std::cout << "you lose !" <<std::endl ;
            break;
        case Droite :
            //std::cout << "you lose !" <<std::endl ;
            break;
        case Haut :
            //std::cout << "you win !" <<std::endl ;
            Jeu.setTouchTrue(n);
            break;
        case Bas :
            //std::cout << "you win !" <<std::endl ;
            Jeu.setTouchTrue(n);
            break;
    }
    return false;
}

std::string CibleHorizontale::typeObjet()const {
    return "Ceci est une CibleHorizontale";
}


}
