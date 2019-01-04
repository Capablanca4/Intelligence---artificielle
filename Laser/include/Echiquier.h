#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <vector>
#include "BlocLaser.h"
#include "Laser.h"
#include "CaseVide.h"
#include "MiroirGaucheVersBas.h"
#include "MiroirGaucheVersHaut.h"
#include "CibleHorirontale.h"
#include "CibleVerticale.h"
#include "Mur.h"
#include "Cible.h"
#include "Monstre.h"

namespace ecran{

class Echiquier
{
    public:
        /** construction de l'echiquier*/
        Echiquier(int nbligne,int nbcolonne,int tailleCase);
        virtual ~Echiquier();
        void init(int nbligne,int nbcolonne);

        /** Changement d'objet de l'Echiquier*/
        Case*& emplacementCase(const int x,const int y);
        Case*& emplacementCase(const coord& coor);
        Case*& emplacementCase(const Point& emplacement);
        Case*& emplacementCase(const Case*& cas) ;
        void setCase(Case* val);

        /** accesseur de base*/
        const int nbligne() const;
        const int nbcolonne() const;
        const int taille() const;

        /** fonctions transformant les points vers les coord de l'Echiquier*/
        int pointVersCoord(int x) const;
        coord pointVersCoord(int x,int y) const;
        coord pointVersCoord(Case* cas) const;
        int coordVersPoint(int coor) const;

        /** fonctions gerant les mouvements du laser sur le plateau*/
        void playAll(Game& Jeu);
        void play(Game& Jeu,int n);
        void move(Game& Jeu,int n);
        void moveLaser(Game& Jeu,const coord& nextCoord,int n);
        void losingByBeingOffBoard(Game& Jeu,int n);
        void gameOver(Game& Jeu,int n);

        void draw(Viewer& fenetre) const;
        void start(Game& Jeu,int n);

    private:
        int d_taille;
        int d_nbligne;
        int d_nbcolonne;
        std::vector<std::vector<Case*> > d_plateau;
       };

std::ostream& operator<<(std::ostream& ost,Echiquier& plateau);

}
#endif // ECHIQUIER_H
