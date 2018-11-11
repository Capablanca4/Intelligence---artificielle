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
        void draw(Viewer& fenetre);
    private:
        TDirection d_direction;
};
}
#endif // BLOCLASER_H
