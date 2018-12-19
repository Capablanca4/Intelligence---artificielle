#include "Echiquier.h"
#include <iostream>
#include <utility>

namespace ecran{

Echiquier::Echiquier(int nbligne,int nbcolonne,int tailleCase):
        d_taille{tailleCase},
        d_emplacementLaser{},
        d_nbligne{nbligne},
        d_nbcolonne{nbcolonne}

        {init(nbligne,nbcolonne);}

int Echiquier::pointVersCoord(int x) const{
    return (x-d_taille/2)/d_taille;
}

coord Echiquier::pointVersCoord(int x,int y) const{
    return coord{pointVersCoord(x),pointVersCoord(y)};
}

int Echiquier::coordVersPoint(int coor) const{
    return coor*d_taille+d_taille/2;
}

void Echiquier::init(int nbligne,int nbcolonne) {
    d_plateau.reserve(nbcolonne);
    for(int j=0;j<nbcolonne;j++ ){
        std::vector<Case*> line;
        line.reserve(nbligne);
        for(int i=0;i<nbligne;i++){
            line.push_back(new CaseVide{coordVersPoint(j),coordVersPoint(i),d_taille});
        }
        d_plateau.push_back(line);
    }
}

std::vector<std::vector<Case*> > Echiquier::plateau(){
    return d_plateau;
}

const coord Echiquier::coordLas() const{
    return d_emplacementLaser;
}

const int Echiquier::nbligne() const{
    return d_nbligne;
}

const int Echiquier::nbcolonne() const{
    return d_nbcolonne;
}

const int Echiquier::taille() const{
    return d_taille;
}

Case*& Echiquier::emplacementCase(const Point& emplacement) {
    return emplacementCase(emplacement.x(),emplacement.y());
}

Case*& Echiquier::emplacementCase(const coord& coor) {
    return emplacementCase(coor.x,coor.y);
}

Case*& Echiquier::emplacementCase(const int x,const int y){
    return d_plateau[x][y];
}

void Echiquier::draw(Viewer& fenetre) const{
    for(unsigned int i=0;i<d_plateau.size();++i){
        for(unsigned int j=0;j<d_plateau[i].size();j++){
            d_plateau[i][j]->draw(fenetre);
        }
    }
}

void Echiquier::setCase(Case* val){
    Case* tamp=emplacementCase(pointVersCoord(val->x(), val->y() ) ) ;
    emplacementCase(pointVersCoord(val->x(), val->y() ) )=val;
    delete tamp;
}

void Echiquier::start(Viewer& fenetre){
    BlocLaser* LeBlocLaser = (BlocLaser*) d_plateau[d_emplacementLaser.x][d_emplacementLaser.y];
    Laser* las = LeBlocLaser->shoot();
    delete d_plateau[pointVersCoord(las->x())][pointVersCoord(las->y())];
    d_plateau[pointVersCoord(las->x())][pointVersCoord(las->y())]=las;
    d_emplacementLaser.x=pointVersCoord(las->x());
    d_emplacementLaser.y=pointVersCoord(las->y());
}

void Echiquier::play(Viewer& fenetre,GameStatut& StatutJeu,int n){
    while(StatutJeu.inMove(n)){
        move(fenetre,StatutJeu,n);
        fenetre.waitUntilButton();
    }
}

void Echiquier::moveLaser(Viewer& fenetre,const coord& nextCoord){
    std::swap(d_plateau[nextCoord.x][nextCoord.y],
              d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]);

    d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->changerCentre(Point{coordVersPoint(d_emplacementLaser.x),
                                                                            coordVersPoint(d_emplacementLaser.y)});
    d_plateau[nextCoord.x][nextCoord.y]->changerCentre(Point{coordVersPoint(nextCoord.x),
                                                             coordVersPoint(nextCoord.y)});
    d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->clearCase(fenetre);
    d_plateau[d_emplacementLaser.x][d_emplacementLaser.y]->draw(fenetre);
    d_plateau[nextCoord.x][nextCoord.y]->clearCase(fenetre);
    d_plateau[nextCoord.x][nextCoord.y]->draw(fenetre);
    d_emplacementLaser=nextCoord;
}

void Echiquier::losingByBeingOffBoard(GameStatut& StatutJeu,int n){
    std::cout <<"this developper suck : you lose" << std::endl;
    StatutJeu.setInMoveFalse(n);
}

void Echiquier::gameOver(GameStatut& StatutJeu,int n){
    std::cout << "this game is over" << std::endl;
    StatutJeu.setInMoveFalse(n);
}

void Echiquier::move(Viewer& fenetre,GameStatut& StatutJeu,int n){
    Laser* las = (Laser*) emplacementCase(d_emplacementLaser);
    switch (las->direction()){
        case Droite :
            if(d_emplacementLaser.x+1>=d_nbcolonne) losingByBeingOffBoard(StatutJeu,n);
            else {
                coord nextCoord = d_plateau[d_emplacementLaser.x+1][d_emplacementLaser.y]->posNextMoveLaser(*this);
                if (emplacementCase(nextCoord)->touch(*this,StatutJeu,n)){
                    moveLaser(fenetre,nextCoord);
                    }
                else gameOver(StatutJeu,n);
                }
            break;
        case Gauche :
            if(d_emplacementLaser.x-1<0) losingByBeingOffBoard(StatutJeu,n);
            else {
                coord nextCoord = d_plateau[d_emplacementLaser.x-1][d_emplacementLaser.y]->posNextMoveLaser(*this);
                if (emplacementCase(nextCoord)->touch(*this,StatutJeu,n)){
                    moveLaser(fenetre,nextCoord);}
                else gameOver(StatutJeu,n);
                }
                break;
            case Haut:
                if(d_emplacementLaser.y+1>=d_nbcolonne) losingByBeingOffBoard(StatutJeu,n);
                else {
                    coord nextCoord = d_plateau[d_emplacementLaser.x][d_emplacementLaser.y+1]->posNextMoveLaser(*this);
                    if (emplacementCase(nextCoord)->touch(*this,StatutJeu,n)){
                        moveLaser(fenetre,nextCoord);
                        }
                    else gameOver(StatutJeu,n);
                    }
                    break;
                case Bas:
                    if(d_emplacementLaser.y-1<0) losingByBeingOffBoard(StatutJeu,n);
                    else {
                        coord nextCoord = d_plateau[d_emplacementLaser.x][d_emplacementLaser.y-1]->posNextMoveLaser(*this);
                        if (emplacementCase(nextCoord)->touch(*this,StatutJeu,n)){
                            moveLaser(fenetre,nextCoord);
                            }
                        else gameOver(StatutJeu,n);
                        }
                    break;
            }
}

void Echiquier::setCoordLaser(coord coord){
    d_emplacementLaser=coord;
}

Echiquier::~Echiquier() {}
}
