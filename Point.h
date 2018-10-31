#ifndef POINT_H
#define POINT_H

namespace geom{
class Point
{
    public:
        Point();
        Point(int x,int y);
        int x();
        int y();
    private:
        int d_x;
        int d_y;
};
}
#endif // POINT_H
