#include "MiroirGaucheVersBas.h"
#include "Echiquier.h"
#include <iostream>

namespace ecran {

MiroirGaucheVersBas::MiroirGaucheVersBas(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersBas::MiroirGaucheVersBas(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersBas::~MiroirGaucheVersBas() {}

void MiroirGaucheVersBas::draw(Viewer& fenetre){
    line(this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2);
}

bool MiroirGaucheVersBas::touch(Echiquier& plateau) const{
    return false;
}

coordLaser MiroirGaucheVersBas::posNextMoveLaser(Echiquier& plateau) const{
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
                Case* maCase =plateau.plateau()[plateau.pointVersCoord(this->x())][plateau.pointVersCoord(this->y())+1];
                las->setDirection(Haut);
                return maCase->posNextMoveLaser(plateau);}
            break;
        case Haut :
            if(plateau.pointVersCoord(this->x())-1<0){
                coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
                return ret;}
            else  {
                Case* maCase =plateau.plateau()[plateau.pointVersCoord(this->x())-1][plateau.pointVersCoord(this->y())];
                las->setDirection(Gauche);
                return maCase->posNextMoveLaser(plateau);}
            break;
        case Bas :
            if(plateau.pointVersCoord(this->x())+1>=plateau.nbcolonne()){
                coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
                return ret;}
            else  {
                Case* maCase =plateau.plateau()[plateau.pointVersCoord(this->x())+1][plateau.pointVersCoord(this->y())];
                las->setDirection(Droite);
                return maCase->posNextMoveLaser(plateau);}
            break;
    }
}

}
