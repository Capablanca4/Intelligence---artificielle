#ifndef LASER_H
#define LASER_H
#include "Case.h"

namespace ecran{

class Laser:public Case
{
    public:
        /** Constructeurs et destructeur*/
        Laser(Point& centre,int cote,const TDirection& direction =Gauche);
        Laser(int x,int y ,int cote,const TDirection& direction =Gauche);
        virtual ~Laser();

        /** Accesseur*/
        const TDirection direction()const;

        /**modificateur de base*/
        void setDirection(TDirection direction);

        /** Fonction herite de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
    private:
        TDirection d_direction;
};
}
#endif // LASER_H
