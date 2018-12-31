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
        setcolor(RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon, rayon/1.5);
        setcolor(WHITE);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon/3);
        setcolor(RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/5.5);
        setcolor(WHITE);
    }
}

bool CibleHorizontale::touch(Game& Jeu,int n){
    Laser* las =(Laser*)Jeu.plateau().emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Gauche :
            break;
        case Droite :
            break;
        case Haut :
            Jeu.setTouchTrue(n);
            break;
        case Bas :
            Jeu.setTouchTrue(n);
            break;
    }
    return false;
}

std::string CibleHorizontale::typeObjet()const {
    return "Ceci est une CibleHorizontale";
}


}
