#include "Cible.h"
#include <iostream>
#include "Game.h"

namespace ecran{

Cible::~Cible() {}

Cible::Cible(Point& centre,int cote):Case{centre,cote} {}

Cible::Cible(const int x,const int y,const int cote):Case{x,y,cote} {}

void Cible::draw(Viewer& fenetre){
    if(fenetre.open()){
        int rayon=cote()/2-1;
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon, rayon);
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon/1.5);
        setfillstyle(SOLID_FILL,RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/3);
        setfillstyle(SOLID_FILL,WHITE);
    }

}

void Cible::touch(Game& Jeu,Laser* las){
    las->setMoveFalse();
}

std::string Cible::nameWithHashtag()const {
    return "#Cible";
}


std::string Cible::typeObjet()const{
    return "Ceci est une Cible";
}

}
