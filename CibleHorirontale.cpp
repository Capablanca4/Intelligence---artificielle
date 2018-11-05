#include "../include/CibleHorirontale.h"

namespace ecran{

CibleHorizontale::CibleHorizontale(const Cible& cib):Cible{cib}{}

CibleHorizontale::CibleHorizontale(const int x,const int y,const int cote):Cible{x,y,cote} {}

CibleHorizontale::~CibleHorizontale(){}

void CibleHorizontale::draw(Viewer& fenetre){
    line(this->x()-this->cote()/2,this->y(),this->x()+this->cote()/2,this->y());
    line(this->x()-this->cote()/2,this->y()-this->cote()/2,this->x()-this->cote()/2,this->y()+this->cote()/2);
    line(this->x()+this->cote()/2,this->y()-this->cote()/2,this->x()+this->cote()/2,this->y()+this->cote()/2);
}
}
