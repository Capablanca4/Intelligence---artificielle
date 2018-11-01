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
        void draw(Viewer& fenetre);
};
}
#endif // CASEVIDE_H
