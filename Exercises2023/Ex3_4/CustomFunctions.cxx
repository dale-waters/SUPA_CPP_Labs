// Title: SUPACOO 2023 - Assignment 2
// Subtitle: CustomFunctions.cxx
// Editor: Dale Waters
// Last edited: 15/12/2023


#include "CustomFunctions.h"
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <limits>

/*
###################
// Normal
###################
*/

NormalDistribution::NormalDistribution() : FiniteFunction() {
    // Default constructor
}

// Overloaded Constructor

NormalDistribution::NormalDistribution(const std::vector<double>& data) : FiniteFunction() {
    m_Mean = calculateMean(data);
    m_StdDev = calculateStdDev(data);
}

double NormalDistribution::callFunction(double x) const {
    // Normal distribution formula
    return exp(-0.5 * pow((x - m_Mean) / m_StdDev, 2)) / (m_StdDev * sqrt(2 * M_PI));
}

void NormalDistribution::printInfo() {
    std::cout << "Normal Distribution Info:" << std::endl;
    std::cout << "Mean: " << m_Mean << std::endl;
    std::cout << "Standard Deviation: " << m_StdDev << std::endl;
    FiniteFunction::printInfo(); // Call base class printInfo
}


/*
###################
// Cauchy-Lorentz
###################
*/

CauchyLorentzDistribution::CauchyLorentzDistribution() : FiniteFunction() {
    // Default Constructor
}

CauchyLorentzDistribution::CauchyLorentzDistribution(const std::vector<double>& data) : FiniteFunction() {
    // Overloaded Constructor
    m_Location = calculateMean(data);
    m_Scale = calculateStdDev(data);
}

double CauchyLorentzDistribution::callFunction(double x) const {
    // Cauchy-Lorentz distribution formula
    return (1 / M_PI) * (m_Scale / ((x - m_Location) * (x - m_Location) + m_Scale * m_Scale));
}

void CauchyLorentzDistribution::printInfo() {
    std::cout << "Cauchy-Lorentz Distribution Info:" << std::endl;
    std::cout << "Location: " << m_Location << std::endl;
    std::cout << "Scale: " << m_Scale << std::endl;
    FiniteFunction::printInfo(); // Call base class printInfo
}

/*
###################
// Negative Crystal Ball
###################
*/

NegativeCrystalBallDistribution::NegativeCrystalBallDistribution()
    : m_Alpha(1.0), m_N(2.0), FiniteFunction() {}

NegativeCrystalBallDistribution::NegativeCrystalBallDistribution(const std::vector<double>& data) : m_Alpha(1.0), m_N(2.0), FiniteFunction() {
    // Overloaded Constructor
    m_Mean = calculateMean(data);
    m_Sigma = calculateStdDev(data);
}

void NegativeCrystalBallDistribution::setAlpha(double alpha) {
    m_Alpha = alpha;
}

void NegativeCrystalBallDistribution::setN(double n) {
    m_N = n;
}

double NegativeCrystalBallDistribution::callFunction(double x) const {
    // Negative Crystal Ball distribution formula (unchanged)
    double t = (x - m_Mean) / m_Sigma;
    double c = (m_N / m_Alpha) * (1 / (m_N - 1)) * exp(-0.5 * m_Alpha * m_Alpha);
    double d = sqrt(M_PI_2) * (1 + erf(fabs(m_Alpha) / sqrt(2)));
    double upper_N = 1 / m_Sigma * (c + d);

    if (t >= -m_Alpha) {
        return upper_N * exp(-0.5 * t * t);
    } else {
        double a = pow(m_N / fabs(m_Alpha), m_N) * exp(-0.5 * m_Alpha * m_Alpha);
        double b = m_N / fabs(m_Alpha) - fabs(m_Alpha);
        return upper_N * a / pow(b - t, m_N);
    }
}

void NegativeCrystalBallDistribution::printInfo() {
    std::cout << "Negative Crystal Ball Distribution Info:" << std::endl;
    std::cout << "Alpha: " << m_Alpha << std::endl;
    std::cout << "n: " << m_N << std::endl;
    std::cout << "Mean: " << m_Mean << std::endl;
    std::cout << "Sigma: " << m_Sigma << std::endl;
    FiniteFunction::printInfo(); // Call base class printInfo
}
