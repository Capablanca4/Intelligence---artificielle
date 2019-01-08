#include "Mur.h"
#include <iostream>
#include "Echiquier.h"


namespace ecran{

Mur::~Mur() {}

Mur::Mur(Point& centre,int cote):
        Case{centre,cote} {}

Mur::Mur(int x,int y,int cote):
        Case{x,y,cote} {}

void Mur::draw(Viewer& fenetre){
    if(fenetre.open()){
        backGround(fenetre);

        const int nbPixel = 16;
        int tab [nbPixel*nbPixel]=
        {
        6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0,
        7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0,
        7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0,
        7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 0, 0, 0, 0,
        7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0,
        7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0,
        7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6,
        };

        drawTab(fenetre, tab, nbPixel);
    }
}

std::string Mur::typeObjet()const{
    return "Ceci est un Mur";
}

}
