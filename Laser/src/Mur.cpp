#include "Mur.h"
#include <iostream>
#include "Echiquier.h"


namespace ecran{

Mur::~Mur() {}

Mur::Mur(Point& centre,int cote):
        Case{centre,cote} {}

Mur::Mur(int x,int y,int cote):
        Case{x,y,cote} {}

void Mur::draw(Viewer& fenetre){
    if(fenetre.open()){

        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(fenetre.pixelX(x()-cote()/2),
            fenetre.pixelY(y()+cote()/2),
            fenetre.pixelX(x()+cote()/2),
            fenetre.pixelY(y()-cote()/2));

        int petitRectangle=cote()/2.1;
        int triangleInf [6]=
            {static_cast <int> (fenetre.pixelX(x()+cote()/2)),static_cast<int> (fenetre.pixelY(y()+cote()/2)),
            static_cast <int> (fenetre.pixelX(x()+cote()/2)),static_cast <int> (fenetre.pixelY(y()-cote()/2)),
            static_cast <int> (fenetre.pixelX(x()-cote()/2)),static_cast <int> (fenetre.pixelY(y()-cote()/2))};

        setfillstyle(SOLID_FILL,BLACK);

        fillpoly(3,triangleInf);

        setfillstyle(SOLID_FILL,BROWN);

        bar(fenetre.pixelX(x()-(cote()-petitRectangle)/2),
            fenetre.pixelY(y()+(cote()-petitRectangle)/2),
            fenetre.pixelX(x()+(cote()-petitRectangle)/2),
            fenetre.pixelY(y()-(cote()-petitRectangle)/1.9));

        line(fenetre.pixelX(x()-cote()/2),
             fenetre.pixelY(y()+cote()/2),
             fenetre.pixelX(x()+cote()/2),
             fenetre.pixelY(y()-cote()/2));

        setfillstyle(SOLID_FILL,WHITE);

        rectangle(fenetre.pixelX(x()-cote()/2),
                  fenetre.pixelY(y()+cote()/2),
                  fenetre.pixelX(x()+cote()/2),
                  fenetre.pixelY(y()-cote()/2));
    }
}

std::string Mur::typeObjet()const{
    return "Ceci est un Mur";
}

}
