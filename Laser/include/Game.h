#ifndef GAME_H
#define GAME_H
#include "Echiquier.h"
#include "Viewer.h"
#include "Bouton.h"
#include "GameStatut.h"

namespace ecran{

class Game
{
    public:
        /** Constructeur*/
        Game(int nbLigne,int nbColonne,int cote,int nbLaser,int maxIter=200);

        /**Gere la fenetre*/
        void openGame();
        void closeGame();
        void waitUntilMouseCkicked();
        void draw();

        /** Juste une fonction generant quelque objet sur d_echiquier pour réaliser des tests*/
        void test();
    private:
        Echiquier d_echiquier;
        Viewer d_fenetre;
        GameStatut StatutJeu;
        Bouton d_boutonQuit;
        Bouton d_boutonDemarrer;
};

}

#endif // GAME_H
