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

TDirection Laser::direction(){
    return d_direction;}

void Laser::setDirection(TDirection direction){
    d_direction=direction;}

void Laser::draw(Viewer& fenetre){

    const int epaisseur = cote()/10;
    const int longueur = cote()/1.1;

    if (d_direction == Droite|| d_direction == Gauche)
     setcolor (BROWN);

        bar(
        fenetre.pixelX(x()-(cote()-petitRectangle)/2),
        fenetre.pixelY(y()+(cote()-petitRectangle)/2),
        fenetre.pixelX(x()+(cote()-petitRectangle)/2),
        fenetre.pixelY(y()-(cote()-petitRectangle)/1.9)
            );

        line(fenetre.pixelX(this->x()-this->cote()/2),
             fenetre.pixelY(this->y()),
             fenetre.pixelX(this->x()+this->cote()/2),
             fenetre.pixelY(this->y()));

    else line(fenetre.pixelX(this->x()),
              fenetre.pixelY(this->y()-this->cote()/2),
              fenetre.pixelX(this->x()),
              fenetre.pixelY(this->y()+this->cote()/2));
}

}
