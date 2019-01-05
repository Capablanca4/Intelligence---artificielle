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

void MiroirGaucheVersHaut::nextLaser(Game& Jeu,const TDirection& direcLas,std::vector<Laser*>& nextLas) const{
    switch (direcLas){
        case Gauche :
            if(Jeu.plateau().pointVersCoord(y())+1>=Jeu.plateau().nbcolonne()){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()+cote())));
                maCase->nextLaser(Jeu,Haut,nextLas);
                }
           break;

        case Droite :
             if(Jeu.plateau().pointVersCoord(y())-1<0){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
             }
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                maCase->nextLaser(Jeu,Bas,nextLas);
                }
            break;

        case Haut :
            if(Jeu.plateau().pointVersCoord(x())-1<0){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord((x()-cote()),y()));
                maCase->nextLaser(Jeu,Gauche,nextLas);
                }
            break;

        case Bas :
            if(Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbligne()){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else  {
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x()+cote(),y()));
                maCase->nextLaser(Jeu,Droite,nextLas);
                }
            break;
    }
}

void MiroirGaucheVersHaut::transformation(Echiquier& plateau){
    CaseVide* cas = new CaseVide{x(),y(),cote()};
    plateau.setCase(cas);
}

std::ostream& MiroirGaucheVersHaut::name(std::ostream& ost)const{
    ost<<"[MiroirGaucheVersHaut,";
    return ost;
}

std::string MiroirGaucheVersHaut::typeObjet()const{
    return "Ceci est un MiroirGaucheVersHaut";
}

}
