#ifndef BOUTON_H
#define BOUTON_H
#include "Point.h"
#include "Viewer.h"

namespace ecran{

class Bouton
{
    public:
        /** Constructeurs*/
        Bouton(const Point& centre,int largeur,int hauteur,const std::string texte);
        Bouton(int x,int y,int largeur,int hauteur,const std::string texte);

        /** Accesseur de base*/
        Point centre() const;
        const int largeur() const;
        const int hauteur() const;
        const std::string texte() const;

        /** Dessine l'objet sur la fenetre*/
        void draw(Viewer& fenetre)const;

    private:
        Point d_centre;
        const int d_largeur;
        const int d_hauteur;
        std::string d_texte;
};

}
#endif // BOUTON_H
