#include "Viewer.h"
#include <iostream>

namespace ecran{

Viewer::Viewer(int largeur,int hauteur):
    d_hauteur{hauteur},
    d_largeur{largeur},
    CoordonneesY{0,largeur,largeur-decalageY,decalageY},
    CoordonneesX{0,hauteur,decalageX,hauteur-decalageX}{}

void Viewer::openWindow() {
    //opengraphsize(d_hauteur+10,d_largeur+13); /** il faut rajouter des constantes car WinBGi rogne le bord des fen�tres */
    initwindow(d_hauteur+10,d_largeur+13); /** il faut rajouter des constantes car WinBGi rogne le bord des fen�tres */
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

void Viewer::waitUntilMouseCkicked(int& x,int& y){
    while (!ismouseclick(WM_LBUTTONDOWN)){
        delay(200);}
    getmouseclick(WM_LBUTTONDOWN, x, y);
}

double Viewer::reversePixelX(double x){
    return CoordonneesX.sourceFromDestination(x);
}

double Viewer::reversePixelY(double y){
    return CoordonneesY.sourceFromDestination(y);
}

}
