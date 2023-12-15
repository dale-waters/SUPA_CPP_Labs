// Title: SUPACOO 2023 - Assignment 2
// Subtitle: estimate_pi.cxx
// Editor: Dale Waters
// Last edited: 15/12/2023

// Steps-to-run

// To compile and run the scrip enter the following in the terminal:
// "./estimate_pi <radius> <number_of_random_points>"
// i.e. "./estimate_pi 16 2000000"

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>

int main(int argc, char* argv[]) {

    // Check if the correct number of command line arguments are provided
       if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <radius> <number_of_random_points>" << std::endl;
        return 1;
    }

    // Parse command line arguments
    double radius = std::atof(argv[1]);
    int n = std::atoi(argv[2]);

    // Check if the input values are valid
    if (radius <= 0 || n <= 0) {
        std::cerr << "Both radius and the number of random points must be positive numbers." << std::endl;
        return 1;
    }

    // Seed the random number generator using the current time
    auto seed = static_cast<unsigned>(std::time(NULL));
    std::mt19937 mtEngine(seed);

    // Define a uniform real distribution for generating random numbers between -1.0 and 1.0
    std::uniform_real_distribution<double> distribution(-1.0, 1.0);

    // Variables to count points inside the circle
    int insideCircle = 0;

    // Generate random points and check if they are inside the circle
    for (int i = 0; i < n; ++i) {
        double x = distribution(mtEngine); // Random x-coordinate between -1 and 1
        double y = distribution(mtEngine); // Random y-coordinate between -1 and 1

        double distance = std::sqrt(x * x + y * y);

        // Check if the point is inside the circle
        if (distance <= 1.0) {
            ++insideCircle;
        }
    }

    // Estimate the value of Pi based on the ratio of points inside the circle
    double piEstimation = 4.0 * static_cast<double>(insideCircle) / n;

    // Output the estimated value of Pi with 10 decimal places
    std::cout.precision(10);
    std::cout << "Estimated value of Pi: " << std::fixed << piEstimation << std::endl;

    return 0;
}