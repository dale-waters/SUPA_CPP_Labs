// Title: SUPACOO 2023 - Assignment 2
// Subtitle: Data Analysis
// Editor: Dale Waters
// Last edited: 15/12/2023

// Files submitted for evaluation: Text.cxx, FiniteFunctions.h, FiniteFunctions.cxx, CustomFunctions.h, CustomFunctions.cxx, Makefile

// Steps-to-run

// i). Enter "make" into the terminal
// ii). Enter "./Test" into the terminal

// Troubleshooting

// i). A copy of "MysteryData.txt" must be in the same folder as Test.cxx
// ii). A copy of "gnuplot-iostream.h" must be in the same folder as FiniteFunctions.h

#include <iostream>
#include <fstream>
#include <vector>
#include "FiniteFunctions.h" // Include the implementation file for the FiniteFunctions
#include "CustomFunctions.h" // Added 13/12/2023 - D.Waters
// #include <random> // Added 15/12/2023 - D.Waters
#include <cstdlib>
#include <ctime>


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
    finiteFunc.setOutfile("DefaultFiniteFunction");

    // Print and plot
    finiteFunc.printInfo();
    finiteFunc.plotFunction(); // Plot the function
    finiteFunc.plotData(dataPoints, 100, true); // Plot data points (100 bins for data points)

    // Create a NormalDistribution object
    NormalDistribution normalDist(dataPoints); // Pass dataPoints to the constructor
    
    // Set funtion limits (you can adjust these limits accordingly)
    normalDist.setRangeMin(-8.0);
    normalDist.setRangeMax(7.0);
    normalDist.setOutfile("NormalDistribution");

    // Print and plot
    normalDist.printInfo();
    normalDist.plotFunction();
    normalDist.plotData(dataPoints, 100, true); // 100 bins for data points

    // Create a CauchyLorentzDistribution object
    CauchyLorentzDistribution cauchyLorentzDist(dataPoints); // Pass dataPoints to the constructor
    
    // Set function limits (you can adjust these limits accordingly)
    cauchyLorentzDist.setRangeMin(-7.0);
    cauchyLorentzDist.setRangeMax(7.0);
    cauchyLorentzDist.setOutfile("CauchyLorentzDistribution");

    // Print and plot
    cauchyLorentzDist.printInfo();
    cauchyLorentzDist.plotFunction();
    cauchyLorentzDist.plotData(dataPoints, 100, true); // 100 bins for data points

  // Create a NegativeCrystalBallDistribution object
    NegativeCrystalBallDistribution crystalBallDist(dataPoints); // Pass dataPoints to the constructor

    // Set function limits (you can adjust these limits accordingly)
    crystalBallDist.setRangeMin(-7.0);
    crystalBallDist.setRangeMax(7.0);
    crystalBallDist.setOutfile("NegativeCrystalBallDistribution");

    // Fit parameters to best match the data
    crystalBallDist.setAlpha(1.0); // alpha > 0
    crystalBallDist.setN(2.0); // n > 1

    // Print and plot
    crystalBallDist.printInfo();
    crystalBallDist.plotFunction();
    crystalBallDist.plotData(dataPoints, 100, true); // 100 bins for data points

/*
###################
// 2.1 RNG
###################
*/ 

    // Metropolis Algorithm for Sampling
    int numSamples = 10000;
    std::vector<double> generatedSamplesX;
    std::vector<double> generatedSamplesY;

    double currentX = normalDist.generateRandomNumber(normalDist.rangeMin(), normalDist.rangeMax());

    for (int i = 0; i < numSamples; ++i) {

        // Proposal step: Generate a proposal sample from a uniform distribution
        double proposalX = normalDist.generateRandomNumber(normalDist.rangeMin(), normalDist.rangeMax());
        
        // Acceptance ratio
        double acceptanceRatio = normalDist.callFunction(proposalX) / normalDist.callFunction(currentX);

        // Metropolis acceptance criterion
        if (acceptanceRatio >= 1.0 || (acceptanceRatio > normalDist.generateRandomNumber(0.0, 1.0))) {
            currentX = proposalX;
        }

        // Generate a second random number y from a normal distribution centered on xi
        double proposalY = normalDist.generateNormalNumber(currentX, 1.0);

        // Acceptance ratio
        double A = normalDist.computeA(currentX, proposalY);

        // Metropolis acceptance criterion
        double T = normalDist.generateRandomNumber(0.0, 1.0);

        if (T < A) {
            currentX = proposalY;
        }

        // Store the generated samples
        generatedSamplesX.push_back(currentX);

    }

    // Plot the generated samples
    normalDist.plotData(generatedSamplesX, 100, false); // 100 bins for generated samples X

    return 0;
}