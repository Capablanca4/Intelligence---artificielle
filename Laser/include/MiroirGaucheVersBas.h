#ifndef MIROIRGAUCHEVERSBAS_H
#define MIROIRGAUCHEVERSBAS_H
#include "Laser.h"
#include "Echiquier.h"

namespace ecran{

class MiroirGaucheVersBas :public Case
{
    public:
        /** Constructeurs et destructeur*/
        MiroirGaucheVersBas(Point& centre,int cote);
        MiroirGaucheVersBas(int x,int y,int cote);
        MiroirGaucheVersBas(Case& cas);
        virtual ~MiroirGaucheVersBas();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual coord posNextMoveLaser(Echiquier& plateau) const override;
        void transformation(Echiquier& plateau) override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
};
}

#endif // MIROIRGAUCHEVERSBAS_H
