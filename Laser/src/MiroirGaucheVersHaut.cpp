#include "MiroirGaucheVersHaut.h"
#include <iostream>

namespace ecran{

MiroirGaucheVersHaut::MiroirGaucheVersHaut(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersHaut::MiroirGaucheVersHaut(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersHaut::~MiroirGaucheVersHaut(){}

void MiroirGaucheVersHaut::draw(Viewer& fenetre){

    int miroirSup[8]={
        fenetre.pixelX(x()+cote()/2),
        fenetre.pixelY(y()+cote()/2),

        fenetre.pixelX(x()+cote()/2),
        fenetre.pixelY(y()+cote()/2)+2,

        fenetre.pixelX(x()-cote()/2)+2,
        fenetre.pixelY(y()-cote()/2),

        fenetre.pixelX(x()-cote()/2),
        fenetre.pixelY(y()-cote()/2)};

        setcolor(LIGHTBLUE);
        fillpoly(4,miroirSup);

        int miroirInf[8]={
        fenetre.pixelX(x()+cote()/2),
        fenetre.pixelY(y()+cote()/2),

        fenetre.pixelX(x()+cote()/2)-2,
        fenetre.pixelY(y()+cote()/2),

        fenetre.pixelX(x()-cote()/2),
        fenetre.pixelY(y()-cote()/2)-2,

        fenetre.pixelX(x()-cote()/2),
        fenetre.pixelY(y()-cote()/2)};

        setcolor(BLUE);
        fillpoly(4,miroirInf);

    setcolor(WHITE);
}

coordLaser MiroirGaucheVersHaut::posNextMoveLaser(Echiquier& plateau) const{
    Laser* las =(Laser*)plateau.plateau()[plateau.coordLas().x][plateau.coordLas().y];
    switch (las->direction()){

        case Gauche :
            if(plateau.pointVersCoord(this->y())-1<0){
                coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
                return ret;}
            else  {
                Case* maCase =plateau.plateau()[plateau.pointVersCoord(this->x())][plateau.pointVersCoord(this->y())-1];
                las->setDirection(Bas);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Droite :
            if(plateau.pointVersCoord(this->y())+1>=plateau.nbligne()){
                coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
                return ret;}
            else  {
                Case* maCase = plateau.plateau()[plateau.pointVersCoord(this->x())][plateau.pointVersCoord(this->y())+1];
                las->setDirection(Haut);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Haut :
            if(plateau.pointVersCoord(this->x())-1<0){
                coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
                return ret;}
            else  {
                Case* maCase = plateau.plateau()[plateau.pointVersCoord(this->x())-1][plateau.pointVersCoord(this->y())];
                las->setDirection(Gauche);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Bas :
            if(plateau.pointVersCoord(this->x())+1>=plateau.nbcolonne()){
                coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
                return ret;}
            else  {
                Case* maCase = plateau.plateau()[plateau.pointVersCoord(this->x())+1][plateau.pointVersCoord(this->y())];
                las->setDirection(Droite);
                return maCase->posNextMoveLaser(plateau);}
            break;
    }
}

}
