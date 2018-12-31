#include "MiroirGaucheVersHaut.h"
#include "Game.h"
#include <iostream>

namespace ecran{

MiroirGaucheVersHaut::MiroirGaucheVersHaut(Point& centre,int cote):Case{centre,cote}{}

MiroirGaucheVersHaut::MiroirGaucheVersHaut(int x,int y,int cote):Case{x,y,cote}{}

MiroirGaucheVersHaut::MiroirGaucheVersHaut(Case& cas):Case{cas}{}

MiroirGaucheVersHaut::~MiroirGaucheVersHaut(){}

void MiroirGaucheVersHaut::draw(Viewer& fenetre){
    if(fenetre.open()){

        int miroirSup[8]={
            fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()+cote()/2),

            fenetre.pixelX(x()-cote()/2)+2,
            fenetre.pixelY(y()+cote()/2),

            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()-cote()/2)-2,

            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()-cote()/2)};

        setfillstyle(SOLID_FILL,LIGHTBLUE);
        fillpoly(4,miroirSup);

        int miroirInf[8]={
            fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()+cote()/2),

            fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()+cote()/2)+2,

            fenetre.pixelX(x()+cote()/2)-2,
            fenetre.pixelY(y()-cote()/2),

            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()-cote()/2)};

        setfillstyle(SOLID_FILL,BLUE);
        fillpoly(4,miroirInf);
    }
}

coord MiroirGaucheVersHaut::posNextMoveLaser(Game& Jeu,int n) const{
Laser* las =(Laser*)Jeu.plateau().emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Gauche :
            if(Jeu.plateau().pointVersCoord(y())+1>=Jeu.plateau().nbcolonne()){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()+cote())));
                las->setDirection(Haut);
                return maCase->posNextMoveLaser(Jeu,n);}
           break;

        case Droite :
             if(Jeu.plateau().pointVersCoord(y())-1<0){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                las->setDirection(Bas);
                return maCase->posNextMoveLaser(Jeu,n);}
            break;

        case Haut :
            if(Jeu.plateau().pointVersCoord(x())-1<0){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord((x()-cote()),y()));
                las->setDirection(Gauche);
                return maCase->posNextMoveLaser(Jeu,n);}
            break;

        case Bas :
            if(Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbligne()){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x()+cote(),y()));
                las->setDirection(Droite);
                return maCase->posNextMoveLaser(Jeu,n);}
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
