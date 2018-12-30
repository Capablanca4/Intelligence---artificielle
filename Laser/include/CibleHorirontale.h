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
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau) const override;
};
}
#endif // CIBLEHORIRONTALE_H
