#ifndef MIROIRGAUCHEVERSBAS_H
#define MIROIRGAUCHEVERSBAS_H
#include "Laser.h"
#include "Echiquier.h"

namespace ecran{

class MiroirGaucheVersBas :public Case
{
    public:
        MiroirGaucheVersBas(Point& centre,int cote);
        MiroirGaucheVersBas(int x,int y,int cote);
        virtual ~MiroirGaucheVersBas();
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau) const override;
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;
};
}

#endif // MIROIRGAUCHEVERSBAS_H
