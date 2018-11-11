#include "BlocLaser.h"

namespace ecran{

BlocLaser::BlocLaser(Point& centre,int cote):Case{centre,cote},d_direction{Gauche}{}

BlocLaser::BlocLaser(int x,int y,int cote):Case{x,y,cote},d_direction{Gauche}{}

BlocLaser::~BlocLaser() {}


void BlocLaser::setDirection(TDirection direction){
    d_direction=direction;}

Laser* BlocLaser::shoot(){
    switch (d_direction) {
        case Gauche :
            return new Laser{this->x()-this->cote(),this->y(),this->cote(),Gauche};
            break;
        case Droite :
            return new Laser{this->x()+this->cote(),this->y(),this->cote(),Droite};
            break;
        case Haut :
            return new Laser{this->x(),this->y()+this->cote(),this->cote(),Haut};
            break;
        case Bas :
            return new Laser{this->x(),this->y()-this->cote(),this->cote(),Bas};
            break;
    }
}

void BlocLaser::draw(Viewer& fenetre){
    rectangle( this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2 );
    line(this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2);
    line(this->x()-this->cote()/2,this->y()-this->cote()/2,this->x()+this->cote()/2,this->y()+this->cote()/2);
    switch (d_direction){
        case Gauche :
            line(this->x()-this->cote()/2,this->y(),this->x()-this->cote()*9/10,this->y());
            break;
        case Droite :
            line(this->x()+this->cote()/2,this->y(),this->x()+this->cote()*9/10,this->y());
            break;
        case Haut :
            line(this->x(),this->y()+this->cote()/2,this->x(),this->y()+this->cote()*9/10);
            break;
        case Bas :
            line(this->x(),this->y()-this->cote()/2,this->x(),this->y()-this->cote()*9/10);
            break;
        }
}

}
