#include "Echiquier.h"
#include <iostream>
#include <utility>
#include "Game.h"

namespace ecran{

Echiquier::Echiquier(int nbligne,int nbcolonne,int tailleCase):
        d_taille{tailleCase},
        d_nbligne{nbligne},
        d_nbcolonne{nbcolonne}

        {init(nbligne,nbcolonne);}

Echiquier::~Echiquier() {}

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

Case*& Echiquier::emplacementCase(const int x,const int y){
    return d_plateau[x][y];
}

Case*& Echiquier::emplacementCase(const coord& coor) {
    return emplacementCase(coor.x,coor.y);
}

Case*& Echiquier::emplacementCase(const Point& emplacement) {
    return emplacementCase(emplacement.x(),emplacement.y());
}

Case*& Echiquier::emplacementCase(const Case*& cas) {
    return emplacementCase(cas->x(),cas->y());
}

 void Echiquier::setCase(Case* val){
    Case* tamp=emplacementCase(pointVersCoord(val->x(), val->y() ) ) ;
    emplacementCase(pointVersCoord(val->x(), val->y() ) )=val;
    delete tamp;
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

int Echiquier::pointVersCoord(int x) const{
    return (x-d_taille/2)/d_taille;
}

coord Echiquier::pointVersCoord(int x,int y) const{
    return coord{pointVersCoord(x),pointVersCoord(y)};
}

coord Echiquier::pointVersCoord(Case* cas) const{
    return coord{pointVersCoord(cas->x()),pointVersCoord(cas->y())};
}

int Echiquier::coordVersPoint(int coor) const{
    return coor*d_taille+d_taille/2;
}

void Echiquier::playAll(Game& Jeu){
    while(!Jeu.finish()&&Jeu.iteration()<Jeu.maxIteration()){
        for(int i=0;i<Jeu.nbLaser();i++) {
            play(Jeu,i);}
        Jeu.fenetre().waitUntilButton();
        Jeu.increaseIter();
    }
    if(Jeu.winning()){
        std::cout << "You win !"<<std::endl;
        Jeu.fenetre().waitUntilButton();
        Jeu.fenetre().closeWindow();
    }
    else {
      std::cout << "Game over" << std::endl;
    }
}

void Echiquier::play(Game& Jeu,int n){
    if(Jeu.inMove(n)){
        move(Jeu,n);
    }
}

void Echiquier::move(Game& Jeu,int n){
    Laser* las = (Laser*) emplacementCase(Jeu.coordLas(n));
    switch (las->direction()){
        case Droite :
            if(Jeu.coordLas(n).x+1>=d_nbcolonne) losingByBeingOffBoard(Jeu,n);
            else {
                coord nextCoord = d_plateau[Jeu.coordLas(n).x+1][Jeu.coordLas(n).y]->posNextMoveLaser(Jeu,n);
                if (emplacementCase(nextCoord)->touch(Jeu,n)){
                    moveLaser(Jeu,nextCoord,n);
                    }
                else gameOver(Jeu,n);
                }
            break;
        case Gauche :
            if(Jeu.coordLas(n).x-1<0) losingByBeingOffBoard(Jeu,n);
            else {
                coord nextCoord = d_plateau[Jeu.coordLas(n).x-1][Jeu.coordLas(n).y]->posNextMoveLaser(Jeu,n);
                if (emplacementCase(nextCoord)->touch(Jeu,n)){
                    moveLaser(Jeu,nextCoord,n);}
                else gameOver(Jeu,n);
                }
                break;
            case Haut:
                if(Jeu.coordLas(n).y+1>=d_nbcolonne) losingByBeingOffBoard(Jeu,n);
                else {
                    coord nextCoord = d_plateau[Jeu.coordLas(n).x][Jeu.coordLas(n).y+1]->posNextMoveLaser(Jeu,n);
                    if (emplacementCase(nextCoord)->touch(Jeu,n)){
                        moveLaser(Jeu,nextCoord,n);
                        }
                    else gameOver(Jeu,n);
                    }
                    break;
                case Bas:
                    if(Jeu.coordLas(n).y-1<0) losingByBeingOffBoard(Jeu,n);
                    else {
                        coord nextCoord = d_plateau[Jeu.coordLas(n).x][Jeu.coordLas(n).y-1]->posNextMoveLaser(Jeu,n);
                        if (emplacementCase(nextCoord)->touch(Jeu,n)){
                            moveLaser(Jeu,nextCoord,n);
                            }
                        else gameOver(Jeu,n);
                        }
                    break;
            }
}

void Echiquier::moveLaser(Game& Jeu,const coord& nextCoord,int n){
    std::swap(emplacementCase(nextCoord),
              emplacementCase(Jeu.coordLas(n)));

    emplacementCase(Jeu.coordLas(n))->changerCentre(Point{coordVersPoint(Jeu.coordLas(n).x),
                                                                coordVersPoint(Jeu.coordLas(n).y)});
    emplacementCase(nextCoord)->changerCentre(Point{coordVersPoint(nextCoord.x),
                                                    coordVersPoint(nextCoord.y)});
    emplacementCase(Jeu.coordLas(n))->clearCase(Jeu.fenetre());
    emplacementCase(Jeu.coordLas(n))->draw(Jeu.fenetre());
    emplacementCase(nextCoord)->clearCase(Jeu.fenetre());
    emplacementCase(nextCoord)->draw(Jeu.fenetre());
    Jeu.setCoordLaser(nextCoord,n);
}

void Echiquier::losingByBeingOffBoard(Game& Jeu,int n){
    std::cout <<"this developper suck : you lose" << std::endl;
    Jeu.setInMoveFalse(n);
}

void Echiquier::gameOver(Game& Jeu,int n){
    Jeu.setInMoveFalse(n);
}

void Echiquier::draw(Viewer& fenetre) const{
    for(unsigned int i=0;i<d_plateau.size();++i){
        for(unsigned int j=0;j<d_plateau[i].size();j++){
            d_plateau[i][j]->draw(fenetre);
        }
    }
}

void Echiquier::start(Game& Jeu,int n){
    BlocLaser* LeBlocLaser = (BlocLaser*) emplacementCase(Jeu.coordLas(n));
    Laser* las = LeBlocLaser->shoot();
    setCase(las);
    Jeu.setCoordLaser(pointVersCoord(las),n);
}

std::ostream& operator<<(std::ostream& ost, Echiquier& plateau){
    ost<<plateau.nbligne()<<" "<<plateau.nbcolonne()<<std::endl;
    for(int i=0;i<plateau.nbcolonne();i++){
        for(int j=0;j<plateau.nbligne();j++){
            ost<<*(plateau.emplacementCase(i,j));
        }
    }
}

}
