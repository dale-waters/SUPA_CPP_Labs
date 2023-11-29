// Title: SUPACOO 2023 - Assignment 1
// Subtitle: Data Analysis
// Editor: Dale Waters
// Last edited: 29/11/2023

// Files submitted for evaluation: AnalyseData.cxx; CustomFuntions.cxx; CustomFunctions.h; Makefile

#include "CustomFunctions.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
    
    // Welcome message
    std::cout << "Welcome to the Data Analysis Program!" << std::endl;
    
    // Variable to control the main loop
    bool exitProgram = false;

    do{

        // File name: Please check that file is in the same directory
        const char* filename = "input2D_float.txt"; 

        // // Prompt the user for the file name
            // std::string filename;
            // std::cout << "Enter the file name: ";
            // std::getline(std::cin, filename);

        // Read (x, y) values from the file into a vector
        std::vector<Point> points = readPointsFromFile(filename);

        // Error file name: Please check that file is in the same directory
        const char* errorsFilename = "error2D_float.txt"; 

        // // Prompt the user for the errors file name
            // std::string errorsFilename;
            // std::cout << "Enter the errors file name: ";
            // std::getline(std::cin, errorsFilename);

        // Read errors from the file into a vector
        std::vector<ErrorPoint> errors = readErrorsFromFile(errorsFilename);

        // Ask the user which function to use
        std::cout << "Choose a function to perform:\n"
                    "1. Print points\n"
                    "2. Calculate magnitudes\n"
                    "3. Fit a straight line\n"
                    "4. Calculate x to the power of y\n"
                    "5. Exit\n"
                    "Enter your choice (1 - 5): ";
        
        int choice, n; // 1 - 5 choice, and n number of lines to print
        std::cin >> choice;

        switch(choice){
            // Perform the chosen function
            case 1: 
            {
                    int totalLines = points.size();

            
                // Print data
                std::cout << "There are " << totalLines << " lines in the file. Enter the number of lines you wish to print:" << std::endl;
                std::cin >> n;

                // Handle invalid input for n
                if (std::cin.fail() || n < 0) {
                std::cerr << "Error: Invalid input. Exiting program." << std::endl;
                return 1;
                }

                // Warn if n is larger than the total number of data points
                if (n > static_cast<int>(points.size())) {
                    std::cerr << "Warning: Requested lines to print exceed total data points. Printing first 5 lines." << std::endl;
                    n = std::min(5, static_cast<int>(points.size()));
                }

                printData(points, n);
  
                // Convert results to a string
                std::string output = "Printing the first " + std::to_string(n) + " data points:\n";

                    for (int i = 0; i < n; ++i) {
                    output += "(" + std::to_string(points[i].x) + ", " + std::to_string(points[i].y) + ")" + "\n";
                };

                 // Save the results to a file
                saveOutputToFile("1.LinesofData.txt", output);


                break;
                } 
            
            case 2: 
            {
                // If the user chooses to calculate the magnitudes of (x,y) coordinates, call the function
                std::vector<double> magnitudes = calculateMagnitudes(points);

                // Convert results to a string
                std::string output = "Calculated the magnitudes of (x,y) coordinates assuming they are the coordinates of a vector:\n";
                for (std::size_t i = 0; i < points.size(); ++i) {
                    output += "The magnitude for (" + std::to_string(points[i].x) + ", " + std::to_string(points[i].y) + ") is: " + std::to_string(magnitudes[i]) + "\n";
                }

                // Save the results to a file
                saveOutputToFile("2.MagnitudeResults.txt", output);

                break;
            } 
            
            case 3: 
            {
                // If the user chooses to fit a straight line, call the function
                double chiSquared;
                int ndf;
                std::string equation = fitStraightLine(points, errors, chiSquared, ndf);
                std::cout << "Fitted Straight Line Equation: " << equation << std::endl;
                std::cout << "Chi-Squared / NDF = " << chiSquared / ndf << std::endl;

                // Save the equation and chi-squared to a file
                std::ofstream outFile("3.FittedLineEquation.txt");
                if (outFile.is_open()) {
                    outFile << "Fitted Straight Line Equation: " << equation << std::endl;
                    outFile << "Chi-Squared / NDF = " << chiSquared / ndf << std::endl;
                    outFile.close();
                    std::cout << "Fitted Line Equation and Chi-Squared / NDF saved to 'FittedLineEquation.txt'" << std::endl;
                } else {
                    std::cerr << "Error saving Fitted Line Equation to file." << std::endl;}
                break;
            }
            case 4: 
            {
                // If the user chooses to calculate x to the power of y, call the function
                std::vector<double> powerResults = calculatePower(points);

                // Convert results to a string
                std::string output = "Calculated x to the power of y (rounded to the nearest whole number):\n";
                for (std::size_t i = 0; i < points.size(); ++i) {
                    output += "x^y for (" + std::to_string(points[i].x) + ", " + std::to_string(points[i].y) + ") is: " + std::to_string(powerResults[i]) + "\n";
                }

                // Save the results to a file
                saveOutputToFile("4.PowerResults.txt", output);

                break;
            }
            case 5:
                // Exit the program
                exitProgram = true;
                break;
            default:
                std::cerr << "Error: Invalid input. Exiting Program." << std::endl;
                return 1;
        }
            
        
        // If the user did not choose to exit, ask if they want to perform another action
        if (!exitProgram) {
            char anotherAction;
            std::cout << "Do you want to perform another action? (y/n): ";
            std::cin >> anotherAction;

            if (anotherAction != 'y' && anotherAction != 'Y') {
                exitProgram = true;
            }
        }

    } while (!exitProgram);

    // Thanking message
    std::cout << "Thank you for using the Data Analysis Program!" << std::endl;

    return 0;
}
