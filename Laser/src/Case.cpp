#include "Case.h"
#include "Game.h"

namespace ecran{

Case::~Case(){}

Case::Case(Point& centre,int cote):Point{centre},d_cote{cote}{}

Case::Case(int x,int y,int cote):Point{x,y},d_cote{cote}{}

Case::Case(Case& cas):Point{cas.centre()},d_cote{cas.cote()}{}

const Point Case::centre()const {
    return Point{x(),y()};}

void Case::changerCentre(const Point& centre){
    Point& LeCentre = *this;
    LeCentre = centre;}

const int Case::cote()const{
    return d_cote;}

bool Case::touch(Game& Jeu,int n) {
    return false ;
}

coord Case::posNextMoveLaser(Game& Jeu,int n) const{
    coord ret{Jeu.plateau().pointVersCoord(x()),
                   Jeu.plateau().pointVersCoord(y())};
    return ret;
}

void Case::clearCase(Viewer& fenetre){
    if(fenetre.open()){
        setfillstyle(SOLID_FILL,BLACK);
        bar(
            fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()+cote()/2),
            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()-cote()/2));
    }
}

void Case::drawTab(Viewer& fenetre, int *tab, int taille)const
{
    int Corr = 3;

    double Cote=static_cast<double>(cote());
    double pixel = Cote/(taille+Corr);
    const double coordX = fenetre.pixelX(x())-(pixel*(taille/2));
    const double coordY = fenetre.pixelY(y())-(pixel*(taille/2));
    double x = coordX;
    double y = coordY;

    int I=0;
    for(int i=0; i<taille; i++)
    {
        I = i*taille;
        for (int j=0; j<taille; j++)
        {
            if (tab[I+j] != 0)
            {
                setfillstyle(SOLID_FILL,tab[I+j]);
                bar (x, y, x + pixel, y + pixel);
            }
            x += pixel;
        }

        x = coordX;
        y += pixel;
    }
    setcolor(WHITE);
}

void Case::backGround(Viewer& fenetre)const
{
            line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()-cote()*1/4),
             fenetre.pixelY(y()+cote()/2));

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()*1/4)); /** coin haut gauche */

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()+cote()*1/4),
             fenetre.pixelY(y()-cote()/2));

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()*1/4)); /** coin bas droite */

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()+cote()*1/4),
             fenetre.pixelY(y()+cote()/2));

        line(fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()+cote()*1/4)); /** coin */

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()-cote()*1/4),
             fenetre.pixelY(y()-cote()/2));

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()-cote()/2),
             fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()-cote()*1/4));/**coin */
}

void Case::transformation(Echiquier& plateau){
}

std::string Case::typeObjet()const{
    return "Ceci est une Case";
}


}
