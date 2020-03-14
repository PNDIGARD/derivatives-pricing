//
//  MonteCarloPricer.hpp
//  MC-pricer
//


#ifndef MonteCarloPricer_hpp
#define MonteCarloPricer_hpp

#include <stdio.h>

double simpleMonteCarloPricer(double Expiry,
                              double Strike,
                              double Spot,
                              double Vol,
                              double r,
                              int NumberOfPaths);

#endif 
