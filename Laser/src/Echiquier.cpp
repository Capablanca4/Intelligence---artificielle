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

Case*& Echiquier::emplacementCase(Case* cas) {
    return emplacementCase(pointVersCoord(cas));
}

 void Echiquier::setCase(Case* val){
    Case* tamp=emplacementCase(pointVersCoord(val->x(), val->y() ) ) ;
    emplacementCase(pointVersCoord(val->x(), val->y() ) )=val;
    delete tamp;
}

const int Echiquier::nbLigne() const{
    return d_nbligne;
}

const int Echiquier::nbColonne() const{
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

coord Echiquier::pointVersCoord(const Point& centre) const{
    return coord{pointVersCoord(centre.x()),pointVersCoord(centre.y())};
}

int Echiquier::coordVersPoint(int coor) const{
    return coor*d_taille+d_taille/2;
}

Point Echiquier::coordVersPoint(coord coor)const{
    return Point{coordVersPoint(coor.x),coordVersPoint(coor.y)};
}

void Echiquier::play(Game& Jeu){
    while(Jeu.moving()&&Jeu.iteration()<Jeu.maxIteration()&&Jeu.notFinish()){
        std::vector<Laser*> nextLas{};
        for(int i=0;i<Jeu.listLas().size();i++) {
            destinationMove(Jeu,i,nextLas);}
        movable(Jeu,nextLas);
        if(Jeu.moving()){
            Jeu.clearLaser();
            for(int i=0;i<nextLas.size();i++){
                if(nextLas[i]->inMove()){
                    Jeu.addLaser(nextLas[i]);
                    setCase(nextLas[i]);
                    nextLas[i]->clearCase(Jeu.fenetre());
                    nextLas[i]->draw(Jeu.fenetre());
                }
            }
        }
        Jeu.fenetre().waitUntilButton();
        Jeu.increaseIter();

    }
    if(Jeu.moving()&&Jeu.iteration()<Jeu.maxIteration()){
        std::cout << "You win !"<<std::endl;
        Jeu.fenetre().waitUntilButton();
        Jeu.fenetre().closeWindow();
    }
    else {
      std::cout << "Game over (echiquier)" << std::endl;
    }
}

void Echiquier::destinationMove(Game& Jeu,int n,std::vector<Laser*>& nextLas){
    if(Jeu.las(n)->inMove()){
        switch (Jeu.las(n)->direction()){
            case Droite :
                if(Jeu.plateau().pointVersCoord(Jeu.las(n)->x())+1>=d_nbcolonne) losingByBeingOffBoard(Jeu);
                else {
                    d_plateau[Jeu.plateau().pointVersCoord(Jeu.las(n)->x())+1][Jeu.plateau().pointVersCoord(Jeu.las(n)->y())]->nextLaser(Jeu,Jeu.las(n)->direction(),nextLas);
                }
                break;
            case Gauche :
                if(Jeu.plateau().pointVersCoord(Jeu.las(n)->x())-1<0) losingByBeingOffBoard(Jeu);
                else {
                    d_plateau[Jeu.plateau().pointVersCoord(Jeu.las(n)->x())-1][Jeu.plateau().pointVersCoord(Jeu.las(n)->y())]->nextLaser(Jeu,Jeu.las(n)->direction(),nextLas);
                }
                    break;
            case Haut:
                if(Jeu.plateau().pointVersCoord(Jeu.las(n)->y())+1>=d_nbcolonne) losingByBeingOffBoard(Jeu);
                else {
                    d_plateau[Jeu.plateau().pointVersCoord(Jeu.las(n)->x())][Jeu.plateau().pointVersCoord(Jeu.las(n)->y())+1]->nextLaser(Jeu,Jeu.las(n)->direction(),nextLas);
                }
                break;
            case Bas:
                if(Jeu.plateau().pointVersCoord(Jeu.las(n)->y())-1<0) losingByBeingOffBoard(Jeu);
                else {
                    d_plateau[Jeu.plateau().pointVersCoord(Jeu.las(n)->x())][Jeu.plateau().pointVersCoord(Jeu.las(n)->y())-1]->nextLaser(Jeu,Jeu.las(n)->direction(),nextLas);
                }
                break;
        }
    }
}

void Echiquier::losingByBeingOffBoard(Game& Jeu){
    std::cout <<"this developper suck : you lose" << std::endl;
    Jeu.setMovingFalse();
}
void Echiquier::movable(Game& Jeu,const std::vector<Laser*>& nextLas){
    for(int i=0;i<nextLas.size();i++){
        emplacementCase(nextLas[i])->touch(Jeu,nextLas[i]);
        if(!nextLas[i]->inMove()){/** Le laser est sur une Case ou il ne peut pas se déplacer*/
            if(!Jeu.moving()){/** Le Laser n'a pas touché de Cible*/
                break;
            }
        }
    }
}

void Echiquier::draw(Viewer& fenetre) const{
    for(unsigned int i=0;i<d_plateau.size();++i){
        for(unsigned int j=0;j<d_plateau[i].size();j++){
            d_plateau[i][j]->draw(fenetre);
        }
    }
}

std::ostream& operator<<(std::ostream& ost, const std::vector<Case*>& listeCase)
{
    for (auto lig : listeCase)
        if (lig->nameWithHashtag() != "#CaseVide")
            ost << *lig;
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const std::vector<std::vector<Case*> >& plateau)
{
    for (auto& col : plateau)
            ost << col;
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const Echiquier& plateau)
{
    ost << plateau.d_plateau;
    return ost;
}

}
