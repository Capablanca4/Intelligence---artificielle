#include <fstream>
#include "Game.h"

int main()
{
    const int nbligne=20;
    const int nbcolonne=20;
    const int cote=40;
    const int maxIter=200;
    std::string nomFichier="sauvegarde.txt";
    /*ecran::Game jeu{nbligne,nbcolonne,cote,maxIter};*/
    std::ifstream ifs{nomFichier};
    ecran::Game jeu{ifs};
    jeu.openGame();
    /*jeu.test();
    std::ofstream of{nomFichier};
    of << jeu;*/
    jeu.draw();
    jeu.waitUntilMouseCkicked();
    return 0;
}

