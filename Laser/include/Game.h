#ifndef GAME_H
#define GAME_H
#include "Echiquier.h"
#include "Viewer.h"
#include "Bouton.h"

namespace ecran{

class Game
{
    public:
        Game(int nbLigne,int nbColonne,int cote);
        void openGame();
        void closeGame();
        void waitUntilMouseCkicked();
        void draw();
        void test();
    private:
        Echiquier d_echiquier;
        Viewer d_fenetre;
        Bouton d_boutonQuit;
        Bouton d_boutonDemarrer;
};

}

#endif // GAME_H
