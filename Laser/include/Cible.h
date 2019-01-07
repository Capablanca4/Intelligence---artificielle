#ifndef CIBLE_H
#define CIBLE_H
#include "Case.h"

namespace ecran {
class Cible : public Case
{
    public:
        /** Constructeurs et destructeur*/
        virtual ~Cible();
        Cible(Point& centre,int cote);
        Cible(const int x,const int y,const int cote);

        /** Fonctions herites de Case et redefinit dans l objet*/
        virtual void draw(Viewer& fenetre) override;
        virtual void touch(Game& Jeu,Laser* las) override;
        virtual std::string nameWithHashtag()const override;

        /**Fonction de test*/
        virtual std::string typeObjet()const override;
};
}
#endif // CIBLE_H
