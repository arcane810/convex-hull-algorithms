#include "utils.hpp"
#include "grahamScan.hpp"
#include "jarvisMarch.hpp"
#include "quickHull.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>

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
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<Point> ch = grahamScan(points);

    auto end = std::chrono::high_resolution_clock::now();
    auto execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fout << std::setprecision(18);
    for (Point p : ch)
    {
        fout << p.x << " " << p.y << "\n";
    }
    long double ms = execution_time.count();
    long double s = ms / 1000000;
    std::cout << "Graham's Scan\nTime taken: \n"
              << "Microseconds: " << ms << "\n"
              << "Seconds: " << s << "\n==================\n";

    start = std::chrono::high_resolution_clock::now();

    ch = jarvisMarch(points);

    end = std::chrono::high_resolution_clock::now();
    execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fout << std::setprecision(18);
    for (Point p : ch)
    {
        fout << p.x << " " << p.y << "\n";
    }
    ms = execution_time.count();
    s = ms / 1000000;
    std::cout << "Jarvis March\nTime taken: \n"
              << "Microseconds: " << ms << "\n"
              << "Seconds: " << s << "\n==================\n";

    start = std::chrono::high_resolution_clock::now();

    ch = quickHull(points);

    end = std::chrono::high_resolution_clock::now();
    execution_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fout << std::setprecision(18);
    for (Point p : ch)
    {
        fout << p.x << " " << p.y << "\n";
    }
    ms = execution_time.count();
    s = ms / 1000000;
    std::cout << "QuickHull\nTime taken: \n"
              << "Microseconds: " << ms << "\n"
              << "Seconds: " << s << "\n";
    std::cout << "\n ConvexHullSize: " << ch.size();

    return 0;
}