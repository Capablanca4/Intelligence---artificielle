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
        setcolor(RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/1.5, rayon);
        setcolor(WHITE);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/3, rayon/1.5);
        setcolor(RED);
        fillellipse(fenetre.pixelX(x()), fenetre.pixelY(y()), rayon/5.5, rayon/3);
        setcolor(WHITE);
    }
}

bool CibleVerticale::touch(Game& Jeu,int n){
    Laser* las =(Laser*)Jeu.plateau().emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Gauche :
            Jeu.setTouchTrue(n);
            break;
        case Droite :
            Jeu.setTouchTrue(n);
            break;
        case Haut :
            break;
        case Bas :
            break;
    }
    return false;
}

std::string CibleVerticale::typeObjet()const {
    return "Ceci est une CibleVerticale";
}

}
