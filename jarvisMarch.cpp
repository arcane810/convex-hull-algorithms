#include "jarvisMarch.hpp"
#include <cmath>

std::vector<Point> jarvisMarch(std::vector<Point> points)
{
    if (points.size() <= 2)
    {
        return points;
    }

    // Select any point of CH as origin
    Point origin = points[0];
    for (Point point : points)
    {
        if (point.x < origin.x)
        {
            origin = point;
        }
        else if (point.x == origin.x && point.y < origin.y)
        {
            origin = point;
        }
    }
    std::vector<Point> convex_hull;
    // Push origin to CH
    convex_hull.push_back(origin);

    // Keep looping till the new point is same as the 1st point in CH
    while (true)
    {
        Point minimumAnglePoint = points[0];
        for (Point point : points)
        {
            if (point == origin)
            {
                continue;
            }
            long double area = signedTriangleArea(origin, minimumAnglePoint, point);
            if (area < 0)
            {
                // area less than 0 means new point makes a smaller angle
                minimumAnglePoint = point;
            }
            else if (area == 0)
            {
                // if current point is collinear to the minimum Angle point, choose the closer one
                if (std::abs(origin.x - point.x) < std::abs(origin.x - minimumAnglePoint.x))
                {
                    minimumAnglePoint = point;
                }
            }
        }
        if (convex_hull[0] == minimumAnglePoint)
        {
            // break if 1st point is reached again
            break;
        }
        else
        {
            // push current point to CH and make this origin
            convex_hull.push_back(minimumAnglePoint);
            origin = minimumAnglePoint;
        }
    }
    return convex_hull;
}