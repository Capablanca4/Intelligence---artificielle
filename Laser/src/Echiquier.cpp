#include "Echiquier.h"

namespace ecran{

Echiquier::Echiquier(int nbligne,int nbcolonne,int tailleCase):d_taille{tailleCase} { init(nbligne,nbcolonne);}

void Echiquier::init(int nbligne,int nbcolonne) {
    std::vector<std::vector<Case*>*> tableau;
    tableau.reserve(nbcolonne);
    for(int j=0;j<nbcolonne;j++ ){
        std::vector<Case*>* line;
        line->reserve(nbligne);
        for(int i=0;i<nbligne;i++){
            line[i]= new CaseVide{i*d_taille,j*d_taille,d_taille}; /** <- erreur par ici */
        }
        tableau[j]=line;
    }
    d_plateau=tableau;
}

Echiquier::~Echiquier() {}
}
