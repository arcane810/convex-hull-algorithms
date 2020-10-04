#include "quickHull.hpp"
#include "utils.hpp"
#include <cmath>
#define max_y 1000000000
#define min_y -1000000000
// Output hull
std::vector<Point> convex_hull;

void quickHull(Point p, Point q, std::vector<Point> points)
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
        quickHull(farthest, p, upper);
        // Add farthest point from line pq to convex hull
        convex_hull.push_back(farthest);
        quickHull(q, farthest, lower);
    }
}

std::vector<Point> Hull(std::vector<Point> points)
{
    if (points.size() <= 2)
    {
        return points;
    }

    // Select top-most and bottom-most point 
    Point p , q;
    p.x = q.x = 0;
    p.y = min_y;
    q.y = max_y;
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
    // Add p to the convex hull
    convex_hull.push_back(p);
    quickHull(p, q, left);
    // Add q to the convex hull
    convex_hull.push_back(q);
    quickHull(q, p, right);

    return convex_hull;
}