#include "CibleVerticale.h"
#include <iostream>
#include "Echiquier.h"
#include "Game.h"

namespace ecran{

CibleVerticale::CibleVerticale(Point& centre,int cote):Case{centre,cote}{}

CibleVerticale::CibleVerticale(const int x,const int y,const int cote):Case{x,y,cote} {}

CibleVerticale::~CibleVerticale(){}

void CibleVerticale::draw(Viewer& fenetre){
    if(fenetre.open()){
        int rayon=cote()/2-1;
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon);
        setfillstyle(SOLID_FILL,WHITE);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/1.5);
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/5.5, rayon/3);
        setfillstyle(SOLID_FILL,WHITE);
    }
}

void CibleVerticale::touch(Game& Jeu,Laser* las){
    switch (las->direction()){
        case Gauche :
            break;
        case Droite :
            break;
        case Haut :
            Jeu.setMovingFalse();
            break;
        case Bas :
            Jeu.setMovingFalse();
            break;
    }
    las->setMoveFalse();
}

std::ostream& CibleVerticale::name(std::ostream& ost)const{
    ost<<"[CibleVerticale,";
    return ost;
}

std::string CibleVerticale::typeObjet()const {
    return "Ceci est une CibleVerticale";
}

}
