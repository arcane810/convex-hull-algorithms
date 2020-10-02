#pragma once

class Point
{
public:
    long double x, y;
    Point(long double x, long double y);
    Point();
    bool operator==(const Point &point);
};

long double signedTriangleArea(Point A, Point B, Point C);