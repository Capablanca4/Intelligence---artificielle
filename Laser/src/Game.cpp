#include "Game.h"
#include <iostream>

namespace ecran{

Game::Game(int nbLigne,int nbColonne,int cote,int maxIter):
    d_echiquier{nbLigne,nbColonne,cote},
    d_fenetre{nbLigne*cote,nbColonne*cote+200},
    d_boutonQuit{nbLigne*cote+100,nbColonne*cote-100,70,20,"Quitter"},
    d_boutonDemarrer{nbLigne*cote+100,nbColonne*cote-200,70,20,"Demarrer"},
    d_score{nbLigne*cote+100,nbColonne*cote-300,70,20} ,

    listLaser{},
    d_iteration{0},
    maxIter{maxIter},
    d_moving{true} {}

void Game::openGame(){
    if(!d_fenetre.open()){
        d_fenetre.openWindow();
    }
}

void Game::draw(){
    if(d_fenetre.open()){
        d_echiquier.draw(d_fenetre);
        d_boutonQuit.draw(d_fenetre);
        d_boutonDemarrer.draw(d_fenetre);
        d_score.draw(d_fenetre);
    }
}

void Game::closeGame(){
    if(d_fenetre.open()) d_fenetre.closeWindow();
}

void Game::waitUntilMouseCkicked(){
    int x,y;
    bool touchedButton=false;
    while(!touchedButton){
        d_fenetre.waitUntilMouseCkicked(x,y);
        double d_x=d_fenetre.reversePixelX(x)*1.0/d_echiquier.taille();
        double d_y=d_fenetre.reversePixelY(y)*1.0/d_echiquier.taille();
        if(d_x>=0 && d_x<d_echiquier.nbcolonne() && d_y>=0 && d_y<d_echiquier.nbligne()){ /** On touche l'échiquier*/
            x=d_x; y=d_y;
            Case* cas= (Case*)d_echiquier.emplacementCase(x,y);
            cas->transformation(d_echiquier);
            cas= (Case*)d_echiquier.emplacementCase(x,y);
            cas->clearCase(d_fenetre);
            cas->draw(d_fenetre);
        }
        if(x>=d_fenetre.pixelX(d_boutonQuit.centre().x()-d_boutonQuit.largeur()/2) &&
           x<=d_fenetre.pixelX(d_boutonQuit.centre().x()+d_boutonQuit.largeur()/2) &&
           y>=d_fenetre.pixelY(d_boutonQuit.centre().y()+d_boutonQuit.hauteur()/2) &&
           y<=d_fenetre.pixelY(d_boutonQuit.centre().y()-d_boutonQuit.hauteur()/2) ){
                touchedButton=true;
                closeGame();
           }
        if(x>=d_fenetre.pixelX(d_boutonDemarrer.centre().x()-d_boutonDemarrer.largeur()/2) &&
           x<=d_fenetre.pixelX(d_boutonDemarrer.centre().x()+d_boutonDemarrer.largeur()/2) &&
           y>=d_fenetre.pixelY(d_boutonDemarrer.centre().y()+d_boutonDemarrer.hauteur()/2) &&
           y<=d_fenetre.pixelY(d_boutonDemarrer.centre().y()-d_boutonDemarrer.hauteur()/2) ){
                touchedButton=true;
                d_echiquier.play(*this);
           }

    }
}

const std::vector<Laser*> Game::listLas() const{
    return listLaser;
}

Laser* Game::las(int n) const{
    return listLaser[n];
}

const int Game::iteration() const{
    return d_iteration;
}

Echiquier& Game::plateau(){
    return d_echiquier;
}

Viewer& Game::fenetre(){
    return d_fenetre;
}

const int Game::score() const{
    return d_score.score();
}

const int Game::maxIteration() const{
    return maxIter;
}

const bool Game::moving() const{
    return d_moving;
}

void Game::addScore(int score){
    d_score.addScore(score);
    if(d_fenetre.open()){
        d_score.clear(d_fenetre);
        d_score.draw(d_fenetre);}
}

void Game::increaseIter(){
    d_iteration++;
}

void Game::setMovingFalse(){
    d_moving=false;
}

bool Game::notFinish() const{
    bool test=false;
    for(int i=0;i<listLaser.size();i++){
        if (listLaser[i]->inMove()) {
            test=true;
            break;
            }
        }
    return test;
}

void Game::addLaser(Laser* las){
    listLaser.push_back(las);
}

void Game::clearLaser(){
    while(!listLaser.empty()) listLaser.pop_back();
}


void Game::test(){
    Laser* las1 = new Laser{d_echiquier.coordVersPoint(0),d_echiquier.coordVersPoint(19),d_echiquier.taille(),ecran::Droite};
    MiroirGaucheVersHaut* mir= new MiroirGaucheVersHaut{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(19),d_echiquier.taille()};
    Cible* cible1= new Cible{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(0),d_echiquier.taille()};
    Cible* cible2= new Cible{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(1),d_echiquier.taille()};
    Monstre* monstre = new Monstre{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(10),d_echiquier.taille()};
    Mur* mur= new Mur{d_echiquier.coordVersPoint(1),d_echiquier.coordVersPoint(1),d_echiquier.taille()};
    Laser* las2 = new Laser{d_echiquier.coordVersPoint(19),d_echiquier.coordVersPoint(0),d_echiquier.taille(),ecran::Gauche};
    addLaser(las1);
    addLaser(las2);
    d_echiquier.setCase(las1);
    d_echiquier.setCase(las2);
    d_echiquier.setCase(mir);
    d_echiquier.setCase(cible1);
    d_echiquier.setCase(cible2);
    d_echiquier.setCase(monstre);
    d_echiquier.setCase(mur);
}

}
