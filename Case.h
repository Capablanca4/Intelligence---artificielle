#ifndef CASE_H
#define CASE_H
#include "Point.h"

namespace geom{
class Case
{
    public:
        Case(Point& centre);
        Point centre();
        changerCentre(Point& centre);
    private:
        Point d_centre;

};
}
#endif // CASE_H
