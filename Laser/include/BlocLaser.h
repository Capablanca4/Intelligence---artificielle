#ifndef BLOCLASER_H
#define BLOCLASER_H
#include "Case.h"
#include "Laser.h"

namespace ecran{

class BlocLaser : public Case
{
    public:
        /** Constructeurs et destructeur*/
        BlocLaser(Point& centre,int cote);
        BlocLaser(int x,int y,int cote);
        virtual ~BlocLaser();

        /** Fonctions herites de Case et redefinit*/
        virtual void draw(Viewer& fenetre) override;
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;

        /** Fonctions propre au Laser*/
        Laser* shoot();
        void setDirection(TDirection direction);

    private:
        TDirection d_direction;
};
}
#endif // BLOCLASER_H
