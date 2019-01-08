#include "TableauDeScore.h"
#include <string>
#include <iostream>

namespace ecran{

TableauDeScore::TableauDeScore(const Point& centre,int largeur,int hauteur):
    d_centre{centre},
    d_largeur{largeur},
    d_hauteur{hauteur},
    d_score{0} {}

TableauDeScore::TableauDeScore(int x,int y,int largeur,int hauteur):
    d_centre{x,y},
    d_largeur{largeur},
    d_hauteur{hauteur},
    d_score{0} {}

Point TableauDeScore::centre() const{
    return d_centre;
}

const int TableauDeScore::largeur() const{
    return d_largeur;
}

const int TableauDeScore::hauteur() const{
    return d_hauteur;
}

const int TableauDeScore::score()const{
    return d_score;
}

void TableauDeScore::addScore(int add){
    d_score+=add;
}

void TableauDeScore::draw(Viewer& fenetre)const{
    if(fenetre.open()){
        std::string str;
        std::ostringstream oststr(str);
        oststr.fill('0');
        oststr.width(8);
        oststr << std::right << d_score ;
        str=oststr.str();
        char* car= (char *)str.c_str();
        outtextxy(fenetre.pixelX(d_centre.x()-d_largeur/2),
                  fenetre.pixelY(d_centre.y()+d_hauteur/2),
                  car);

        outtextxy(fenetre.pixelX(d_centre.x()-d_largeur/2),
                  fenetre.pixelY(d_centre.y()+2*d_hauteur),
                  "Score");

        /*rectangle(fenetre.pixelX(d_centre.x()-d_largeur/2),
                  fenetre.pixelY(d_centre.y()-d_hauteur/2),
                  fenetre.pixelX(d_centre.x()+d_largeur/2),
                  fenetre.pixelY(d_centre.y()+d_hauteur/2));*/
    }

}

void TableauDeScore::clear(Viewer& fenetre)const{
    if(fenetre.open()){
        setfillstyle(SOLID_FILL,BLACK);
        bar(fenetre.pixelX(d_centre.x()-d_largeur/2),
            fenetre.pixelY(d_centre.y()-d_hauteur/2),
            fenetre.pixelX(d_centre.x()+d_largeur/2),
            fenetre.pixelY(d_centre.y()+d_hauteur/2));
    }
}

}
