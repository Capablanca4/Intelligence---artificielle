#ifndef CASE_H
#define CASE_H
#include "Point.h"

namespace ecran{
class Case: public Point
{
    public:
        virtual ~Case();
        Case(Point& centre);
        Case(int x,int y);
        const Point centre();
        void changerCentre(Point& centre);
        const int cote();
        void changerCote(const int cote);
        void virtual draw()=0;
    private:
        int d_cote; /** largeur du carre definissant la case*/

};
}
#endif // CASE_H
