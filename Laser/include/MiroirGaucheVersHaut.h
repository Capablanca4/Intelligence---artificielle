#ifndef MIROIRGAUCHEVERSHAUT_H
#define MIROIRGAUCHEVERSHAUT_H
#include "Case.h"
#include "Laser.h"
#include "Echiquier.h"

namespace ecran{

class MiroirGaucheVersHaut:public Case
{
    public:
        /** Constructeurs et destructeur*/
        MiroirGaucheVersHaut(Point& centre,int cote);
        MiroirGaucheVersHaut(int x,int y,int cote);
        MiroirGaucheVersHaut(Case& cas);
        virtual ~MiroirGaucheVersHaut();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual coord posNextMoveLaser(Game& Jeu,int n) const override;
        void transformation(Echiquier& plateau) override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // MIROIRGAUCHEVERSHAUT_H
