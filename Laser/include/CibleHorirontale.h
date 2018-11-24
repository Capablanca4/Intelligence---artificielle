#ifndef CIBLEHORIRONTALE_H
#define CIBLEHORIRONTALE_H
#include "Cible.h"

namespace ecran{
class CibleHorizontale : public Cible
{
    public:
        CibleHorizontale(const Cible& cib);
        CibleHorizontale(const int x,const int y,const int cote);
        virtual ~CibleHorizontale();
        void draw(Viewer& fenetre);
        void touch(Laser& las);
};
}
#endif // CIBLEHORIRONTALE_H
