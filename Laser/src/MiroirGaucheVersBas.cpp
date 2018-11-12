#include "MiroirGaucheVersBas.h"
#include "Echiquier.h"

namespace ecran {

MiroirGaucheVersBas::MiroirGaucheVersBas(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersBas::MiroirGaucheVersBas(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersBas::~MiroirGaucheVersBas() {}

void MiroirGaucheVersBas::draw(Viewer& fenetre){
    line(this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2);
}

bool MiroirGaucheVersBas::touch(Echiquier& plateau) const{
    Laser* las =(Laser*)plateau.plateau()[plateau.coordLas().x][plateau.coordLas().y];
    switch (las->direction()){
        case Gauche :
            if(plateau.pointVersCoord(this->x())-1<0){return false ;}
            else  {
                las->setDirection(Bas);
                return plateau.plateau()[plateau.pointVersCoord(this->x())-1][plateau.pointVersCoord(this->y)];
            }
            break;
        case Droite :
            if(plateau.pointVersCoord(this->x())+1>=plateau.nbcolonne()){return false;}
            else {
                las->setDirection(Haut);
                return plateau.plateau()[plateau.pointVersCoord(this->x())+1][plateau.pointVersCoord(this->y)];
            }
            break;
        case Haut:
            if(plateau.pointVersCoord(this->y())+1>=plateau.nbligne()){return false;}
            else {
                las->setDirection(Droite);
                return plateau.plateau()[plateau.pointVersCoord(this->x())][plateau.pointVersCoord(this->y)+1];
                }
            break;
        case Bas:
            if(plateau.pointVersCoord(this->y())-1<0){return false;}
            else {
                las->setDirection(Gauche);
                return plateau.plateau()[plateau.pointVersCoord(this->x())][plateau.pointVersCoord(this->y)-1];
                }
            break;
    }
}

}
