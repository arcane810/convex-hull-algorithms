/** @file */

#pragma once
#include "utils.hpp"
#include <vector>

/**
 * Return the Convex Hull of a set of points using the Quickhull algorithm.
 * Works in worse case time complexity O(N*N) and space complexity O(N+H) where N is the number of points and H is the number of points in the Convex Hull.
 * 
 * @param points A vector of points for which the Convex Hull is to be found
 * @return A vector of points which contains the points of the Convex Hull
 * 
 * @relatesalso Point
 */
std::vector<Point> Hull(std::vector<Point> points);