#include "Viewer.h"
#include <iostream>

namespace ecran{

Viewer::Viewer(int largeur,int hauteur):
    d_hauteur{hauteur},
    d_largeur{largeur},
    CoordonneesY{0,hauteur,hauteur-decalageY,decalageY},
    CoordonneesX{0,largeur,decalageX,largeur-decalageX}{}

void Viewer::openWindow() {
    std::cout << d_hauteur<< " ,"<< d_largeur << std::endl;
    opengraphsize(d_hauteur+10,d_largeur+13); /** il faut rajouter des constantes car WinBGi rogne le bord des fenêtres */
    d_open=true;
    }

 void Viewer::closeWindow() {
    closegraph();
    d_open=false;
    }

void Viewer::waitUntilButton() {
    getch();
    }

void Viewer::clear(){
    cleardevice();
    }

double Viewer::pixelX(double x){
    return CoordonneesX.destinationFromSource(x);
}

double Viewer::pixelY(double y){
    return CoordonneesY.destinationFromSource(y);
}

}
