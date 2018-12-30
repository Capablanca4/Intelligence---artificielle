#include "BlocLaser.h"
#include "Echiquier.h"

namespace ecran{

BlocLaser::BlocLaser(Point& centre,int cote):Case{centre,cote},d_direction{Gauche}{}

BlocLaser::BlocLaser(int x,int y,int cote):Case{x,y,cote},d_direction{Gauche}{}

BlocLaser::~BlocLaser() {}


void BlocLaser::setDirection(TDirection direction){
    d_direction=direction;}

Laser* BlocLaser::shoot(){
    Laser* retLaser ;
    switch (d_direction) {
        case Gauche :
            retLaser = new Laser{this->x()-this->cote(),this->y(),this->cote(),Gauche};
            break;
        case Droite :
            retLaser = new Laser{this->x()+this->cote(),this->y(),this->cote(),Droite};
            break;
        case Haut :
            retLaser = new Laser{this->x(),this->y()+this->cote(),this->cote(),Haut};
            break;
        case Bas :
            retLaser = new Laser{this->x(),this->y()-this->cote(),this->cote(),Bas};
            break;
    }
    return retLaser;
}

bool BlocLaser::touch(Echiquier& plateau) const {
    return false;
}

void BlocLaser::draw(Viewer& fenetre){

    const int pixel=cote()/32;

    switch (d_direction){

        case Gauche :
        setcolor (RED);
        bar(
        fenetre.pixelX(x())+cote()/3,
        fenetre.pixelY(y()+1)-3*pixel,
        fenetre.pixelX(x())-cote()/3,
        fenetre.pixelY(y()-2)+3*pixel);

        setcolor (LIGHTRED);

        bar(
        fenetre.pixelX(x())+cote()/3,
        fenetre.pixelY(y()+1)-1.5*pixel,
        fenetre.pixelX(x())-cote()/3,
        fenetre.pixelY(y()-2)+1.5*pixel);


            break;
        case Droite :
            line(fenetre.pixelX(this->x()+this->cote()/2),
                 fenetre.pixelY(this->y()),
                 fenetre.pixelX(this->x()+this->cote()*9/10),
                 fenetre.pixelY(this->y()));
            break;
        case Haut :
            line(fenetre.pixelX(this->x()),
                 fenetre.pixelY(this->y()+this->cote()/2),
                 fenetre.pixelX(this->x()),
                 fenetre.pixelY(this->y()+this->cote()*9/10));
            break;
        case Bas :
            line(fenetre.pixelX(this->x()),
                 fenetre.pixelY(this->y()-this->cote()/2),
                 fenetre.pixelX(this->x()),
                 fenetre.pixelY(this->y()-this->cote()*9/10));
            break;
        }
}

coordLaser BlocLaser::posNextMoveLaser(Echiquier& plateau) const{
    coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
    return ret;
}


}
