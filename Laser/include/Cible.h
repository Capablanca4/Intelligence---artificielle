#ifndef CIBLE_H
#define CIBLE_H
#include "Case.h"
#include "Laser.h"

namespace ecran {
class Cible : public Case
{
    public:
        ~Cible();
        Cible(Point& centre,int cote);
        Cible(int x,int y,int cote);
        virtual void Touch(Laser& las) = 0;
    private:
};
}
#endif // CIBLE_H
