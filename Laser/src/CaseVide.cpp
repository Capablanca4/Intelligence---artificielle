#include "CaseVide.h"

namespace ecran{

CaseVide::CaseVide(Point& centre,int cote):Case{centre,cote} {}

CaseVide::CaseVide(int x,int y,int cote):Case{x,y,cote} {}

CaseVide::~CaseVide() {}

void CaseVide::draw(Viewer& fenetre){
    rectangle( this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2 );}

}
