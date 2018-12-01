#include "../include/Point.h"

namespace ecran{

Point::Point():
    d_x{0},
    d_y{0} {}

Point::Point(int x,int y):
    d_x{x},
    d_y{y}{}

const int Point::x() const {
    return d_x;
}

const int Point::y() const {
    return d_y;
}

Point& Point::operator=(const Point& centre){
    this->d_x = centre.d_x;
    this->d_y = centre.d_y;
}

}
