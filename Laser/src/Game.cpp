#include "Game.h"
#include <iostream>

namespace ecran{

Game::Game(int nbLigne,int nbColonne,int cote):
    d_echiquier{nbLigne,nbColonne,cote},
    d_fenetre{nbLigne*cote,nbColonne*cote+200},
    d_boutonQuit{nbLigne*cote+100,nbColonne*cote-100,50,20,"Quitter"},
    d_boutonDemarrer{nbLigne*cote+100,nbColonne*cote-200,70,20,"Demarrer"} {}

void Game::openGame(){
    d_fenetre.openWindow();
}

void Game::draw(){
    d_echiquier.draw(d_fenetre);
    d_boutonQuit.draw(d_fenetre);
    d_boutonDemarrer.draw(d_fenetre);
}

void Game::closeGame(){
    d_fenetre.closeWindow();
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
            Case* cas= (Case*)d_echiquier.plateau()[x][y];
            cas->transformation(d_echiquier);
            d_fenetre.clear();
            draw();
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
            d_echiquier.play(d_fenetre);
           }

    }
}

void Game::test(){
    Laser* las = new Laser{d_echiquier.coordVersPoint(0),d_echiquier.coordVersPoint(19),d_echiquier.taille(),ecran::Droite};
    MiroirGaucheVersBas* mur= new MiroirGaucheVersBas{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(19),d_echiquier.taille()};
    CibleHorizontale* cible= new CibleHorizontale{d_echiquier.coordVersPoint(8),d_echiquier.coordVersPoint(0),d_echiquier.taille()};
    d_echiquier.setCoordLaser({0,19});
    d_echiquier.setCase(las);
    d_echiquier.setCase(mur);
    d_echiquier.setCase(cible);
}

}
