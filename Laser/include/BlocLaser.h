#ifndef BLOCLASER_H
#define BLOCLASER_H
#include "Case.h"
#include "Laser.h"

namespace ecran{

class BlocLaser : public Case
{
    public:
        /** Constructeurs et destructeur*/
        BlocLaser(Point& centre,int cote);
        BlocLaser(int x,int y,int cote);
        virtual ~BlocLaser();

        /** Accesseur*/
        const TDirection direction()const;

        /** Fonctions herites de Case et redefinit*/
        virtual void draw(Viewer& fenetre) override;
        virtual std::string nameWithHashtag()const override;
        virtual std::string specificitiesCase()const override;

        /** Fonctions propre au Laser*/
        Laser* shoot();
        void setDirection(TDirection direction);

        /**Fonction de test*/
        virtual std::string typeObjet()const override;
    private:
        TDirection d_direction;
};
}
#endif // BLOCLASER_H
