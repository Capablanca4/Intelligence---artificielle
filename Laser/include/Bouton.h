#ifndef BOUTON_H
#define BOUTON_H
#include "Point.h"
#include "Viewer.h"

namespace ecran{

class Bouton
{
    public:
        Bouton(const Point& centre,int largeur,int hauteur,const std::string text);
        Bouton(int x,int y,int largeur,int hauteur,const std::string text);
        void draw(Viewer& fenetre)const;

        Point centre() const;
        const int largeur() const;
        const int hauteur() const;

    private:
        Point d_centre;
        const int d_largeur;
        const int d_hauteur;
        std::string d_texte;
};

}
#endif // BOUTON_H
