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
        const bool inMove(int n) const;
        const bool touch(int n)const;
        const coord coordLas(int n) const;
        const int iteration() const;
        const int score() const; /** Pour les tests*/
        const int nbLaser() const;
        Echiquier& plateau();
        Viewer& fenetre();

        /**modificateur de base*/
        void setInMoveFalse(int n);
        void setTouchTrue(int n);
        void setCoordLaser(coord coord,int n);
        void addScore(int score);
        void increaseIter();

        bool finish() const;
        void addLaser(coord coord);

        /** Juste une fonction generant quelque objet sur d_echiquier pour réaliser des tests*/
        void test();
    private:
        Echiquier d_echiquier;
        Viewer d_fenetre;
        std::vector<bool> in_move;
        std::vector<bool> d_touch;
        std::vector<coord> d_emplacementLaser; /** emplacement du(des) Laser(s) sur le dessin */
        int d_nbLaser;
        int d_iteration;
        const int maxIter;

        Bouton d_boutonQuit;    /** InfoConteneur*/
        Bouton d_boutonDemarrer;/** InfoConteneur*/
        TableauDeScore d_score; /** InfoConteneur*/
};

}

#endif // GAME_H
