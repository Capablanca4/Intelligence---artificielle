#include "Laser.h"
#include <iostream>
#include "Echiquier.h"

namespace ecran{

Laser::Laser(Point& centre,int cote,TDirection direction):
        Case{centre,cote},
        d_direction{direction},
        in_move{true} {}

Laser::Laser(int x,int y ,int cote,TDirection direction):
        Case{x,y,cote},
        d_direction{direction},
        in_move{true}  {}

Laser::~Laser(){}

const TDirection Laser::direction()const{
    return d_direction;}

const bool Laser::inMove() const{
    return in_move;
}

void Laser::setDirection(TDirection direction){
    d_direction=direction;
}

void Laser::setMoveFalse(){
    in_move=false;
}

void Laser::draw(Viewer& fenetre){
    if(fenetre.open()){

        //backGround(fenetre);

        double Cote = static_cast<double>(cote());
        const double pixel = Cote/38;
        const double coordX = fenetre.pixelX(x());
        const double coordY = fenetre.pixelY(y());

        if (d_direction == Droite || d_direction == Gauche){
            setfillstyle(SOLID_FILL,RED);
            bar(
            coordX+16*pixel,
            coordY-4*pixel,
            coordX-16*pixel,
            coordY+4*pixel);

            setfillstyle(SOLID_FILL,LIGHTRED);

            bar(
            coordX+16*pixel,
            coordY-2*pixel,
            coordX-16*pixel,
            coordY+2*pixel);
            }
        else{
            setfillstyle(SOLID_FILL,RED);
            bar(
            coordX-4*pixel,
            coordY+16*pixel,
            coordX+4*pixel,
            coordY-16*pixel);

            setfillstyle(SOLID_FILL,LIGHTRED);

            bar(
            coordX-2*pixel,
            coordY+16*pixel,
            coordX+2*pixel,
            coordY-16*pixel);
            //fillellipse(fenetre.pixelX(x()),fenetre.pixelY(y()),cote()/3,cote()/8)
            }
        setfillstyle(SOLID_FILL,BLACK);
    }
}

std::string Laser::nameWithHashtag()const {
    return "#Laser";
}

std::string Laser::specificitiesCase()const{
    std::ostringstream oststr{};
    oststr << static_cast<int>(d_direction);
    return oststr.str();
}

std::string Laser::typeObjet()const{
    return "Ceci est un Laser";
}

}
