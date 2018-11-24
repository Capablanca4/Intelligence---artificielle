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
        void move();
        void draw(Viewer& fenetre);
        const bool enMouvement();
    private:
        TDirection d_direction;
        bool d_inMove;
};
}
#endif // LASER_H
