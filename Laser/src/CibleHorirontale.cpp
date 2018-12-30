#include "CibleHorirontale.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

CibleHorizontale::CibleHorizontale(const Cible& cib):Cible{cib}{}

CibleHorizontale::CibleHorizontale(const int x,const int y,const int cote):Cible{x,y,cote} {}

CibleHorizontale::~CibleHorizontale(){}

void CibleHorizontale::draw(Viewer& fenetre)
{
    int rayon=cote()/2-1;
    setcolor(RED);
    fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon, rayon/1.5);
    setcolor(WHITE);
    fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon/3);
    setcolor(RED);
    fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/5.5);
    setcolor(WHITE);
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

}
/*
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
*/
