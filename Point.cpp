#include "Point.h"

namespace ecran{

Point::Point():d_x{0},d_y{0} {}

Point::Point(int x,int y): d_x{x},d_y{y}{}

const int Point::x() {
    return d_x;}

const int Point::y() {
    return d_y;}

}
