#include "CibleHorirontale.h"
#include <iostream>
#include "Echiquier.h"
#include "Game.h"

namespace ecran{

CibleHorizontale::CibleHorizontale(Point& centre,int cote):Case{centre,cote}{}

CibleHorizontale::CibleHorizontale(const int x,const int y,const int cote):Case{x,y,cote} {}

CibleHorizontale::~CibleHorizontale(){}

void CibleHorizontale::draw(Viewer& fenetre){
    if(fenetre.open()){
        int rayon=cote()/2-1;
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon, rayon/1.5);
        setfillstyle(SOLID_FILL,WHITE);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon/3);
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/5.5);
        setfillstyle(SOLID_FILL,WHITE);
    }
}

void CibleHorizontale::touch(Game& Jeu,Laser* las){
    switch (las->direction()){
        case Gauche :
            Jeu.setMovingFalse();
            break;
        case Droite :
            Jeu.setMovingFalse();
            break;
        case Haut :
            break;
        case Bas :
            break;
    }
    las->setMoveFalse();
}

std::string CibleHorizontale::nameWithHashtag()const {
    return "#CibleHorizontale";
}

std::string CibleHorizontale::typeObjet()const {
    return "Ceci est une CibleHorizontale";
}


}
