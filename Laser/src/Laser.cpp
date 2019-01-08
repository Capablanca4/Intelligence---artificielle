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
    if(fenetre.open()){

        const int pixel = cote()/32;
        const double coordX = fenetre.pixelX(x());
        const double coordY = fenetre.pixelY(y());

        if (d_direction == Droite || d_direction == Gauche){
            setfillstyle(SOLID_FILL,RED);
            bar(
            coordX+16*pixel,
            coordY-4*pixel,
            coordX-16*pixel,
            coordY+4*pixel);

            setfillstyle(SOLID_FILL,LIGHTRED);

            bar(
            coordX+16*pixel,
            coordY-2*pixel,
            coordX-16*pixel,
            coordY+2*pixel);
            }
        else{
            setfillstyle(SOLID_FILL,RED);
            bar(
            coordX-4*pixel,
            coordY+16*pixel,
            coordX+4*pixel,
            coordY-16*pixel);

            setfillstyle(SOLID_FILL,LIGHTRED);

            bar(
            coordX-2*pixel,
            coordY+16*pixel,
            coordX+2*pixel,
            coordY-16*pixel);
            //fillellipse(fenetre.pixelX(x()),fenetre.pixelY(y()),cote()/3,cote()/8)
            }
        setfillstyle(SOLID_FILL,BLACK);
    }
}

std::string Laser::typeObjet()const{
    return "Ceci est un Laser";
}

}
