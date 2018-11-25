#include "CaseVide.h"
#include "Echiquier.h"

namespace ecran{

CaseVide::CaseVide(Point& centre,int cote):Case{centre,cote} {}

CaseVide::CaseVide(int x,int y,int cote):Case{x,y,cote} {}

CaseVide::~CaseVide() {}

void CaseVide::draw(Viewer& fenetre){
    rectangle( this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2 );}

bool CaseVide::touch(Echiquier& plateau) const {
    return true;
}

coordLaser CaseVide::posNextMoveLaser(Echiquier& plateau) const{
    coordLaser ret{plateau.pointVersCoord(this->x()),plateau.pointVersCoord(this->y())};
    return ret;
}

}
