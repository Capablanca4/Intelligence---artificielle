#include "Viewer.h"
#include <iostream>

namespace ecran{

Viewer::Viewer(int largeur,int hauteur,int decalageX,int decalageY):
    d_hauteur{hauteur},
    d_largeur{largeur},
    decalageX{decalageX},
    decalageY{decalageY},
    d_open{false},
    CoordonneesY{0,largeur,largeur-decalageY,decalageY},
    CoordonneesX{0,hauteur,decalageX,hauteur-decalageX}{}

void Viewer::openWindow() {
    if(!d_open){
        initwindow(d_hauteur+10,d_largeur+13); /** il faut rajouter des constantes car WinBGi rogne le bord des fen�tres */
        d_open=true;
        }
    }

const bool Viewer::open()const{
    return d_open;
}

 void Viewer::closeWindow() {
    if(d_open){
        closegraph();
        d_open=false;
        }
    }

void Viewer::waitUntilButton() {
    if(d_open) getch();
    }

void Viewer::clear(){
    if(d_open) cleardevice();
    }

double Viewer::pixelX(double x){
    return CoordonneesX.destinationFromSource(x);
}

double Viewer::pixelY(double y){
    return CoordonneesY.destinationFromSource(y);
}

void Viewer::waitUntilMouseClicked(int& x,int& y){
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

std::string Viewer::typeObjet()const{
    return "Ceci est un Viewer";
}

std::ostream& operator<<(std::ostream& ost, const Viewer& v)
{
    ost << v.d_hauteur << " " << v.d_largeur << std::endl;
    ost << v.decalageX << " " << v.decalageY << std::endl;

    return ost;
}

}
