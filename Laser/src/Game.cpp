#include "Game.h"
#include <iostream>

namespace ecran{

Game::Game(int nbLigne,int nbColonne,int cote,int maxIter):
    d_echiquier{nbLigne,nbColonne,cote},
    d_fenetre{nbLigne*cote,nbColonne*cote+200},
    d_boutonQuit{nbLigne*cote+100,nbColonne*cote-100,70,20,"Quitter"},
    d_boutonDemarrer{nbLigne*cote+100,nbColonne*cote-200,70,20,"Demarrer"},
    d_score{nbLigne*cote+100,nbColonne*cote-300,70,20} ,

    in_move{},
    d_touch{},
    d_emplacementLaser{},
    d_nbLaser{0},
    d_iteration{0},
    maxIter{maxIter} {}

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
                d_echiquier.playAll(*this);
           }

    }
}

const bool Game::inMove(int n) const{
    return in_move[n];
}

const bool Game::touch(int n)const{
    return d_touch[n];
}

const coord Game::coordLas(int n) const{
    return d_emplacementLaser[n];
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

const int Game::nbLaser() const{
    return d_nbLaser;
}

const int Game::score() const{
    return d_score.score();
}

const int Game::maxIteration() const{
    return maxIter;
}

void Game::setInMoveFalse(int n){
    in_move[n]=false;
}

void Game::setTouchTrue(int n){
    d_touch[n]=true;
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

bool Game::winning() const{
    bool test=true;
    for(int i=0;i<in_move.size();i++){
        if(!d_touch[i]) {
            test=false;
            break;
        }
    }
    return test;
}

bool Game::finish() const{
    bool test=false;
    for(int i=0;i<in_move.size();i++){
        if (!in_move[i]) {
            if(!d_touch[i]){
                test=true;
                break;
            }
        }
    }
    bool test2=winning();
    return test||test2;
}

void Game::addLaser(coord coord){
    in_move.push_back(true);
    d_touch.push_back(false);
    d_emplacementLaser.push_back(coord);
    d_nbLaser+=1;
}

void Game::setCoordLaser(coord coord,int n){
    d_emplacementLaser[n]=coord;
}

void Game::test(){
    Laser* las1 = new Laser{d_echiquier.coordVersPoint(0),d_echiquier.coordVersPoint(19),d_echiquier.taille(),ecran::Droite};
    MiroirGaucheVersHaut* mir= new MiroirGaucheVersHaut{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(19),d_echiquier.taille()};
    Cible* cible= new Cible{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(0),d_echiquier.taille()};
    Monstre* monstre = new Monstre{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(10),d_echiquier.taille()};
    Mur* mur= new Mur{d_echiquier.coordVersPoint(1),d_echiquier.coordVersPoint(1),d_echiquier.taille()};
    Laser* las2 = new Laser{d_echiquier.coordVersPoint(19),d_echiquier.coordVersPoint(0),d_echiquier.taille(),ecran::Gauche};
    addLaser({0,19});
    addLaser({19,0});
    d_echiquier.setCase(las1);
    d_echiquier.setCase(las2);
    d_echiquier.setCase(mir);
    d_echiquier.setCase(cible);
    d_echiquier.setCase(monstre);
    d_echiquier.setCase(mur);
}

}
