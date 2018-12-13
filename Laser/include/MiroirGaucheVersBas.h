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
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;
        void transformation(Echiquier& plateau) override;
};
}

#endif // MIROIRGAUCHEVERSBAS_H
