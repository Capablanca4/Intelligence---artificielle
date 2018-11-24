#include "Laser.h"
#include <iostream>

namespace ecran{

Laser::Laser(Point& centre,int cote,const TDirection& direction):Case{centre,cote},d_direction{direction},d_inMove{true} {}

Laser::Laser(int x,int y ,int cote,const TDirection& direction):Case{x,y,cote},d_direction{direction},d_inMove{true} {}

Laser::~Laser(){}

TDirection Laser::direction(){
    return d_direction;}

void Laser::setDirection(TDirection direction){
    d_direction=direction;}

const bool Laser::enMouvement() {
    return d_inMove;}

void Laser::move(){
    switch (d_direction) {
        case Gauche :
            changerCentre(Point{this->x()-this->cote(),this->y()});
            break;
        case Droite :
            changerCentre(Point{this->x()+this->cote(),this->y()});
            break;
        case Haut :
            changerCentre(Point{this->x(),this->y()+this->cote()});;
            break;
        case Bas :
            changerCentre(Point{this->x(),this->y()-this->cote()});}
    }

void Laser::draw(Viewer& fenetre){
    if (d_direction == Droite|| d_direction == Gauche) line(this->x()-this->cote()/2,this->y(),this->x()+this->cote()/2,this->y());
    else line(this->x(),this->y()-this->cote()/2,this->x(),this->y()+this->cote()/2);}

}
