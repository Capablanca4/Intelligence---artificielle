#ifndef MIROIRGAUCHEVERSHAUT_H
#define MIROIRGAUCHEVERSHAUT_H
#include "Case.h"
#include "Laser.h"
#include "Echiquier.h"

namespace ecran{

class MiroirGaucheVersHaut:public Case
{
    public:
        MiroirGaucheVersHaut(Point& centre,int cote);
        MiroirGaucheVersHaut(int x,int y,int cote);
        virtual ~MiroirGaucheVersHaut();
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau) const override;
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;
};
}
#endif // MIROIRGAUCHEVERSHAUT_H
