#include "Case.h"

namespace ecran{

Case::~Case(){}

Case::Case(Point& centre):Point{centre}{}

Case::Case(int x,int y):Point{x,y}{}

const Point Case::centre() {
    return Point{x(),y()};}

void Case::changerCentre(Point& centre){
    (Point)(*this)=centre;}

const int Case::cote(){
    return d_cote;}

void Case::changerCote(const int cote){
    d_cote=cote;}

}
