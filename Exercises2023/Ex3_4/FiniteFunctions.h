// Title: SUPACOO 2023 - Assignment 2
// Subtitle: FiniteFunctions.h
// Editor: Dale Waters
// Last edited: 15/12/2023

// Changelog:

// 15/12/2023 added "generateRandomNumber", "generateNormalNumber", "computeA" as public class members - D.Waters

// 15/12/2023 const added to "callFunction" and "invxsquared" - D.Waters

// 14/12/2023 Added functions "calculateMean" and "calculateStdDev" as protected class members - D.Waters

#include <string>
#include <vector>
#include "gnuplot-iostream.h"
#include <cmath>
#include <numeric> // Added for std::accumulate
#include <random> // Added 15/12/2023 - D.Waters

#pragma once //Replacement for IFNDEF

class FiniteFunction{

public:
  // Constructors
  FiniteFunction(); //Empty constructor
  FiniteFunction(double range_min, double range_max, std::string outfile); //Variable constructor
  
  // Destructor
  ~FiniteFunction(); //Destructor
  
  // Setters
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  void setOutfile(std::string outfile);

  // Getters
  double rangeMin(); //Low end of the range the function is defined within
  double rangeMax(); //High end of the range the function is defined within
  
  // Integration
  double integral(int Ndiv = 1000); 
  
  // Private class member
  std::vector< std::pair<double,double> > scanFunction(int Nscan = 1000); //Scan over function to plot it (slight hack needed to plot function in gnuplot)

  // New function for normalization to data
  void normalizeToData(std::vector<double>& data);

  // Plotting
  void plotFunction(); //Plot the function using scanFunction
  // Plot the supplied data points (either provided data or points sampled from function) as a histogram using NBins
  void plotData(std::vector<double> &points, int NBins, bool isdata=true); //NB! use isdata flag to pick between data and sampled distributions
  
  // Helper function
  virtual void printInfo(); //Dump parameter info about the current function (Overridable)
  
  // Function Evaluation
  virtual double callFunction(double x) const; //Call the function with value x (Overridable)

  // Functions added 15.12.2023 - D.Waters

    // Function to generate a random number in a given range
    double generateRandomNumber(double rangeMin, double rangeMax);

    // Function to generate a random number from a normal distribution
    double generateNormalNumber(double mean, double stddev);

    // Function to compute Metropolis acceptance criterion A
    double computeA(double xi, double y);

  //Protected members can be accessed by child classes but not users
protected:

  // Data members
  double m_RMin;
  double m_RMax;
  double m_Integral;
  int m_IntDiv = 0; //Number of division for performing integral
  std::string m_FunctionName;
  std::string m_OutData; //Output filename for data
  std::string m_OutPng; //Output filename for plot
  
  // Plotting flags and data
  std::vector< std::pair<double,double> > m_data; //input data points to plot
  std::vector< std::pair<double,double> > m_samples; //Holder for randomly sampled data 
  std::vector< std::pair<double,double> > m_function_scan; //holder for data from scanFunction (slight hack needed to plot function in gnuplot)
  bool m_plotfunction = false; //Flag to determine whether to plot function
  bool m_plotdatapoints = false; //Flag to determine whether to plot input data
  bool m_plotsamplepoints = false; //Flag to determine whether to plot sampled data 
  
  // Private functions
  double integrate(int Ndiv);
  void checkPath(std::string outstring); //Helper function to ensure data and png paths are correct
  void generatePlot(Gnuplot &gp); 
  std::vector< std::pair<double, double> > makeHist(std::vector<double> &points, int Nbins); //Helper function to turn data points into histogram with Nbins

  // Functions added 14.12.2023 - D.Waters
    double calculateMean(const std::vector<double>& data);
    double calculateStdDev(const std::vector<double>& data);


private:

  // Function evalutation
  double invxsquared(double x) const; //The default functional form

  // Seed for the random number generator - D.Waters 15/12/2023
      unsigned int seed; 

};