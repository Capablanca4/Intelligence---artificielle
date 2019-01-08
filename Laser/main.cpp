#include <fstream>
#include "Game.h"

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

    std::string nomFichier="sauvegarde.txt";
    std::ifstream ifs{nomFichier};
    ecran::Game jeu{ifs};
    ifs.close();

    /*
    std::ofstream of{nomFichier};
    of << jeu;
    */

    jeu.openGame();
    jeu.draw();
    jeu.waitUntilMouseClicked();

    return 0;
}

