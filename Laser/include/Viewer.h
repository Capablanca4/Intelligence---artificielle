#ifndef VIEWER_H
#define VIEWER_H

#include "Point.h"
#include "graphics.h"
#include "viewPort.hpp"

namespace ecran{

class Viewer
{
    public:
        Viewer(int largeur,int hauteur);
        void openWindow();
        void closeWindow();
        void waitUntilButton();
        void clear();
        Point pixel(Point& P);
        double pixelX(double x);
        double pixelY(double y);
        void waitUntilMouseCkicked(int& x,int& y);
        double reversePixelX(double x);
        double reversePixelY(double y);
    private:
        int d_hauteur;
        int d_largeur;
        bool d_open;
        const int decalageX=20;
        const int decalageY=20;
        viewPort CoordonneesY/*{0, 1000, 980, 20}*/;
        viewPort CoordonneesX/*{0, 1000, 20, 980}*/;

};
}
#endif // VIEWER_H
