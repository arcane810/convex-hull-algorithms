#include "utils.hpp"
#include <cmath>
Point::Point(long double x, long double y) : y(y), x(x) {}
Point::Point() : y(0), x(0) {}
bool Point::operator==(const Point &point)
{
    return (x == point.x && y == point.y);
}

long double signedTriangleArea(Point A, Point B, Point C)
{
    return 0.5 * ((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}

long double Point::findDist(Point p, Point q) 
{ 
    return std :: abs ((y - p.y) * (q.x - p.x) - 
               (q.y - p.y) * (x - p.x));
} 
