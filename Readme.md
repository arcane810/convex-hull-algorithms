# Convex Hull Algorithms

An API which provides implementation of various convex hull algorithms. Made as a part of the computation geometry course at BITS Pilani, Hyderabad Campus

This API provides a Point class with some general functions about it and 3 Convex Hull Algorithms:

-   Graham's Scan (grahamScan.hpp and grahamScan.cpp)
-   Jarvis March (jarvisMarch.hpp and jarvisMarch.cpp)
-   QuickHull (quickHull.hpp and quickHull.cpp)

Steps to use the API:

-   Use utils.hpp header for the Point class
-   Include the header file algorithmName.hpp  
    Eg:
    #include <grahamScan.hpp>
-   Use the function for the respective algorithm
-   Compile your C++ file with the file algorithmName.cpp and utils.cpp  
    Eg:
    g++ test.cpp grahamScan.cpp utils.cpp
