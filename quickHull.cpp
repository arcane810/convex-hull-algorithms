/** @file */

#include "quickHull.hpp"
#include <cmath>

/**
 * Adds farthest point from line joining p,q to convex hull and recrsively divides the point set to find convex hull
 * 
 * @param p 1st point of line
 * @param q 2nd point of line
 * @param points A vector of points chosen from previous division of points below and above a line
 * @param convex_hull The convex hull for overall set to which the points in convex hull are added, passed by reference
 * 
 * @relatesalso Point
 */
void quickHullHelper(Point p, Point q, std::vector<Point> points, std::vector<Point> &convex_hull)
{
    if (points.size() > 0)
    {
        Point farthest;
        long double max_dist = 0;

        // Select the point at maximum distance from line
        for (Point point : points)
        {
            long double dist = point.findDist(p, q);
            if (dist > max_dist)
            {
                max_dist = dist;
                farthest = point;
            }
        }
        // Select points outside triangle formed by p, q, farthest
        std::vector<Point> upper, lower;
        for (Point point : points)
        {
            if (signedTriangleArea(farthest, p, point) > 0)
            {
                upper.push_back(point);
            }
            if (signedTriangleArea(q, farthest, point) > 0)
            {
                lower.push_back(point);
            }
        }
        // Recurse on exterior points afer pruning interior points
        quickHullHelper(farthest, p, upper, convex_hull);
        // Add farthest point from line pq to convex hull
        convex_hull.push_back(farthest);
        quickHullHelper(q, farthest, lower, convex_hull);
    }
}

std::vector<Point> quickHull(std::vector<Point> points)
{
    if (points.size() <= 2)
    {
        return points;
    }

    // Select top-most and bottom-most point
    Point p, q;
    p = points[0];
    q = points[0];
    for (Point point : points)
    {
        if (point.y < q.y)
        {
            q = point;
        }
        else if (point.y == q.y && point.x > q.x)
        {
            q = point;
        }
        if (point.y > p.y)
        {
            p = point;
        }
        else if (point.y == p.y && point.x > p.x)
        {
            p = point;
        }
    }

    // Split into two sets, left and right of the line joining q to p.
    std::vector<Point> left, right;
    for (Point point : points)
    {
        if (signedTriangleArea(p, q, point) < 0)
        {
            left.push_back(point);
        }
        else if (signedTriangleArea(p, q, point) > 0)
        {
            right.push_back(point);
        }
    }

    std::vector<Point> convex_hull;
    // Add p to the convex hull
    convex_hull.push_back(p);
    quickHullHelper(p, q, left, convex_hull);
    // Add q to the convex hull
    convex_hull.push_back(q);
    quickHullHelper(q, p, right, convex_hull);

    return convex_hull;
}