#ifndef TABLEAUDESCORE_H
#define TABLEAUDESCORE_H
#include "Viewer.h"
#include "Point.h"
#include "GameStatut.h"

namespace ecran{

class TableauDeScore
{
    public:
        /** Constructeurs*/
        TableauDeScore(const Point& centre,int largeur,int hauteur);
        TableauDeScore(int x,int y,int largeur,int hauteur);

        /** Accesseur de base*/
        Point centre() const;
        const int largeur() const;
        const int hauteur() const;

        /** Dessine l'objet sur la fenetre*/
        void draw(Viewer& fenetre)const;
        void clear(Viewer& fenetre)const;

        void addScore(int add,Viewer& fenetre);
    private:
        Point d_centre;
        int score;
        const int d_largeur;
        const int d_hauteur;
};
}

#endif // TABLEAUDESCORE_H
