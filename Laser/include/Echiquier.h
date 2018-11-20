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

struct coordLaser {
    int x,y; };

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
        const coordLaser coordLas();
        std::vector<std::vector<Case*> > plateau();
        const int nbligne();
        const int nbcolonne();
        int pointVersCoord(int x);
        int coordVersPoint(int coor);
        void draw(Viewer fenetre) const;
        void move();
        void start(Viewer fenetre);
        void setCoordLaser(coordLaser coord);
    private:
        bool in_move;
        std::vector<std::vector<Case*> > d_plateau;
        int d_taille;
        int d_nbligne;
        int d_nbcolonne;
        coordLaser d_emplacementLaser; /** emplacement du laser sur le dessin */
};
}
#endif // ECHIQUIER_H
