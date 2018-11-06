#ifndef CIBLE_H
#define CIBLE_H
#include "Case.h"

namespace ecran {
class Cible : public Case
{
    public:
        ~Cible();
        Cible(Point& centre,int cote);
        Cible(int x,int y,int cote);
        const bool isTouched();
    private:
        bool Touched;
};
}
#endif // CIBLE_H
