#include "CaseVide.h"
#include "Echiquier.h"

namespace ecran{

CaseVide::CaseVide(Point& centre,int cote):Case{centre,cote} {}

CaseVide::CaseVide(int x,int y,int cote):Case{x,y,cote} {}

CaseVide::~CaseVide() {}

void CaseVide::draw(Viewer& fenetre){

    rectangle(fenetre.pixelX(this->x()-this->cote()/2),
              fenetre.pixelY(this->y()+this->cote()/2),
              fenetre.pixelX(this->x()+this->cote()/2),
              fenetre.pixelY(this->y()-this->cote()/2 ));}

bool CaseVide::touch(Echiquier& plateau) const {
    return true;
}

}
