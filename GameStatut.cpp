#include "GameStatut.h"

GameStatut::GameStatut(int nbLaser,int maxIter):
        in_move{},
        d_touch{},
        d_score{0},
        d_iteration{0},
        maxIter{maxIter}
    {
        for(int i =0;i<nbLaser;i++){
            in_move.push_back(true);
            d_touch.push_back(false);
        }
}

const bool GameStatut::inMove(int n) const{
    return in_move[n];
}

const bool GameStatut::touch(int n)const{
    return d_touch[n];
}

const int GameStatut::score()const{
    return d_score;
}

const int GameStatut::iteration() const{
    return d_iteration;
}

void GameStatut::setInMoveFalse(int n){
    in_move[n]=false;
}

void GameStatut::setTouchTrue(int n){
    d_touch[n]=true;
}

void GameStatut::addScore(int score){
    d_score+=score;
}

void GameStatut::increaseIter(){
    d_iteration++;
}

