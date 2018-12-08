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

namespace ecran{

class Echiquier
{
    public:
        Echiquier(int nbligne,int nbcolonne,int tailleCase);
        void init(int nbligne,int nbcolonne);
        virtual ~Echiquier();
        Case* emplacementCase(const int x,const int y);
        Case* emplacementCase(const coordLaser& coor);
        Case* emplacementCase(const Point& emplacement);
        void setCase(Case* val);
        const coordLaser coordLas() const;
        std::vector<std::vector<Case*> > plateau();
        const int nbligne() const;
        const int nbcolonne() const;
        const int taille() const;
        int pointVersCoord(int x);
        int coordVersPoint(int coor);
        void draw(Viewer& fenetre) const;
        void move();
        void play(Viewer& fenetre);
        void start(Viewer& fenetre);
        void setCoordLaser(coordLaser coord);
    private:
        int d_taille;
        coordLaser d_emplacementLaser; /** emplacement du laser sur le dessin */
        bool in_move;
        int d_nbligne;
        int d_nbcolonne;
        std::vector<std::vector<Case*> > d_plateau;
       };
}
#endif // ECHIQUIER_H
