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
        virtual ~Monstre();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual bool touch(Echiquier& plateau,GameStatut& StatutJeu,int n) override;
        void changement(Echiquier& plateau);
};
}
#endif // MONSTRE_H
