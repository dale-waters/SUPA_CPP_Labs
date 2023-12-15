// Title: SUPACOO 2023 - Assignment 2
// Subtitle: CustomFunctions.h
// Editor: Dale Waters
// Last edited: 15/12/2023

// Changelog:

// 15/12/2023 "const" added to "callFunction" for all classes

// 14/12/2023 CustomFunctions add new classes which inherit from the base FiniteFunction class
// New classes were added for:
// 2. The Cauchy-Lorentz distribution - D.Waters
// 3. The negative Crystal Ball distribution - D.Waters

// 13/12/2023 CustomFunctions add new classes which inherit from the base FiniteFunction class
// New classes were added for:
// 1. The normal distribution - D.Waters


#include "FiniteFunctions.h"
#include <cmath>
#include <vector>
#include <algorithm>

// Normal distribution

class NormalDistribution : public FiniteFunction {
public:
    // Constructors
    NormalDistribution();
    NormalDistribution(const std::vector<double>& data);;

    // Override necessary functions
    double callFunction(double x) const override;
    void printInfo() override;
    // double integrate(int Ndiv) override;

private:

    // Data members for normal distribution parameters
    double m_Mean;
    double m_StdDev;
};


// Cauchy-Lorentz

class CauchyLorentzDistribution : public FiniteFunction {
public:
    // Constructors
    CauchyLorentzDistribution();
    CauchyLorentzDistribution(const std::vector<double>& data);;

    // Override necessary functions
    double callFunction(double x) const override;
    void printInfo() override;

private:
    // Data members for Cauchy-Lorentz distribution parameters
    double m_Location; // Location parameter (center), here we approximate using "calculateMeanmean()"
    double m_Scale;    // Scale parameter (half-width at half-maximum), here we approximate using "calculateStdDev()"
};

// Negative Crystal Ball

class NegativeCrystalBallDistribution : public FiniteFunction {
public:
    // Constructors
    NegativeCrystalBallDistribution();
    NegativeCrystalBallDistribution(const std::vector<double>& data);;

    // Setters for parameters
    void setAlpha(double alpha);
    void setN(double n);

    // Override necessary functions
    double callFunction(double x) const override;
    void printInfo() override;

private:
    // Data members for negative Crystal Ball distribution parameters
    double m_Alpha; // Alpha parameter
    double m_N;     // n parameter
    double m_Mean;
    double m_Sigma;
};
