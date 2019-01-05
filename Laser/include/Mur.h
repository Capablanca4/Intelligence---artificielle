#ifndef MUR_H
#define MUR_H
#include "Case.h"

namespace ecran{
class Mur:public Case
{
    public:
        /** Constructeurs et destructeur*/
        virtual ~Mur();
        Mur(Point& centre,int cote);
        Mur(int x,int y,int cote);

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual std::ostream& name(std::ostream& ost)const override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // MUR_H
