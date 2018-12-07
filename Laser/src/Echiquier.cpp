#include "Echiquier.h"
#include <iostream>
#include <utility>

namespace ecran{

Echiquier::Echiquier(int nbligne,int nbcolonne,int tailleCase):
        d_taille{tailleCase},
        d_emplacementLaser{},
        in_move{false},
        d_nbligne{nbligne},
        d_nbcolonne{nbcolonne}

        {init(nbligne,nbcolonne);}

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
            line.push_back(new Mur{coordVersPoint(j),coordVersPoint(i),d_taille});
        }
        d_plateau.push_back(line);
    }
}

std::vector<std::vector<Case*> > Echiquier::plateau(){
    return d_plateau;
}

const coordLaser Echiquier::coordLas(){
    return d_emplacementLaser;
}

const int Echiquier::nbligne(){
    return d_nbligne;
}

const int Echiquier::nbcolonne(){
    return d_nbcolonne;
}

Case* Echiquier::emplacementCase(const Point& emplacement) {
    return emplacementCase(emplacement.x(),emplacement.y());
}

Case* Echiquier::emplacementCase(const coordLaser& coor) {
    return emplacementCase(coor.x,coor.y);
}

Case* Echiquier::emplacementCase(const int x,const int y){
    return d_plateau[x][y];
}

void Echiquier::draw(Viewer& fenetre) const{
    for(int i=0;i<d_plateau.size();++i){
        for(int j=0;j<d_plateau[i].size();j++){
            d_plateau[i][j]->draw(fenetre);
        }
    }
}

void Echiquier::setCase(Case* val){
    d_plateau[pointVersCoord(val->x())][pointVersCoord(val->y())]=val;
}

void Echiquier::start(Viewer& fenetre){

    if (!in_move){
        BlocLaser* LeBlocLaser = (BlocLaser*) d_plateau[d_emplacementLaser.x][d_emplacementLaser.y];
        Laser* las = LeBlocLaser->shoot();
        delete d_plateau[pointVersCoord(las->x())][pointVersCoord(las->y())];
        d_plateau[pointVersCoord(las->x())][pointVersCoord(las->y())]=las;
        d_emplacementLaser.x=pointVersCoord(las->x());
        d_emplacementLaser.y=pointVersCoord(las->y());
        in_move =true;}
}

void Echiquier::play(Viewer& fenetre){
    while(in_move){
        fenetre.clear();
        move();
        draw(fenetre);
        fenetre.waitUntilButton();
    }
}

void Echiquier::move(){
    if (in_move){
        Laser* las = (Laser*) emplacementCase(d_emplacementLaser);
        switch (las->direction()){
            case Droite :
                if(d_emplacementLaser.x+1>=d_nbcolonne){
                    std::cout <<"this developper suck : you lose" << std::endl;
                    in_move = false;}
                else {
                    coordLaser nextCoord = d_plateau[d_emplacementLaser.x+1][d_emplacementLaser.y]->posNextMoveLaser(*this);
                    if (d_plateau[nextCoord.x][nextCoord.y]->touch(*this)){

                        std::swap(d_plateau[nextCoord.x][nextCoord.y],
                                  d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]);

                        d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->changerCentre(Point{coordVersPoint(d_emplacementLaser.x),
                                                                                                   coordVersPoint(d_emplacementLaser.y)});
                        d_plateau[nextCoord.x][nextCoord.y]->changerCentre(Point{coordVersPoint(nextCoord.x),
                                                                                 coordVersPoint(nextCoord.y)});
                        d_emplacementLaser=nextCoord;
                        }
                    else {
                        std::cout << "this game is over" << std::endl;
                        in_move = false;
                        }
                    }
                break;
            case Gauche :
                if(d_emplacementLaser.x-1<0){
                    std::cout <<"this developper suck : you lose" << std::endl;
                    in_move = false;}
                else {
                    coordLaser nextCoord = d_plateau[d_emplacementLaser.x-1][d_emplacementLaser.y]->posNextMoveLaser(*this);
                    if (d_plateau[nextCoord.x][nextCoord.y]->touch(*this)){

                        std::swap(d_plateau[nextCoord.x][nextCoord.y],
                                  d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]);

                        d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->changerCentre(Point{coordVersPoint(d_emplacementLaser.x),
                                                                                                coordVersPoint(d_emplacementLaser.y)});
                        d_plateau[nextCoord.x][nextCoord.y]->changerCentre(Point{coordVersPoint(nextCoord.x),
                                                                                 coordVersPoint(nextCoord.y)});
                        d_emplacementLaser=nextCoord;}
                    else {
                        std::cout << "this game is over" << std::endl;
                        in_move = false;
                        }
                    }
                    break;
                case Haut:
                    if(d_emplacementLaser.y+1>=d_nbcolonne){
                        std::cout <<"this developper suck : you lose" << std::endl;
                        in_move = false;}
                    else {
                        coordLaser nextCoord = d_plateau[d_emplacementLaser.x][d_emplacementLaser.y+1]->posNextMoveLaser(*this);
                        if (d_plateau[nextCoord.x][nextCoord.y]->touch(*this)){

                            std::swap(d_plateau[nextCoord.x][nextCoord.y],
                                      d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]);

                            d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->changerCentre(Point{coordVersPoint(d_emplacementLaser.x),
                                                                                                       coordVersPoint(d_emplacementLaser.y)});
                            d_plateau[nextCoord.x][nextCoord.y]->changerCentre(Point{coordVersPoint(nextCoord.x),
                                                                                     coordVersPoint(nextCoord.y)});
                            d_emplacementLaser=nextCoord;
                            }
                        else {
                            std::cout << "this game is over" << std::endl;
                            in_move = false;
                            }
                        }
                        break;
                    case Bas:
                        if(d_emplacementLaser.y-1<0){
                            std::cout <<"this developper suck : you lose" << std::endl;
                            in_move = false;}
                        else {
                            coordLaser nextCoord = d_plateau[d_emplacementLaser.x][d_emplacementLaser.y-1]->posNextMoveLaser(*this);
                            if (d_plateau[nextCoord.x][nextCoord.y]->touch(*this)){

                                std::swap(d_plateau[nextCoord.x][nextCoord.y],
                                          d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]);

                                d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->changerCentre(Point{coordVersPoint(d_emplacementLaser.x),
                                                                                                           coordVersPoint(d_emplacementLaser.y)});
                                d_plateau[nextCoord.x][nextCoord.y]->changerCentre(Point{coordVersPoint(nextCoord.x),
                                                                                         coordVersPoint(nextCoord.y)});
                                d_emplacementLaser=nextCoord;
                                }
                            else {
                                std::cout << "this game is over" << std::endl;
                                in_move = false;
                                }
                            }
                        break;
                }

        }
}

void Echiquier::setCoordLaser(coordLaser coord){
    d_emplacementLaser=coord;
    in_move = true;
}

Echiquier::~Echiquier() {}
}
