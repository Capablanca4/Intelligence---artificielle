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
        void draw(Viewer& fenetre);
        bool touch(Echiquier& plateau) const;
};
}

#endif // MIROIRGAUCHEVERSBAS_H
