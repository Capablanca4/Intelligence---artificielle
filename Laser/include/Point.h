#ifndef POINT_H
#define POINT_H
#include "iostream"

namespace ecran{
class Point
{
    public:
        /**Constructeurs */
        Point();
        Point(int x,int y);

        /**Accesseur*/
        const int x() const ;
        const int y() const;

        std::ostream& write(std::ostream& ost)const;

    private:
        int d_x;
        int d_y;
};
}
#endif // POINT_H
