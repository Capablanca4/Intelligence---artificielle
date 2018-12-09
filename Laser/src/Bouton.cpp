#include "Bouton.h"

namespace ecran{

Bouton::Bouton(const Point& centre,int largeur,int hauteur,const std::string text):
    d_centre{centre},
    d_largeur{largeur},
    d_hauteur{hauteur},
    d_texte{text} {}

Bouton::Bouton(int x,int y,int largeur,int hauteur,const std::string text):
    d_centre{x,y},
    d_largeur{largeur},
    d_hauteur{hauteur},
    d_texte{text} {}

Point Bouton::centre() const{
    return d_centre;
}

const int Bouton::largeur() const{
    return d_largeur;
}

const int Bouton::hauteur() const{
    return d_hauteur;
}

void Bouton::draw(Viewer& fenetre)const{
    outtextxy(fenetre.pixelX(d_centre.x()-d_largeur/2),
              fenetre.pixelY(d_centre.y()+d_hauteur/2),
              (char *)d_texte.c_str());

    rectangle(fenetre.pixelX(d_centre.x()-d_largeur/2),
              fenetre.pixelY(d_centre.y()-d_hauteur/2),
              fenetre.pixelX(d_centre.x()+d_largeur/2),
              fenetre.pixelY(d_centre.y()+d_hauteur/2));


}

}
