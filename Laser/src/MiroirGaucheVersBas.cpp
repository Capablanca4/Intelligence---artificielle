#include "MiroirGaucheVersBas.h"
#include "Game.h"
#include <iostream>

/** attention x = mouvement selon l'axe horizontale et y = mouvement selon l'axe verticale*/

namespace ecran {

MiroirGaucheVersBas::MiroirGaucheVersBas(Point& centre,int cote):
        Case{centre,cote}{}

MiroirGaucheVersBas::MiroirGaucheVersBas(int x,int y,int cote):
        Case{x,y,cote}{}

MiroirGaucheVersBas::MiroirGaucheVersBas(Case& cas):
        Case{cas}{}

MiroirGaucheVersBas::~MiroirGaucheVersBas() {}

void MiroirGaucheVersBas::draw(Viewer& fenetre){
    if(fenetre.open()){

        int miroirSup[8]={
            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()+cote()/2),

            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()+cote()/2)+2,

            fenetre.pixelX(x()-cote()/2)+2,
            fenetre.pixelY(y()-cote()/2),

            fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()-cote()/2)};

        setfillstyle(SOLID_FILL,LIGHTBLUE);
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

        setfillstyle(SOLID_FILL,BLUE);
        fillpoly(4,miroirInf);
    }
}

coord MiroirGaucheVersBas::posNextMoveLaser(Game& Jeu,int n) const{
    Laser* las =(Laser*)Jeu.plateau().emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Gauche :
            if(Jeu.plateau().pointVersCoord(y())-1<0){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                las->setDirection(Bas);
                return maCase->posNextMoveLaser(Jeu,n);}
            break;

        case Droite :
            if(Jeu.plateau().pointVersCoord(y())+1>=Jeu.plateau().nbcolonne()){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()+cote())));
                las->setDirection(Haut);
                return maCase->posNextMoveLaser(Jeu,n);}
           break;

        case Haut :
            if(Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbligne()){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x()+cote(),y()));
                las->setDirection(Droite);
                return maCase->posNextMoveLaser(Jeu,n);}
            break;

        case Bas :
            if(Jeu.plateau().pointVersCoord(x())-1<0){
                return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};}
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord((x()-cote()),y()));
                las->setDirection(Gauche);
                return maCase->posNextMoveLaser(Jeu,n);}
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
