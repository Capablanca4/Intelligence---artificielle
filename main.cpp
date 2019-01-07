#include <iostream>
#include "Viewer.h"
#include "Echiquier.h"
#include "Game.h"
#include <fstream>



int main()
{
    /*
    const int nbligne=20;
    const int nbcolonne=20;
    const int cote=40;
    const int maxIter=200;
    ecran::Game jeu{nbligne,nbcolonne,cote,maxIter};
    jeu.test();
    */
    std::ifstream ifst{"sauvegarde.txt"};
    ecran::Game jeu{ifst};
    jeu.openGame();
    /*
    ifst.close();
    std::ofstream ofst{"sauvegarde.txt"};
    ofst << jeu;
    */
    jeu.draw();
    jeu.waitUntilMouseCkicked();

    return 0;
}

