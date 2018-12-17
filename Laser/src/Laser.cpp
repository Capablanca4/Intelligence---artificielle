#include "Laser.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

Laser::Laser(Point& centre,int cote,const TDirection& direction):
        Case{centre,cote},
        d_direction{direction} {}

Laser::Laser(int x,int y ,int cote,const TDirection& direction):
        Case{x,y,cote},
        d_direction{direction} {}

Laser::~Laser(){}

const TDirection Laser::direction()const{
    return d_direction;}

void Laser::setDirection(TDirection direction){
    d_direction=direction;}

void Laser::draw(Viewer& fenetre){

    const int epaisseur = cote()/10;
    const int longueur = cote()/1.1;
    const int petitRectangle=50;

    if (d_direction == Droite|| d_direction == Gauche){
     setcolor (BROWN);

        bar(
        fenetre.pixelX(x()-(cote()-petitRectangle)/2),
        fenetre.pixelY(y()+(cote()-petitRectangle)/2),
        fenetre.pixelX(x()+(cote()-petitRectangle)/2),
        fenetre.pixelY(y()-(cote()-petitRectangle)/1.9)
            );

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()),
             fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()));
        setcolor (WHITE);
}
    else line(fenetre.pixelX(x()),
              fenetre.pixelY(y()-cote()/2),
              fenetre.pixelX(x()),
              fenetre.pixelY(y()+cote()/2));
}

std::string Laser::typeObjet()const{
    return "Ceci est un Laser";
}

}
