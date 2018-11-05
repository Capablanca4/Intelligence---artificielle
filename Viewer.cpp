#include "../include/Viewer.h"


namespace ecran{

Viewer::Viewer(int largeur,int hauteur):d_hauteur{hauteur},d_largeur{largeur}{}

void Viewer::openWindow() {
    //initgraph()
    initwindow(d_hauteur,d_largeur);
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

/*void Viewer::drawCible(const Cible& cib){
    cib.draw(*this);
}*/
}
