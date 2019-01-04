#ifndef CASEVIDE_H
#define CASEVIDE_H
#include "Case.h"

namespace ecran{

class CaseVide : public Case
{
    public:
        /** Constructeurs et destructeur*/
        CaseVide(Point& centre,int cote);
        CaseVide(int x,int y,int cote);
        virtual ~CaseVide();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Game& Jeu,int n) override;
        void transformation(Echiquier& plateau) override;
        virtual std::string nameWithHashtag()const override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;

};
}
#endif // CASEVIDE_H
