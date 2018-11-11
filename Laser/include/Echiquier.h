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
        Case* emplacementCase(const int x,const int y);
        Case* emplacementCase(const coordLaser& coor);
        Case* emplacementCase(const Point& emplacement);
        void setCase(int x,int y,Case& val);
        virtual ~Echiquier();
        int pointVersCoord(int x);
        int coordVersPoint(int coor);
        void draw(Viewer fenetre) const;
        void move();
        void start(Viewer fenetre);
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
