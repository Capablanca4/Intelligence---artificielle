#include "MiroirTransparentGaucheVersBas.h"
#include "Game.h"

namespace ecran{

MiroirTransparentGaucheVersBas::MiroirTransparentGaucheVersBas(Point& centre,int cote):Case{centre,cote} {}

MiroirTransparentGaucheVersBas::MiroirTransparentGaucheVersBas(int x,int y,int cote):Case{x,y,cote} {}

MiroirTransparentGaucheVersBas::MiroirTransparentGaucheVersBas(Case& cas):Case{cas} {}

MiroirTransparentGaucheVersBas::~MiroirTransparentGaucheVersBas() {}

void MiroirTransparentGaucheVersBas::draw(Viewer& fenetre){

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

        setfillstyle(SOLID_FILL,RED);
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

        setfillstyle(SOLID_FILL,LIGHTRED);
        fillpoly(4,miroirInf);
    }
}

/*std::vector<coord> MiroirTransparentGaucheVersBas::posNextMoveLaser(Game& Jeu,int n) const{
    Laser* las =(Laser*)Jeu.plateau().emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Gauche :
            if(Jeu.plateau().pointVersCoord(y())-1<0){
                return std::vector<coord>{};
                }
            else  {
                if(Jeu.plateau().pointVersCoord(x())+1>=Jeu.plateau().nbligne()){
                    return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};
                }
                else{
                    coord newLaserCoord=Jeu.plateau().emplacementCase(x()+cote(),y()).newLaser();
                    if(newLaserCoord==coord{x()+cote(),y()}){
                        return coord{Jeu.plateau().pointVersCoord(x()),Jeu.plateau().pointVersCoord(y())};
                    }
                    else{
                        Laser* las2 = new Laser{newLaserCoord};/// Ajout d'un Laser
                        Jeu.plateau().setCase(las2);
                        Jeu.addLaser(newLaserCoord);
                        Case* maCase = Jeu.plateau().emplacementCase(Jeu.plateau().pointVersCoord(x(),(y()-cote())));
                        las->setDirection(Bas);
                        return maCase->posNextMoveLaser(Jeu,n);
                    }
                }
            }
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
}*/


std::string MiroirTransparentGaucheVersBas::typeObjet()const{
    return "Ceci est un MiroirTransparentGaucheVersBas";
}

}
