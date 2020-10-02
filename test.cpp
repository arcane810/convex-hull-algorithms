#include "utils.hpp"
#include "grahamScan.hpp"
#include <iostream>

int main()
{
    Point A(0, 0);
    Point B(0, 1);
    Point C(1, 1);
    Point D(1, 0);
    Point E(0.5, 0.5);

    std::vector<Point> points({A, B, C, D, E});

    std::vector<Point> ch = grahamScan(points);

    for (Point p : ch)
    {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}