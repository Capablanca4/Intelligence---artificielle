#include "Point.h"

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

void Point::writePoint(std::ostream& ost)const
{
    ost<<d_x<<" "<<d_y;
}

std::ostream& operator<<(std::ostream& ost, const Point& p)
{
    p.writePoint(ost);
    return ost;
}

}
