#include "TableauDeScore.h"
#include <string>

namespace ecran{

TableauDeScore::TableauDeScore(const Point& centre,int largeur,int hauteur):
    d_centre{centre},
    d_largeur{largeur},
    d_hauteur{hauteur},
    score{0} {}

TableauDeScore::TableauDeScore(int x,int y,int largeur,int hauteur):
    d_centre{x,y},
    d_largeur{largeur},
    d_hauteur{hauteur},
    score{0} {}

Point TableauDeScore::centre() const{
    return d_centre;
}

const int TableauDeScore::largeur() const{
    return d_largeur;
}

const int TableauDeScore::hauteur() const{
    return d_hauteur;
}

void TableauDeScore::addScore(int add,Viewer& fenetre){
    score+=add;
    clear(fenetre);
    draw(fenetre);
}

void TableauDeScore::draw(Viewer& fenetre)const{
    std::string str;
    std::ostringstream oststr(str);
    oststr.fill('0');
    oststr.width(8);
    oststr << std::right << score;
    char* car= (char *)str.c_str();

    outtextxy(fenetre.pixelX(d_centre.x()-d_largeur/2),
              fenetre.pixelY(d_centre.y()+d_hauteur/2),
              car);

    rectangle(fenetre.pixelX(d_centre.x()-d_largeur/2),
              fenetre.pixelY(d_centre.y()-d_hauteur/2),
              fenetre.pixelX(d_centre.x()+d_largeur/2),
              fenetre.pixelY(d_centre.y()+d_hauteur/2));

}

void TableauDeScore::clear(Viewer& fenetre)const{
    setfillstyle(SOLID_FILL,BLACK);
    bar(
        fenetre.pixelX(d_centre.x()-d_largeur/2),
        fenetre.pixelY(d_centre.y()-d_hauteur/2),
        fenetre.pixelX(d_centre.x()+d_largeur/2),
        fenetre.pixelY(d_centre.y()+d_hauteur/2));
}

}
