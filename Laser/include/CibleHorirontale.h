#ifndef CIBLEHORIRONTALE_H
#define CIBLEHORIRONTALE_H
#include "Case.h"
#include "Echiquier.h"

namespace ecran{
class CibleHorizontale : public Case
{
    public:
        /**Constructeurs et destructeur*/
        CibleHorizontale(Point& centre,int cote);
        CibleHorizontale(const int x,const int y,const int cote);
        virtual ~CibleHorizontale();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual void touch(Game& Jeu,Laser* las) override;
        virtual std::ostream& name(std::ostream& ost)const override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;

};
}
#endif // CIBLEHORIRONTALE_H
