#ifndef VIEWER_H
#define VIEWER_H

namespace ecran{
class Viewer
{
    public:
        Viewer(int largeur,int hauteur);
        void openWindow();
        void closeWindow();
        void waitUntilButton();
        void clear();
    private:
        int d_hauteur;
        int d_largeur;
        bool d_open;
};
}
#endif // VIEWER_H
