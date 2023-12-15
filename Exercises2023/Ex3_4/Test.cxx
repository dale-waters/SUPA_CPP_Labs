// Title: SUPACOO 2023 - Assignment 2
// Subtitle: Data Analysis
// Editor: Dale Waters
// Last edited: 13/12/2023

// Files submitted for evaluation: 

// Problems with code:

// i). the MysteryData file must be in the same folder as Test.cxx

#include <iostream>
#include <fstream>
#include <vector>
#include "FiniteFunctions.h" // Include the implementation file for the FiniteFunctions
// #include "gnuplot-iostream.h"
#include "CustomFunctions.h"

int main() {

    // Specify the path to the file in another folder
    std::string filePath = "MysteryData21212.txt";

    // Read data from MysteryData.txt
    std::ifstream dataFile(filePath);

    if (!dataFile.is_open()) {
        std::cerr << "Error: Unable to open MysteryData.txt" << std::endl;
        return 1;
    }

    std::vector<double> dataPoints;
    double x;
    while (dataFile >> x) {
        dataPoints.push_back(x);
    }
    dataFile.close();

    // Create a FiniteFunction object
    FiniteFunction finiteFunc;

    // Set function limits (you can adjust these limits accordingly)
    finiteFunc.setRangeMin(-10.0);
    finiteFunc.setRangeMax(10.0);
    std::cout << "The upper and lower limits of my function are " << finiteFunc.rangeMin() << " and " << finiteFunc.rangeMax() << " respectively." << std::endl;

    finiteFunc.plotFunction();
    finiteFunc.plotData(dataPoints, 100, true); // 100 bins for data points

    // Test Normal Distribution
    NormalDistribution normalDist;
    normalDist.setRangeMin(-10.0);
    normalDist.setRangeMax(10.0);
    normalDist.setMean(5);
    normalDist.setStdDev(5);

    normalDist.integral(1000); // You can adjust the number of divisions
    normalDist.printInfo();
    normalDist.plotFunction();

    return 0;
}