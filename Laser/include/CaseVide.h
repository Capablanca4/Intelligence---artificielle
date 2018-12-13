#ifndef CASEVIDE_H
#define CASEVIDE_H
#include "Case.h"

namespace ecran{

class CaseVide : public Case
{
    public:
        CaseVide(Point& centre,int cote);
        CaseVide(int x,int y,int cote);
        virtual ~CaseVide();
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau) const override;
        void transformation(Echiquier& plateau) override;
};
}
#endif // CASEVIDE_H
