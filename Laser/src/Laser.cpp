#include "Laser.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

Laser::Laser(Point& centre,int cote,const TDirection& direction):Case{centre,cote},d_direction{direction} {}

Laser::Laser(int x,int y ,int cote,const TDirection& direction):Case{x,y,cote},d_direction{direction} {}

Laser::~Laser(){}

TDirection Laser::direction(){
    return d_direction;}

void Laser::setDirection(TDirection direction){
    d_direction=direction;}

void Laser::draw(Viewer& fenetre){
    if (d_direction == Droite|| d_direction == Gauche) line(this->x()-this->cote()/2,this->y(),this->x()+this->cote()/2,this->y());
    else line(this->x(),this->y()-this->cote()/2,this->x(),this->y()+this->cote()/2);}

bool Laser::touch(Echiquier& plateau) const {
return false;}

coordLaser Laser::posNextMoveLaser(Echiquier& plateau) const{
    coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
    return ret;
}

}
