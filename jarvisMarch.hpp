/** @file */

#pragma once
#include "utils.hpp"
#include <vector>

/**
 * Return the Convex Hull (ordered in anticlockwise direction) of a set of points using the Jarvis March algorithm.
 * Works in worse case time complexity O(N*H) and space complexity O(N+H) where N is the number of points and H is the number of points in the Convex Hull.
 * 
 * @param points A vector of points for which the Convex Hull is to be found
 * @return A vector of points which contains the points of the Convex Hull in anti-clockwise order
 * 
 * @relatesalso Point
 */
std::vector<Point> jarvisMarch(std::vector<Point> points);