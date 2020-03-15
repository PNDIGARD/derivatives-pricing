//
//  MonteCarloPricer.hpp
//  payoff-class
//


#ifndef MonteCarloPricer_hpp
#define MonteCarloPricer_hpp

#include <stdio.h>
#include "PayOff.hpp"

double simpleMonteCarloPricer(const PayOff& thePayOff,
                              double Expiry,
                              double Spot,
                              double Vol,
                              double r,
                              int NumberOfPaths);

#endif
