#include "Case.h"
#include "Echiquier.h"

namespace ecran{

Case::~Case(){}

Case::Case(Point& centre,int cote):Point{centre},d_cote{cote}{}

Case::Case(int x,int y,int cote):Point{x,y},d_cote{cote}{}

const Point Case::centre() {
    return Point{x(),y()};}

void Case::changerCentre(const Point& centre){
    Point& LeCentre = *this;
    LeCentre = centre;}

const int Case::cote(){
    return d_cote;}

void Case::changerCote(const int cote){
    d_cote=cote;}

bool Case::touch(Echiquier& plateau) const {
    return false ;
}

coordLaser Case::posNextMoveLaser(Echiquier& plateau) const{
    coordLaser ret{plateau.pointVersCoord(this->x()),
                   plateau.pointVersCoord(this->y())};
    return ret;
}

}
