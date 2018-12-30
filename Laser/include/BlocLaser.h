#ifndef BLOCLASER_H
#define BLOCLASER_H
#include "Case.h"
#include "Laser.h"

namespace ecran{

class BlocLaser : public Case
{
    public:
        BlocLaser(Point& centre,int cote);
        BlocLaser(int x,int y,int cote);
        virtual ~BlocLaser();
        void setDirection(TDirection direction);
        Laser* shoot();
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau)const override;
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;
    private:
        TDirection d_direction;
};
}
#endif // BLOCLASER_H
