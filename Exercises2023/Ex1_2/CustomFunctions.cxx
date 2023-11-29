// Title: SUPACOO 2023 - Assignment 1
// Substitle: Functions
// Editor: Dale Waters
// Last Edited: 29/11/2023

#include "CustomFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

// Function to read (x, y) values from a file
std::vector<Point> readPointsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return {};
    }

    std::vector<Point> points;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Point p;
        char comma;
        if (ss >> p.x >> comma >> p.y) {
            points.push_back(p);
        } else {
            // std::cerr << "Error reading line: " << line << std::endl;
        }
    }

    file.close();
    return points;
}

// Function to read error values for (x, y) from a file
std::vector<ErrorPoint> readErrorsFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return {};
    }

    std::vector<ErrorPoint> errors;
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        ErrorPoint error;
        char comma;
        if (ss >> error.xError >> comma >> error.yError) {
            errors.push_back(error);
        } else {
            // std::cerr << "Error reading line: " << line << std::endl;
        }
    }

    file.close();
    return errors;
}

// Function to print 'n' lines of data
void printData(const std::vector<Point>& points, int n){


    for (int i = 0; i < n; ++i) {
        std::cout << "(" << points[i].x << ", " << points[i].y << ")" << std::endl;
    }
}



// Function to calculate magnitudes from (x, y) values
std::vector<double> calculateMagnitudes(const std::vector<Point>& points) {
    std::vector<double> magnitudes;

    std::cout << "Calculated Magnitudes:" << std::endl;
    for (const auto& point : points) {
        double magnitude = std::sqrt(point.x * point.x + point.y * point.y);
        magnitudes.push_back(magnitude);
        std::cout << magnitude << std::endl;
    }

    return magnitudes;
}

// Function to fit a straight line (y = mx + c) using the least squares method
std::string fitStraightLine(const std::vector<Point>& points, const std::vector<ErrorPoint>& errors, double& chiSquared, int& ndf) {
    int n = static_cast<int>(points.size());

    // Initialize variables for sums
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
    double sumW = 0.0, sumWX = 0.0, sumWY = 0.0, sumWXY = 0.0;

    // Calculate sums
    for (int i = 0; i < n; ++i) {
        double w = 1.0 / (errors[i].yError * errors[i].yError);
        sumX += points[i].x;
        sumY += points[i].y;
        sumXY += points[i].x * points[i].y;
        sumX2 += points[i].x * points[i].x;

        sumW += w;
        sumWX += w * points[i].x;
        sumWY += w * points[i].y;
        sumWXY += w * points[i].x * points[i].y;
    }

    // Calculate coefficients for the straight line (y = mx + c)
    double m = (sumW * sumWXY - sumWX * sumWY) / (sumW * sumX2 - sumWX * sumWX);
    double c = (sumWY - m * sumWX) / sumW;

    // Calculate chi-squared
    chiSquared = 0.0;
    for (int i = 0; i < n; ++i) {
        double residual = points[i].y - (m * points[i].x + c);
        chiSquared += residual * residual / (errors[i].yError * errors[i].yError);
    }

    // Calculate number of degrees of freedom (NDF)
    ndf = n - 2; // Assuming a linear fit (2 parameters: m and c)

    // Save the final function as a string
    std::stringstream ss;
    ss << std::fixed << "y = " << m << "x + " << c
       << "\nChi-Squared / NDF = " << chiSquared / ndf;

    return ss.str();
}

// Function to calculate x to the power of y for each (x, y) data point
std::vector<double> calculatePower(const std::vector<Point>& points) {
    std::vector<double> powerResults;

    std::cout << "Calculated x to the power of y (rounded to the nearest whole number):" << std::endl;
    for (const auto& point : points) {
        // Round y to the nearest whole number
        int roundedY = static_cast<int>(std::round(point.y));

        // Calculate x to the power of y without using pow, std::pow, or a loop
        double result = std::exp(roundedY * std::log(point.x));

        powerResults.push_back(result);

        std::cout << point.x << " ^ " << roundedY << " = " << result << std::endl;
    }

    return powerResults;
}

// Function to save output to a file
void saveOutputToFile(const std::string& filename, const std::string& output) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << output << std::endl;
        outFile.close();
        std::cout << "Output saved to '" << filename << "'" << std::endl;
    } else {
        std::cerr << "Error saving output to file." << std::endl;
    }
}


// // NOT WORKING!!!! Overloaded print function to print either (x, y) values or magnitudes
// template <typename T>
// void printValues(const std::vector<T>& values, int n = -1) {
//     // int n
//     // std::cout << "Enter the number of lines to print:" << std::endl;
//     // std::cin >> n;

//     std::cout << "Printing ";
//     if (n == -1) {
//         std::cout << "all ";
//     } else {
//         std::cout << n << " ";
//     }
//     std::cout << "lines:" << std::endl;

//     int count = 0;
//     for (const auto& value : values) {
//         if (n != -1 && count >= n) {
//             break;
//         }
//         std::cout << value << std::endl;
//         ++count;
//     }
// }