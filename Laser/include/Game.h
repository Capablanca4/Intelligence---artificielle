#ifndef GAME_H
#define GAME_H
#include "Echiquier.h"
#include "Viewer.h"
#include "Bouton.h"
#include "TableauDeScore.h"

namespace ecran{

class Game
{
    public:
        /** Constructeur*/
        Game(int nbLigne,int nbColonne,int cote,int maxIter=200);

        /**Gere la fenetre*/
        void openGame();
        void closeGame();
        void waitUntilMouseCkicked();
        void draw();

        /** accesseur de base */
        const std::vector<Laser*> listLas() const;
        Laser* las(int n) const;
        const int iteration() const;
        const int score() const; /** Pour les tests*/
        const int nbLaser() const;
        const int maxIteration() const;
        const bool moving() const;
        Echiquier& plateau();
        Viewer& fenetre();

        /**modificateur de base*/
        void addLaser(Laser* las);
        void clearLaser();
        void addScore(int score);
        void increaseIter();
        void setMovingFalse();

        bool notFinish() const;

        /** Juste une fonction generant quelque objet sur d_echiquier pour réaliser des tests*/
        void test();
    private:
        Echiquier d_echiquier;
        Viewer d_fenetre;
        Bouton d_boutonQuit;    /** InfoConteneur*/
        Bouton d_boutonDemarrer;/** InfoConteneur*/
        TableauDeScore d_score; /** InfoConteneur*/

        std::vector<Laser*> listLaser; /** emplacement du(des) Laser(s) sur le dessin */
        int d_iteration;
        const int maxIter;
        bool d_moving;


};

}

#endif // GAME_H
