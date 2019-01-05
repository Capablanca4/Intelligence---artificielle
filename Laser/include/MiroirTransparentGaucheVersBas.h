#ifndef MIROIRTRANSPARENTGAUCHEVERSBAS_H
#define MIROIRTRANSPARENTGAUCHEVERSBAS_H
#include "Laser.h"
#include "Echiquier.h"

namespace ecran{

class MiroirTransparentGaucheVersBas:public Case
{
    public:
        /** Constructeurs et destructeur*/
        MiroirTransparentGaucheVersBas(Point& centre,int cote);
        MiroirTransparentGaucheVersBas(int x,int y,int cote);
        MiroirTransparentGaucheVersBas(Case& cas);
        virtual ~MiroirTransparentGaucheVersBas();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        //virtual std::vector<coord> posNextMoveLaser(Game& Jeu,int n) const override;
        //virtual std::ostream& name(std::ostream& ost)const override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;

    private:
};
}

#endif // MIROIRTRANSPARENTGAUCHEVERSBAS_H
