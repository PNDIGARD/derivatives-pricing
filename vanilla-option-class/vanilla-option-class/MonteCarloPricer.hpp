//
//  MonteCarloPricer.hpp
//  payoff-class
//


#ifndef MonteCarloPricer_hpp
#define MonteCarloPricer_hpp

#include <stdio.h>
#include "VanillaOption.hpp"

double simpleMonteCarloPricer(const VanillaOption& theOption,
                              double Spot,
                              double Vol,
                              double r,
                              int NumberOfPaths);

#endif
