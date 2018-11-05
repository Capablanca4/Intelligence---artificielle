#include "../include/CibleVerticale.h"

namespace ecran{

CibleVerticale::CibleVerticale(const Cible& cib):Cible{cib}{}

CibleVerticale::CibleVerticale(const int x,const int y,const int cote):Cible{x,y,cote} {}

CibleVerticale::~CibleVerticale(){}

void CibleVerticale::draw(Viewer& fenetre){
    line(this->x(),this->y()-this->cote()/2,this->x(),this->y()+this->cote()/2);
    line(this->x()-this->cote()/2,this->y()-this->cote()/2,this->x()+this->cote()/2,this->y()-this->cote()/2);
    line(this->x()-this->cote()/2,this->y()+this->cote()/2,this->x()+this->cote()/2,this->y()+this->cote()/2);
}
}
