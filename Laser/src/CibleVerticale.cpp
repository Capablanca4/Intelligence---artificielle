#include "CibleVerticale.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

CibleVerticale::CibleVerticale(const Cible& cib):Cible{cib}{}

CibleVerticale::CibleVerticale(const int x,const int y,const int cote):Cible{x,y,cote} {}

CibleVerticale::~CibleVerticale(){}

void CibleVerticale::draw(Viewer& fenetre)
{
    int rayon=cote()/2-1;
    setcolor(RED);
    fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon);
    setcolor(WHITE);
    fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/1.5);
    setcolor(RED);
    fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/5.5, rayon/3);
    setcolor(WHITE);
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
