#include "FiniteFunctions.h"
#include "CustomFunctions.h"

// Normal Distribution

// OVERLOAD CONSTUCTOR
NormalDistribution::NormalDistribution(double mean, double stddev, double range_min, double range_max, std::string outfile){

    FiniteFunction(range_min, range_max, outfile); //call the parent class' constructor
    m_Mean = mean;
    m_StdDev = stddev;


// SETTERS    
void setMean(double mean){m_Mean = mean;};
void setStdDev(double stddev){m_StdDev = stddev;};

// OVERIDING FUNCTIONS
double NormalDistribution::callFunction(double x) {

    FiniteFunction::callFunction(double x);
    
        return std::exp(-0.5 * ((x - m_Mean) / m_StdDev) * ((x - m_Mean) / m_StdDev)) / (m_StdDev * std::sqrt(2 * M_PI));
    }


// // Cauchy-Lorentz Distribution

//     CauchyLorentzDistribution(double location, double scale, double range_min, double range_max, std::string outfile)
//         : FiniteFunction(range_min, range_max, outfile), m_Location(location), m_Scale(scale) {}

//     virtual double callFunction(double x) {
//         return (1.0 / (M_PI * m_Scale)) * (1 +  ((x - m_Location) * (x - m_Location) / m_Scale * m_Scale));
//     }


// // Negative Crystal Ball Distribution

//     NegativeCrystalBallDistribution(double alpha, double n, double sigma, double range_min, double range_max, std::string outfile)
//         : FiniteFunction(range_min, range_max, outfile), m_Alpha(alpha), m_N(n), m_Sigma(sigma) {}

//     virtual double callFunction(double x) {
//         double z = (x - m_Alpha) / m_Sigma;
//         if (z < -m_N) {
//             return std::exp(-0.5 * m_N * m_N);
//         } else {
//             return std::exp(-0.5 * z * z);
//         }
//     }
