#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <vector>
#include "BlocLaser.h"
#include "Laser.h"
#include "CaseVide.h"
#include "MiroirGaucheVersBas.h"
#include "MiroirGaucheVersHaut.h"
#include "MiroirTransparentGaucheVersBas.h"
#include "MiroirTransparentGaucheVersHaut.h"
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
        Case*& emplacementCase(Case* cas) ;
        void setCase(Case* val);

        /** accesseur de base*/
        const int nbLigne() const;
        const int nbColonne() const;
        const int taille() const;

        /** fonctions transformant les points vers les coord de l'Echiquier*/
        int pointVersCoord(int x) const;
        coord pointVersCoord(int x,int y) const;
        coord pointVersCoord(Case* cas) const;
        coord pointVersCoord(const Point& centre) const;
        int coordVersPoint(int coor) const;
        Point coordVersPoint(coord coor)const;

        /** fonctions gerant les mouvements du laser sur le plateau*/
        void play(Game& Jeu);
        void destinationMove(Game& Jeu,int n,std::vector<Laser*>& nextLas);
        void losingByBeingOffBoard(Game& Jeu);
        void movable(Game& Jeu,const std::vector<Laser*>& nextLas);

        void draw(Viewer& fenetre) const;

        friend std::ostream& operator<<(std::ostream& ost, const Echiquier& plateau);

    private:
        int d_taille;
        int d_nbligne;
        int d_nbcolonne;
        std::vector<std::vector<Case*> > d_plateau;
       };

std::ostream& operator<<(std::ostream& ost, const std::vector<Case*>& listeCase);
std::ostream& operator<<(std::ostream& ost, const std::vector<std::vector<Case*> >& plateau);

}
#endif // ECHIQUIER_H
