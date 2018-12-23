#include "MiroirGaucheVersHaut.h"
#include <iostream>

namespace ecran{

MiroirGaucheVersHaut::MiroirGaucheVersHaut(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersHaut::MiroirGaucheVersHaut(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersHaut::MiroirGaucheVersHaut(Case& cas):Case{cas}{}

MiroirGaucheVersHaut::~MiroirGaucheVersHaut(){}

void MiroirGaucheVersHaut::draw(Viewer& fenetre){

    line(fenetre.pixelX(x()-cote()/2),
         fenetre.pixelY(y()+cote()/2),
         fenetre.pixelX(x()+cote()/2),
         fenetre.pixelY(y()-cote()/2));
}

coord MiroirGaucheVersHaut::posNextMoveLaser(Echiquier& plateau) const{
Laser* las =(Laser*)plateau.emplacementCase(plateau.coordLas());
    switch (las->direction()){
        case Gauche :
            if(plateau.pointVersCoord(y())+1>=plateau.nbcolonne()){
                return coord{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord(x(),(y()+cote())));
                las->setDirection(Haut);
                return maCase->posNextMoveLaser(plateau);}
           break;

        case Droite :
             if(plateau.pointVersCoord(y())-1<0){
                return coord{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord(x(),(y()-cote())));
                las->setDirection(Bas);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Haut :
            if(plateau.pointVersCoord(x())-1<0){
                return coord{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord((x()-cote()),y()));
                las->setDirection(Gauche);
                return maCase->posNextMoveLaser(plateau);}
            break;

        case Bas :
            if(plateau.pointVersCoord(x())+1>=plateau.nbligne()){
                return coord{plateau.pointVersCoord(x()),plateau.pointVersCoord(y())};}
            else  {
                Case* maCase = plateau.emplacementCase(plateau.pointVersCoord(x()+cote(),y()));
                las->setDirection(Droite);
                return maCase->posNextMoveLaser(plateau);}
            break;
    }
}

void MiroirGaucheVersHaut::transformation(Echiquier& plateau){
    CaseVide* cas = new CaseVide{x(),y(),cote()};
    plateau.setCase(cas);
}

std::string MiroirGaucheVersHaut::typeObjet()const{
    return "Ceci est un MiroirGaucheVersHaut";
}

}
