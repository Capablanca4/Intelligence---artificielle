#ifndef MIROIRTRANSPARENTGAUCHEVERSHAUT_H
#define MIROIRTRANSPARENTGAUCHEVERSHAUT_H

#include "Laser.h"
#include "Echiquier.h"

namespace ecran{

class MiroirTransparentGaucheVersHaut:public Case
{
    public:
        /** Constructeurs et destructeur*/
        MiroirTransparentGaucheVersHaut(Point& centre,int cote);
        MiroirTransparentGaucheVersHaut(int x,int y,int cote);
        MiroirTransparentGaucheVersHaut(Case& cas);
        virtual ~MiroirTransparentGaucheVersHaut();

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual void nextLaser(Game& Jeu,const TDirection& direcLas,std::vector<Laser*>& nextLas) const override;
        virtual std::string nameWithHashtag()const override;

        /** Fonction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // MIROIRTRANSPARENTGAUCHEVERSHAUT_H
