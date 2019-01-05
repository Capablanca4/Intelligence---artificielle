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
        virtual void touch(Game& Jeu,Laser* las) override;
        virtual std::ostream& name(std::ostream& ost)const override;

        void changement(Echiquier& plateau);

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // MONSTRE_H
