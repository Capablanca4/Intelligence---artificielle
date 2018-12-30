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

void Laser::draw(Viewer& fenetre)
{
    const int pixel=cote()/32;
    if (d_direction == Droite || d_direction == Gauche)
    {
        setcolor (RED);
        bar(
        fenetre.pixelX(x())+cote()/2,
        fenetre.pixelY(y()+1)-3*pixel,
        fenetre.pixelX(x())-cote()/2,
        fenetre.pixelY(y()-2)+3*pixel);

        setcolor (LIGHTRED);

        bar(
        fenetre.pixelX(x())+cote()/2,
        fenetre.pixelY(y()+1)-1.5*pixel,
        fenetre.pixelX(x())-cote()/2,
        fenetre.pixelY(y()-2)+1.5*pixel);
    }

    else
    {
        setcolor (RED);
        bar(
        fenetre.pixelX(x())-3*pixel,
        fenetre.pixelY(y()+1)+cote()/2,
        fenetre.pixelX(x())+3*pixel,
        fenetre.pixelY(y()-2)-cote()/2);

        setcolor (LIGHTRED);

        bar(
        fenetre.pixelX(x())-1.5*pixel,
        fenetre.pixelY(y()+1)+cote()/2,
        fenetre.pixelX(x())+1.5*pixel,
        fenetre.pixelY(y()-2)-cote()/2);
        //fillellipse(fenetre.pixelX(x()),fenetre.pixelY(y()),cote()/3,cote()/8)
    }
    setcolor(WHITE);
}

}
