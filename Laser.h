#ifndef LASER_H
#define LASER_H
#include "Case.h"

namespace ecran{

class Laser:public Case
{
    public:
        /** Constructeurs et destructeur*/
        Laser(Point& centre,int cote,TDirection direction =Droite);
        Laser(int x,int y ,int cote,TDirection direction =Droite);
        virtual ~Laser();

        /** Accesseur*/
        const TDirection direction()const;
        const bool inMove() const;

        /**modificateur de base*/
        void setDirection(TDirection direction);
        void setMoveFalse();

        /** Fonction herite de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;

        virtual std::string nameWithHashtag()const override;
        virtual std::string specificitiesCase()const override;

    private:
        TDirection d_direction;
        bool in_move;
};
}
#endif // LASER_H
