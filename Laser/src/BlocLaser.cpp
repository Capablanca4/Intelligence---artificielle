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
    if (fenetre.open())
    {
    backGround(fenetre);
    const double coordX = fenetre.pixelX(x());
    const double coordY = fenetre.pixelY(y());

    const int pixel=cote()/32;

    int TrapezeEnHaut[8]={
        coordX-5*pixel, coordY-cote()/4,
        coordX+5*pixel, coordY-cote()/4,

        coordX+3*pixel, coordY-cote()/2.3,
        coordX-3*pixel, coordY-cote()/2.3};

    int TrapezeEnBas[8]={

        coordX-5*pixel, coordY+cote()/4,
        coordX+5*pixel, coordY+cote()/4,

        coordX+3*pixel, coordY+cote()/2.3,
        coordX-3*pixel, coordY+cote()/2.3};

    int TrapezeADroite[8]={

        coordX+cote()/4, coordY-5*pixel,
        coordX+cote()/4, coordY+5*pixel,

        coordX+cote()/2.3, coordY+3*pixel,
        coordX+cote()/2.3, coordY-3*pixel};

    int TrapezeAGauche[8]={

        coordX-cote()/4, coordY-5*pixel,
        coordX-cote()/4, coordY+5*pixel,

        coordX-cote()/2.3, coordY+3*pixel,
        coordX-cote()/2.3, coordY-3*pixel};

//~~~~~~~~~~~~~~~~ Bloc Horizontal ~~~~~~~~~~~~~~~~

    if (d_direction == Gauche || d_direction == Droite)
    {
        setcolor (WHITE);
        bar(
        coordX+cote()/2.9, coordY-5*pixel,
        coordX-cote()/3-pixel, coordY+6*pixel);

        setcolor (RED);
        bar(
        fenetre.pixelX(x())+cote()/3, coordY-4*pixel,
        fenetre.pixelX(x())-cote()/3, coordY+5*pixel);

        setcolor (LIGHTRED);

        bar(
        coordX+cote()/3, coordY-2*pixel,
        coordX-cote()/3, coordY+3*pixel);

        setcolor(WHITE);

        if (d_direction==Droite)
            fillpoly(4,TrapezeADroite);
        else
            fillpoly(4,TrapezeAGauche);
    }

//~~~~~~~~~~~~~~~~ Bloc Vertical ~~~~~~~~~~~~~~~~

    else
    {
        setcolor (WHITE);
        bar(
        coordX-5*pixel, fenetre.pixelY(y())+cote()/2.9,
        coordX+6*pixel, fenetre.pixelY(y())-cote()/3-pixel);

        setcolor (RED);
        bar(
        coordX-4*pixel, fenetre.pixelY(y())+cote()/3,
        coordX+5*pixel, fenetre.pixelY(y())-cote()/3);

        setcolor (LIGHTRED);

        bar(
        coordX-2*pixel, fenetre.pixelY(y())+cote()/3,
        coordX+3*pixel, fenetre.pixelY(y())-cote()/3);

        setcolor(WHITE);
        if (d_direction==Bas)
            fillpoly(4,TrapezeEnBas);
        else
            fillpoly(4,TrapezeEnHaut);
    }
    }
}

std::string BlocLaser::typeObjet() const{
    return "Ceci est un BlocLaser";
}

}

