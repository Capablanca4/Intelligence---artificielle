#include "CibleVerticale.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

CibleVerticale::CibleVerticale(Point& centre,int cote):Case{centre,cote}{}

CibleVerticale::CibleVerticale(const int x,const int y,const int cote):Case{x,y,cote} {}

CibleVerticale::~CibleVerticale(){}

void CibleVerticale::draw(Viewer& fenetre){

    line(fenetre.pixelX(x()),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()),
         fenetre.pixelY(y()+cote()/2));

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()-cote()/2));

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()+cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()+cote()/2));
}

bool CibleVerticale::touch(Echiquier& plateau,GameStatut& StatutJeu,int n){
    Laser* las =(Laser*)plateau.emplacementCase(plateau.coordLas());
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

std::string CibleVerticale::typeObjet()const {
    return "Ceci est une CibleVerticale";
}

}
