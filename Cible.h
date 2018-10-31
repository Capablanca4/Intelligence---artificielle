#ifndef CIBLE_H
#define CIBLE_H
#include "Case.h"
#include "Viewer.h"

namespace ecran{
class Cible : public Case
{
    public:
        Cible(Point& centre);
        Cible(int x,int y);
        const bool isTouched();
        void draw(Viewer& fenetre);
    private:
        bool Touched;
};
}
#endif // CIBLE_H
