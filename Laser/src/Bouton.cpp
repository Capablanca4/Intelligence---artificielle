#include "Bouton.h"

namespace ecran{

Bouton::Bouton(const Point& centre,int largeur,int hauteur,const std::string texte):
    d_centre{centre},
    d_largeur{largeur},
    d_hauteur{hauteur},
    d_texte{texte} {}

Bouton::Bouton(int x,int y,int largeur,int hauteur,const std::string texte):
    d_centre{x,y},
    d_largeur{largeur},
    d_hauteur{hauteur},
    d_texte{texte} {}

Point Bouton::centre() const{
    return d_centre;
}

const int Bouton::largeur() const{
    return d_largeur;
}

const int Bouton::hauteur() const{
    return d_hauteur;
}

const std::string Bouton::texte() const{
    return d_texte;
}

void Bouton::draw(Viewer& fenetre)const{
    if(fenetre.open()){

        outtextxy(fenetre.pixelX(d_centre.x()-d_largeur/2),
                  fenetre.pixelY(d_centre.y()+d_hauteur/2),
                  (char *)d_texte.c_str());

        rectangle(fenetre.pixelX(d_centre.x()-d_largeur/2),
                  fenetre.pixelY(d_centre.y()-d_hauteur/2),
                  fenetre.pixelX(d_centre.x()+d_largeur/2),
                  fenetre.pixelY(d_centre.y()+d_hauteur/2));

    }
}

std::ostream& operator<<(std::ostream& ost, const Bouton& b)
{
    ost << b.centre() << std::endl;
    ost << b.largeur() << std::endl;
    ost << b.hauteur() << std::endl;
    ost << b.texte() << std::endl;

    return ost;
}


}
