#ifndef MIROIRGAUCHEVERSHAUT_H
#define MIROIRGAUCHEVERSHAUT_H
#include "Case.h"
#include "Laser.h"

namespace ecran{

class MiroirGaucheVersHaut:public Case
{
    public:
        MiroirGaucheVersHaut(Point& centre,int cote);
        MiroirGaucheVersHaut(int x,int y,int cote);
        virtual ~MiroirGaucheVersHaut();
        void draw(Viewer& fenetre);
        Laser touch(Laser& las);
};
}
#endif // MIROIRGAUCHEVERSHAUT_H