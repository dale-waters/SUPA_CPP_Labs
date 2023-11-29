// Title: SUPACOO 2023 - Assignment 1
// Subtitle: Function Headers
// Editor: Dale Waters
// Last Edited: 29/11/2023

#pragma once

#include <vector>
#include <string>

// Struct to represent (x, y) values
struct Point {
    double x;
    double y;
};

// Struct to represent errors for (x, y) values
struct ErrorPoint {
    double xError;
    double yError;
};

// Function declarations
std::vector<Point> readPointsFromFile(const std::string& filename);
std::vector<ErrorPoint> readErrorsFromFile(const std::string& filename);
void printData(const std::vector<Point>& points, int n);
std::vector<double> calculateMagnitudes(const std::vector<Point>& points);
std::string fitStraightLine(const std::vector<Point>& points, const std::vector<ErrorPoint>& errors, double& chiSquared, int& ndf);
std::vector<double> calculatePower(const std::vector<Point>& points);
void saveOutputToFile(const std::string& filename, const std::string& output);


// // NOT WORKING!!! Overloaded print function to print either (x, y) values or magnitudes
// template <typename T>
// void printValues(const std::vector<T>& values, int n = -1);
