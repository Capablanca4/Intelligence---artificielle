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

void MiroirGaucheVersBas::nextLaser(Game& Jeu,const TDirection& direcLas,std::vector<Laser*>& nextLas) const{
    switch (direcLas){
        case Gauche :
            if(Jeu.plateau().pointVersCoord(y())-1<0){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else{
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                maCase->nextLaser(Jeu,Bas,nextLas);
            }
            break;

        case Droite :
            if(Jeu.plateau().pointVersCoord(y())+1>=Jeu.plateau().nbColonne()){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else{
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()+cote())));
                maCase->nextLaser(Jeu,Haut,nextLas);
                }
           break;

        case Haut :
            if(Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbLigne()){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else{
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x()+cote(),y()));
                maCase->nextLaser(Jeu,Droite,nextLas);
                }
            break;

        case Bas :
            if(Jeu.plateau().pointVersCoord(x())-1<0){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else{
                Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord((x()-cote()),y()));
                maCase->nextLaser(Jeu,Gauche,nextLas);
                }
            break;
    }
}

void MiroirGaucheVersBas::transformation(Echiquier& plateau){
    MiroirGaucheVersHaut* mir = new MiroirGaucheVersHaut{x(),y(),cote()};
    plateau.setCase(mir);
}

std::string MiroirGaucheVersBas::nameWithHashtag()const {
    return "#MiroirGaucheVersBas";
}

std::string MiroirGaucheVersBas::typeObjet()const{
    return "Ceci est un MiroirGaucheVersBas";
}

}
