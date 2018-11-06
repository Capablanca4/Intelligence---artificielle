#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <vector>
#include "BlocLaser.h"
#include "Laser.h"
#include "CaseVide.h"
#include "MiroirGaucheVersBas.h"
#include "MiroirGaucheVersHaut.h"
#include "CibleHorirontale.h"
#include "CibleVerticale.h"
#include "Mur.h"

namespace ecran{

class Echiquier
{
    public:
        Echiquier(int taille);
        void init();
        Case& readCase(int x,int y);
        void setCase(int x,int y,Case& val);
        virtual ~Echiquier();
        void draw(Viewer fenetre);
    private:
        std::vector<std::vector<Case*>> d_plateau;
};
}
#endif // ECHIQUIER_H
