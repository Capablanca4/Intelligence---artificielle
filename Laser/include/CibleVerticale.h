#ifndef CIBLEVERTICALE_H
#define CIBLEVERTICALE_H
#include "Cible.h"
#include "Echiquier.h"

namespace ecran{
class CibleVerticale : public Cible
{
    public:
        CibleVerticale(const Cible& cib);
        CibleVerticale(const int x,const int y,const int cote);
        virtual ~CibleVerticale();
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau) const override;
        virtual coordLaser posNextMoveLaser(Echiquier& plateau) const override;
};
}
#endif // CIBLEVERTICALE_H
