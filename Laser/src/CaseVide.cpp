#include "CaseVide.h"
#include "Echiquier.h"

namespace ecran{

CaseVide::CaseVide(Point& centre,int cote):Case{centre,cote} {}

CaseVide::CaseVide(int x,int y,int cote):Case{x,y,cote} {}

CaseVide::~CaseVide() {}

void CaseVide::draw(Viewer& fenetre){
    if(fenetre.open()){
        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()-cote()*1/4),
             fenetre.pixelY(y()+cote()/2));

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()*1/4)); /** coin haut gauche */

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()+cote()*1/4),
             fenetre.pixelY(y()-cote()/2));

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()*1/4)); /** coin bas droite */

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()+cote()*1/4),
             fenetre.pixelY(y()+cote()/2));

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()+cote()*1/4)); /** coin */

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()-cote()*1/4),
             fenetre.pixelY(y()-cote()/2));

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()-cote()*1/4));/**coin */
        }
    }

bool CaseVide::touch(Game& Jeu,int n){
    return true;
}

void CaseVide::transformation(Echiquier& plateau){
    MiroirGaucheVersBas* mir = new MiroirGaucheVersBas{x(),y(),cote()};
    plateau.setCase(mir);
}

std::string CaseVide::typeObjet()const {
    return "Ceci est une CaseVide";
}

}
