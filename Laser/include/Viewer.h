#ifndef VIEWER_H
#define VIEWER_H

#include "Point.h"
#include "graphics.h"
#include "viewPort.hpp"

namespace ecran{

class Viewer
{
    public:
        /** Constructeur*/
        Viewer(int largeur,int hauteur,int decalageX=50,int decalageY=50);

        /**Accesseur*/
        const bool open()const;

        /** Fonction gerant la fenetre et les actions sur la fenetre*/
        void openWindow();
        void closeWindow();
        void clear();
        void waitUntilButton();
        void waitUntilMouseClicked(int& x,int& y);

        /** Fonctions gerant le ViewPort*/
        double pixelX(double x);
        double pixelY(double y);
        double reversePixelX(double x);
        double reversePixelY(double y);

        friend std::ostream& operator<<(std::ostream& ost, const Viewer& v);

        /**Fonction de test*/
        std::string typeObjet()const;

    private:
        int d_hauteur;
        int d_largeur;
        bool d_open;
        const int decalageX;
        const int decalageY;
        viewPort CoordonneesY;
        viewPort CoordonneesX;

};
}
#endif // VIEWER_H
