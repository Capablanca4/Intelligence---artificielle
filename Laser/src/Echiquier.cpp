#include "Echiquier.h"

namespace ecran{

Echiquier::Echiquier(int nbligne,int nbcolonne,int tailleCase):d_taille{tailleCase} { init(nbligne,nbcolonne);}

void Echiquier::init(int nbligne,int nbcolonne) {
    d_plateau.reserve(nbcolonne);
    for(int j=0;j<nbcolonne;j++ ){
        std::vector<Case*>* line;
        line->reserve(nbligne);
        for(int i=0;i<nbligne;i++){
            line->push_back(new CaseVide{i*d_taille+d_taille/2,j*d_taille+d_taille/2,d_taille}); /** <- erreur par ici */
        }
        d_plateau.push_back(line);
    }
}

Case* Echiquier::emplacementCase(const Point& emplacement) {
    return emplacementCase(emplacement.x(),emplacement.y());
}

Case* Echiquier::emplacementCase(const int x,const int y){
    return d_plateau[(y-d_taille/2)/d_taille][(x-d_taille/2)/d_taille][0]; /** pourquoi d_plateau est il de dimension 3 ?*/
}

Echiquier::~Echiquier() {}
}
