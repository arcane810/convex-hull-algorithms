#include "utils.hpp"
#include "grahamScan.hpp"
#include "jarvisMarch.hpp"
#include "quickHull.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{

    std::ofstream fout("out.txt");
    int n;
    std::cin >> n;
    std::vector<Point> points;
    for (int i = 0; i < n; i++)
    {
        long double x, y;
        std::cin >> x >> y;
        points.push_back(Point(x, y));
    }

    std::vector<Point> ch = jarvisMarch(points);
    fout << std::setprecision(18);
    for (Point p : ch)
    {
        fout << p.x << " " << p.y << "\n";
    }

    return 0;
}