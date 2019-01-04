#ifndef MONSTRE_H
#define MONSTRE_H
#include "Case.h"

namespace ecran{
class Monstre:public Case
{
    public:
    /** Constructeurs et destructeur*/
        Monstre(Point& centre,int cote);
        Monstre(int x,int y,int cote);
        Monstre(Case& cas);
        virtual ~Monstre();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Game& Jeu,int n) override;
        void changement(Echiquier& plateau);
        virtual std::string nameWithHashtag()const override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // MONSTRE_H
