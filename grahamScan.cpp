#include "grahamScan.hpp"
#include <algorithm>
#include <stack>

std::vector<Point> grahamScan(std::vector<Point> points)
{
    if (points.size() <= 3)
    {
        return points;
    }

    // Finding leftmost point (bottom most among them if there are multiple)
    Point leftMostPoint = points[0];
    for (Point point : points)
    {
        if (point.x < leftMostPoint.x)
        {
            leftMostPoint = point;
        }
        else if (point.x == leftMostPoint.x && point.y < leftMostPoint.y)
        {
            leftMostPoint = point;
        }
    }

    // Custom Comparator which will help in sorting points with respect to angle
    auto comparator = [leftMostPoint](Point &left, Point &right) {
        if (left == leftMostPoint)
        {
            return true;
        }
        if (right == leftMostPoint)
        {
            return false;
        }
        int triangleArea = signedTriangleArea(leftMostPoint, left, right);
        if (triangleArea == 0)
        {
            return left.x < right.x;
        }
        return signedTriangleArea(leftMostPoint, left, right) < 0;
    };
    std::sort(points.begin(), points.end(), comparator);
    std::stack<Point> tempCH;
    tempCH.push(points[0]);
    tempCH.push(points[1]);

    // Graham's Scan
    for (int i = 2; i < points.size(); i++)
    {
        // Delete as many points as possible before adding current point
        while (tempCH.size() > 1)
        {
            Point prev = tempCH.top();
            tempCH.pop();
            Point prevprev = tempCH.top();
            tempCH.push(prev);
            if (signedTriangleArea(prevprev, prev, points[i]) < 0)
            {
                break;
            }
            tempCH.pop();
        }
        // Add current point
        tempCH.push(points[i]);
    }
    std::vector<Point> convex_hull;
    while (!tempCH.empty())
    {
        convex_hull.push_back(tempCH.top());
        tempCH.pop();
    }

    //Emptying the stack returns points in reverse order, reverse again to get CH in clockwise order
    reverse(convex_hull.begin(), convex_hull.end());

    return convex_hull;
}