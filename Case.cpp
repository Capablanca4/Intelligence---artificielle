#include "Case.h"
#include "Game.h"

namespace ecran{

Case::~Case(){}

Case::Case(Point& centre,int cote):Point{centre},d_cote{cote}{}

Case::Case(int x,int y,int cote):Point{x,y},d_cote{cote}{}

Case::Case(Case& cas):Point{cas.centre()},d_cote{cas.cote()}{}

const Point Case::centre()const {
    return Point{x(),y()};}

const int Case::cote()const{
    return d_cote;}

void Case::touch(Game& Jeu,Laser* las) {
    las->setMoveFalse();
    Jeu.setMovingFalse();
}

void Case::nextLaser(Game& Jeu,const TDirection& direcLas,std::vector<Laser*>& nextLas) const{
    Laser* las=new Laser{x(),y(),d_cote,direcLas};
    nextLas.push_back(las);
}

void Case::clearCase(Viewer& fenetre){
    if(fenetre.open()){
        setfillstyle(SOLID_FILL,BLACK);
        bar(
            fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()+cote()/2),
            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()-cote()/2));
    }
}

void Case::transformation(Echiquier& plateau){
}

std::string Case::typeObjet()const{
    return "Ceci est une Case";
}

std::string Case::nameWithHashtag()const{ /// !!! Temporaire (= 0)
    return "#Case";
}

std::string Case::specificitiesCase()const
{
    return "";
}

std::ostream& operator<<(std::ostream& ost,const Case& cas){
    ost<<cas.nameWithHashtag()<<std::endl;
    cas.writePoint(ost);
    ost<<std::endl;
    ost<<cas.specificitiesCase()<<std::endl;

    return ost;
}

}
