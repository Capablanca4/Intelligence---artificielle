#ifndef MUR_H
#define MUR_H
#include "Case.h"

namespace ecran{
class Mur:public Case
{
    public:
        virtual ~Mur();
        Mur(Point& centre,int cote);
        Mur(int x,int y,int cote);
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau) const override;
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;
};
}
#endif // MUR_H
