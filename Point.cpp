#include "Point.h"

namespace geom{

Point::Point():d_x{0},d_y{0} {}

Point::Point(int x,int y): d_x{x},d_y{y}{}

int Point::x() {
    return d_x;}

int Point::y() {
    return d_y;}

}
