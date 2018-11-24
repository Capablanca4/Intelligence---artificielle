#ifndef CASE_H
#define CASE_H
#include "Point.h"
#include "Viewer.h"

namespace ecran{

enum TDirection{Droite,Gauche,Haut,Bas};

class Case: public Point
{
    public:
        virtual ~Case();
        Case(Point& centre,int cote);
        Case(int x,int y,int cote);
        const Point centre();
        void changerCentre(const Point& centre);
        const int cote();
        void changerCote(const int cote);
        virtual void draw(Viewer& fenetre)=0;
    private:
        int d_cote; /** largeur du carre definissant la case*/

};
}
#endif // CASE_H
