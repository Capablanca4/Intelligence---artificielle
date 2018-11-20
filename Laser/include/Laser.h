#ifndef LASER_H
#define LASER_H
#include "Case.h"

namespace ecran{

class Laser:public Case
{
    public:
        Laser(Point& centre,int cote,const TDirection& direction =Gauche);
        Laser(int x,int y ,int cote,const TDirection& direction =Gauche);
        virtual ~Laser();
        void setDirection(TDirection direction);
        TDirection direction();
        void draw(Viewer& fenetre);
        bool touch(Echiquier& plateau) const ;
    private:
        TDirection d_direction;
};
}
#endif // LASER_H
