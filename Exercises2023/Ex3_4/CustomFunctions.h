#include "FiniteFunctions.h"

// Normal Distribution
class NormalDistribution : public FiniteFunction {

public:
    NormalDistribution();
    NormalDistribution(double mean, double stddev, double range_min, double range_max, std::string outfile);
    virtual double callFunction(double x);

    void setMean(double mean);
    void setStdDev(double stddev);

private:
    double m_Mean;
    double m_StdDev;
};

// // Cauchy-Lorentz Distribution
// class CauchyLorentzDistribution : public FiniteFunction {
// public:
//     CauchyLorentzDistribution(double location, double scale, double range_min, double range_max, std::string outfile);
//     virtual double callFunction(double x);

// private:
//     double m_Location;
//     double m_Scale;
// };

// // Negative Crystal Ball Distribution
// class NegativeCrystalBallDistribution : public FiniteFunction {
// public:
//     NegativeCrystalBallDistribution(double alpha, double n, double sigma, double range_min, double range_max, std::string outfile);
//     virtual double callFunction(double x);

// private:
//     double m_Alpha;
//     double m_N;
//     double m_Sigma;
// };