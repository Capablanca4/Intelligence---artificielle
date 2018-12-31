#ifndef CIBLEVERTICALE_H
#define CIBLEVERTICALE_H
#include "Case.h"
#include "Echiquier.h"

namespace ecran{
class CibleVerticale : public Case
{
    public:
        /** Constructeurs et destructeur*/
        CibleVerticale(Point& centre,int cote);
        CibleVerticale(const int x,const int y,const int cote);
        virtual ~CibleVerticale();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Game& Jeu,int n) override;

        /** Finction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // CIBLEVERTICALE_H
