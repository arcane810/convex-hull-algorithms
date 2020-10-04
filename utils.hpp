/** @file */

#pragma once

/**
 * A Class for representing a point in a two-dimensional cartesian plane
 */
class Point
{
public:
    /// The x coordinate of the point
    long double x;
    /// The y coordinate of the point
    long double y;

    /**
     * Constructor. Initializes the coordinates to the passed parameters
     * 
     * @param x The x coordinate
     * @param y The y coordinate
     */
    Point(long double x, long double y);

    /**
     * Default Constructor
     */
    Point();

    /**
     * Equality operator. Two points are equal if they have the same x and y coordinates
     */
    bool operator==(const Point &point);
    long double findDist(Point p, Point q);
};

/**
 * Find signed area of triangle formed by 3 points in a fixed order
 * 
 * @param A 1st Point
 * @param B 2nd Point
 * @param C 3rd Point
 * @return The signed area of triangle formed by points A,B,C in the same order.
 * 
 * @relatesalso Point 
 */
long double signedTriangleArea(Point A, Point B, Point C);
/**
 * Find distance of a point from a line joining two points.
 * @param p 1st Point
 * @param q 2nd Point
 * @return The distance of Point from the line joining p and q.
 * 
 * @relatesalso Point 
 */
