#include "grahamScan.hpp"
#include <algorithm>
#include <stack>

std::vector<Point> grahamScan(std::vector<Point> points)
{
    if (points.size() <= 3)
    {
        return points;
    }
    std::vector<Point> convex_hull;
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

    for (int i = 2; i < points.size(); i++)
    {
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
        tempCH.push(points[i]);
    }

    while (!tempCH.empty())
    {
        convex_hull.push_back(tempCH.top());
        tempCH.pop();
    }
    reverse(convex_hull.begin(), convex_hull.end());

    return convex_hull;
}