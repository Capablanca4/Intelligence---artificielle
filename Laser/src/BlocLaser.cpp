#include "BlocLaser.h"
#include "Echiquier.h"

namespace ecran{

BlocLaser::BlocLaser(Point& centre,int cote):Case{centre,cote},d_direction{Gauche}{}

BlocLaser::BlocLaser(int x,int y,int cote):Case{x,y,cote},d_direction{Gauche}{}

BlocLaser::~BlocLaser() {}

const TDirection BlocLaser::direction()const{
    return d_direction;
}

void BlocLaser::setDirection(TDirection direction){
    d_direction=direction;}

Laser* BlocLaser::shoot(){
    Laser* retLaser ;
    switch (d_direction) {
        case Gauche :
            retLaser = new Laser{x()-cote(),y(),cote(),Gauche};
            break;
        case Droite :
            retLaser = new Laser{x()+cote(),y(),cote(),Droite};
            break;
        case Haut :
            retLaser = new Laser{x(),y()+cote(),cote(),Haut};
            break;
        case Bas :
            retLaser = new Laser{x(),y()-cote(),cote(),Bas};
            break;
    }
    return retLaser;
}

void BlocLaser::draw(Viewer& fenetre){

    rectangle(fenetre.pixelX(x()-cote()/2),
              fenetre.pixelY(y()+cote()/2),
              fenetre.pixelX(x()+cote()/2),
              fenetre.pixelY(y()-cote()/2 ));

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()+cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()-cote()/2));

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()-cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()+cote()/2));

    switch (d_direction){
        case Gauche :
            line(fenetre.pixelX(x()-cote()/2),
                 fenetre.pixelY(y()),
                 fenetre.pixelX(x()-cote()*9/10),
                 fenetre.pixelY(y()));
            break;

        case Droite :
            line(fenetre.pixelX(x()+cote()/2),
                 fenetre.pixelY(y()),
                 fenetre.pixelX(x()+cote()*9/10),
                 fenetre.pixelY(y()));
            break;

        case Haut :
            line(fenetre.pixelX(x()),
                 fenetre.pixelY(y()+cote()/2),
                 fenetre.pixelX(x()),
                 fenetre.pixelY(y()+cote()*9/10));
            break;

        case Bas :
            line(fenetre.pixelX(x()),
                 fenetre.pixelY(y()-cote()/2),
                 fenetre.pixelX(x()),
                 fenetre.pixelY(y()-cote()*9/10));
            break;
        }
}

std::string BlocLaser::typeObjet() const{
    return "Ceci est un BlocLaser";
}

}

