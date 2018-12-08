#include "CaseVide.h"
#include "Echiquier.h"

namespace ecran{

CaseVide::CaseVide(Point& centre,int cote):Case{centre,cote} {}

CaseVide::CaseVide(int x,int y,int cote):Case{x,y,cote} {}

CaseVide::~CaseVide() {}

void CaseVide::draw(Viewer& fenetre){
    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2),
         fenetre.pixelX(this->x()-this->cote()*1/4),
         fenetre.pixelY(this->y()+this->cote()/2));

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2),
         fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()*1/4)); /** coin haut gauche */

    line(fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()*1/4),
         fenetre.pixelY(this->y()-this->cote()/2));

    line(fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()*1/4)); /** coin bas droite */

    line(fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()*1/4),
         fenetre.pixelY(this->y()+this->cote()/2));

    line(fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()/2),
         fenetre.pixelX(this->x()+this->cote()/2),
         fenetre.pixelY(this->y()+this->cote()*1/4));

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()-this->cote()*1/4),
         fenetre.pixelY(this->y()-this->cote()/2));

    line(fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()/2),
         fenetre.pixelX(this->x()-this->cote()/2),
         fenetre.pixelY(this->y()-this->cote()*1/4));
    }

bool CaseVide::touch(Echiquier& plateau) const {
    return true;
}

void CaseVide::transformation(Echiquier& plateau){
    MiroirGaucheVersBas* mir = new MiroirGaucheVersBas{this->x(),this->y(),this->cote()};
    plateau.setCase(mir);
}

}
