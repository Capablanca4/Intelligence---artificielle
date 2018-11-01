#ifndef MUR_H
#define MUR_H
#include "Case.h"

namespace ecran{
class Mur:public Case
{
    public:
        virtual ~Mur();
        Mur(Point& centre,int cote);
        Mur(int x,int y,int cote);
        void draw(Viewer& fenetre);
};
}
#endif // MUR_H
