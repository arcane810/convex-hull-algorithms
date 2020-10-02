#include "utils.hpp"

Point::Point(long double x, long double y) : y(y), x(x) {}
bool Point::operator==(const Point &point)
{
    return (x == point.x && y == point.y);
}

long double signedTriangleArea(Point A, Point B, Point C)
{
    return 0.5 * ((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}