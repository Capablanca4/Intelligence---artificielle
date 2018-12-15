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
        virtual bool touch(Echiquier& plateau,GameStatut& StatutJeu,int n) override;
};
}
#endif // CIBLEHORIRONTALE_H
