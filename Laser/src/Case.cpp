#include "Case.h"
#include "Echiquier.h"

namespace ecran{

Case::~Case(){}

Case::Case(Point& centre,int cote):Point{centre},d_cote{cote}{}

Case::Case(int x,int y,int cote):Point{x,y},d_cote{cote}{}

Case::Case(Case& cas):Point{cas.centre()},d_cote{cas.cote()}{}

const Point Case::centre()const {
    return Point{x(),y()};}

void Case::changerCentre(const Point& centre){
    Point& LeCentre = *this;
    LeCentre = centre;}

const int Case::cote()const{
    return d_cote;}

void Case::changerCote(const int cote){
    d_cote=cote;}

bool Case::touch(Echiquier& plateau,GameStatut& StatutJeu,int n) {
    return false ;
}

coord Case::posNextMoveLaser(Echiquier& plateau) const{
    coord ret{plateau.pointVersCoord(x()),
                   plateau.pointVersCoord(y())};
    return ret;
}

void Case::clearCase(Viewer& fenetre){
    setfillstyle(SOLID_FILL,BLACK);
    bar(
        fenetre.pixelX(x()-cote()/2),
        fenetre.pixelY(y()+cote()/2),
        fenetre.pixelX(x()+cote()/2),
        fenetre.pixelY(y()-cote()/2)
            );
}

void Case::transformation(Echiquier& plateau){
}

std::string Case::typeObjet()const{
    return "Ceci est une Case";
}


}
