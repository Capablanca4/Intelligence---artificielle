#include "Echiquier.h"

namespace ecran{

Echiquier::Echiquier(int nbligne,int nbcolonne,int tailleCase):d_taille{tailleCase},d_emplacementLaser{},in_move{false},d_nbligne{nbligne},d_nbcolonne{nbcolonne} { init(nbligne,nbcolonne);}

int Echiquier::pointVersCoord(int x){
    return (x-d_taille/2)/d_taille;
}

int Echiquier::coordVersPoint(int coor){
    return coor*d_taille+d_taille/2;
}

void Echiquier::init(int nbligne,int nbcolonne) {
    d_plateau.reserve(nbcolonne);
    for(int j=0;j<nbcolonne;j++ ){
        std::vector<Case*> line;
        line.reserve(nbligne);
        for(int i=0;i<nbligne;i++){
            line.push_back(new CaseVide{coordVersPoint(i),coordVersPoint(j),d_taille});
        }
        d_plateau.push_back(line);
    }
}

Case* Echiquier::emplacementCase(const Point& emplacement) {
    return emplacementCase(emplacement.x(),emplacement.y());
}

Case* Echiquier::emplacementCase(const coordLaser& coor) {
    return emplacementCase(coor.x,coor.y);
}

Case* Echiquier::emplacementCase(const int x,const int y){
    return d_plateau[pointVersCoord(x)][pointVersCoord(y)];
}

void Echiquier::draw(Viewer fenetre) const{
    for(int i=0;i<d_plateau.size();++i){
        for(int j=0;j<d_plateau[i].size();j++){
            d_plateau[i][j]->draw(fenetre);
        }
    }
}

void Echiquier::start(Viewer fenetre){
    if (!in_move){
        BlocLaser* LeBlocLaser = (BlocLaser*) d_plateau[d_emplacementLaser.x][d_emplacementLaser.y];
        Laser* las = LeBlocLaser->shoot();
        delete d_plateau[pointVersCoord(las->x())][pointVersCoord(las->y())];
        d_plateau[pointVersCoord(las->x())][pointVersCoord(las->y())]=las;
        d_emplacementLaser.x=pointVersCoord(las->x());
        d_emplacementLaser.y=pointVersCoord(las->y());
        in_move =true;}
}

void Echiquier::move(){
    if (in_move){
        Laser* las = (Laser*) emplacementCase(d_emplacementLaser);
        switch (las->direction()){
            case Droite :
                if(d_emplacementLaser.x<d_nbcolonne){
                    d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]
                    las->move();
                    break;
                }
                else{
                    std::cout << "you lose !" <<std::endl ;
                    break;
                }

        }
    }
}

Echiquier::~Echiquier() {}
}
