#ifndef CIBLEHORIRONTALE_H
#define CIBLEHORIRONTALE_H
#include "Cible.h"
#include "Echiquier.h"

namespace ecran{
class CibleHorizontale : public Cible
{
    public:
        CibleHorizontale(const Cible& cib);
        CibleHorizontale(const int x,const int y,const int cote);
        virtual ~CibleHorizontale();
        void draw(Viewer& fenetre);
        bool touch(Echiquier& plateau) const;
};
}
#endif // CIBLEHORIRONTALE_H
