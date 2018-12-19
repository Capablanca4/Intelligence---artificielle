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
        Case* emplacementCase(const int x,const int y);
        Case* emplacementCase(const coordLaser& coor);
        Case* emplacementCase(const Point& emplacement);
        void setCase(Case* val);

        /** accesseur de base*/
        const coordLaser coordLas() const;
        std::vector<std::vector<Case*> > plateau();
        const int nbligne() const;
        const int nbcolonne() const;
        const int taille() const;

        /** fonctions transformant les points vers les coord de l'Echiquier*/
        int pointVersCoord(int x) const;
        Point pointVersCoord(int x,int y) const;
        int coordVersPoint(int coor) const;

        /** fonctions gerant les mouvements du laser sur le plateau*/
        void play(Viewer& fenetre,GameStatut& StatutJeu,int n);
        void move(Viewer& fenetre,GameStatut& StatutJeu,int n);
        void moveLaser(Viewer& fenetre,const coordLaser& nextCoord);
        void losingByBeingOffBoard(GameStatut& StatutJeu,int n);
        void gameOver(GameStatut& StatutJeu,int n);

        void draw(Viewer& fenetre) const;
        void start(Viewer& fenetre);
        void setCoordLaser(coordLaser coord);

    private:
        int d_taille;
        coordLaser d_emplacementLaser; /** emplacement du laser sur le dessin */
        int d_nbligne;
        int d_nbcolonne;
        std::vector<std::vector<Case*> > d_plateau;
       };
}
#endif // ECHIQUIER_H
