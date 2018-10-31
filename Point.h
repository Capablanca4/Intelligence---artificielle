#ifndef POINT_H
#define POINT_H

namespace ecran{
class Point
{
    public:
        Point();
        Point(int x,int y);
        const int x();
        const int y();
    private:
        int d_x;
        int d_y;
};
}
#endif // POINT_H
