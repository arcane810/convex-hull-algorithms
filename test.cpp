#include "utils.hpp"
#include "grahamScan.hpp"
#include "jarvisMarch.hpp"
#include "quickHull.hpp"
#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::vector<Point> points;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.push_back(Point(x, y));
    }

    std::vector<Point> ch = quickHull(points);

    for (Point p : ch)
    {
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}