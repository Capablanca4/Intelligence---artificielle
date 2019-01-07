#ifndef GAME_H
#define GAME_H
#include "Echiquier.h"
#include "Viewer.h"
#include "Bouton.h"
#include "TableauDeScore.h"

namespace ecran{

struct ParamGame
{
    int nbLigne, nbColonne, cote, maxIter;
};

class Game
{
    public:
        /** Constructeur*/
        Game(int nbLigne,int nbColonne,int cote,int maxIter=200);
        Game(const ParamGame& param);
        Game(std::ifstream& ist);
        ParamGame paramJeuDeFichier(std::ifstream& ist);

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

         /** Sauvegarde*/
        void sauvegardeDansFichier(std::ostream& ost) const ;

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
        const int maxIter, d_cote;
        bool d_moving;


};

std::ostream& operator<<(std::ostream& ost, const Game& g);

}

#endif // GAME_H
