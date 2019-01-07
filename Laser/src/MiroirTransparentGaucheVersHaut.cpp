#include "MiroirTransparentGaucheVersHaut.h"
#include "Game.h"
namespace ecran{

MiroirTransparentGaucheVersHaut::MiroirTransparentGaucheVersHaut(Point& centre,int cote):Case{centre,cote} {}

MiroirTransparentGaucheVersHaut::MiroirTransparentGaucheVersHaut(int x,int y,int cote):Case{x,y,cote} {}

MiroirTransparentGaucheVersHaut::MiroirTransparentGaucheVersHaut(Case& cas):Case{cas} {}

MiroirTransparentGaucheVersHaut::~MiroirTransparentGaucheVersHaut() {}

void MiroirTransparentGaucheVersHaut::draw(Viewer& fenetre){
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

        setfillstyle(SOLID_FILL,LIGHTRED);
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

        setfillstyle(SOLID_FILL,RED);
        fillpoly(4,miroirInf);
    }
}

void MiroirTransparentGaucheVersHaut::nextLaser(Game& Jeu,const TDirection& direcLas,std::vector<Laser*>& nextLas) const{
    switch (direcLas){
        case Gauche :
            if(Jeu.plateau().pointVersCoord(y())+1>=Jeu.plateau().nbColonne()||Jeu.plateau().pointVersCoord(x())-1<0){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else  {
                Case* maCase1 = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()+cote())));
                maCase1->nextLaser(Jeu,Haut,nextLas);
                Case* maCase2 = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord((x()-cote()),y()));
                maCase2->nextLaser(Jeu,Gauche,nextLas);
                }
           break;

        case Droite :
             if(Jeu.plateau().pointVersCoord(y())-1<0||Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbLigne()){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
             }
            else  {
                Case* maCase1 = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                maCase1->nextLaser(Jeu,Bas,nextLas);
                Case* maCase2= Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x()+cote(),y()));
                maCase2->nextLaser(Jeu,Droite,nextLas);
                }
            break;

        case Haut :
            if(Jeu.plateau().pointVersCoord(x())-1<0||Jeu.plateau().pointVersCoord(y())+1>=Jeu.plateau().nbColonne()){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else  {
                Case* maCase1 = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord((x()-cote()),y()));
                maCase1->nextLaser(Jeu,Gauche,nextLas);
                Case* maCase2 = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()+cote())));
                maCase2->nextLaser(Jeu,Haut,nextLas);
                }
            break;

        case Bas :
            if(Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbLigne()||Jeu.plateau().pointVersCoord(y())-1<0){
                Laser* las=new Laser{x(),y(),cote(),direcLas};
                nextLas.push_back(las);
            }
            else  {
                Case* maCase1= Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x()+cote(),y()));
                maCase1->nextLaser(Jeu,Droite,nextLas);
                Case* maCase2 = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                maCase2->nextLaser(Jeu,Bas,nextLas);
                }
            break;
    }
}

std::string MiroirTransparentGaucheVersHaut::nameWithHashtag()const
{
    return "#MiroirTransparentGaucheVersHaut";
}

std::string MiroirTransparentGaucheVersHaut::typeObjet()const{
    return "Ceci est un MiroirTransparentGaucheVersHaut";
}

}
