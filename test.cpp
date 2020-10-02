#include "utils.hpp"
#include "grahamScan.hpp"
#include <iostream>

int main()
{
    Point A(2, 3);
    Point B(10, 2);
    Point C(0, 1);
    Point D(5, 4);
    Point E(1, 10);

    std::vector<Point> points({A, B, C, D, E});

    std::vector<Point> ch = grahamScan(points);

    for (Point p : ch)
    {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}