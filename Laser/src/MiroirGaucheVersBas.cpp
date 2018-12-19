#include "MiroirGaucheVersBas.h"
#include "Echiquier.h"
#include <iostream>

namespace ecran {

MiroirGaucheVersBas::MiroirGaucheVersBas(Point& centre,int cote):
        Case{centre,cote}{}

MiroirGaucheVersBas::MiroirGaucheVersBas(int x,int y,int cote):
        Case{x,y,cote}{}

MiroirGaucheVersBas::~MiroirGaucheVersBas() {}

void MiroirGaucheVersBas::draw(Viewer& fenetre){

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()+cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()-cote()/2));
}

coordLaser MiroirGaucheVersBas::posNextMoveLaser(Echiquier& plateau) const{
    Laser* las =(Laser*)plateau.plateau()[plateau.coordLas().x][plateau.coordLas().y];
    switch (las->direction()){

        case Gauche :
            if(plateau.pointVersCoord(y())+1>=plateau.nbligne()){
                coordLaser ret{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};
                return ret;}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord(x(),(y()+1)));
                las->setDirection(Haut);
                return maCase->posNextMoveLaser(plateau);}
           break;

        case Droite :
             if(plateau.pointVersCoord(y())-1<0){
                coordLaser ret{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};
                return ret;}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord(x(),(y()-1)));
                las->setDirection(Bas);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Haut :
            if(plateau.pointVersCoord(x())-1<0){
                coordLaser ret{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};
                return ret;}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord((x()-1),y()));
                las->setDirection(Gauche);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Bas :
            if(plateau.pointVersCoord(x())+1>=plateau.nbcolonne()){
                coordLaser ret{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};
                return ret;}
            else  {
                Case* maCase =plateau.emplacementCase(plateau.pointVersCoord((x()+1),y()));
                las->setDirection(Droite);
                return maCase->posNextMoveLaser(plateau);}
            break;
    }
}

void MiroirGaucheVersBas::transformation(Echiquier& plateau){
    MiroirGaucheVersHaut* mir = new MiroirGaucheVersHaut{x(),y(),cote()};
    plateau.setCase(mir);
}

std::string MiroirGaucheVersBas::typeObjet()const{
    return "Ceci est un MiroirGaucheVersBas";
}

}
