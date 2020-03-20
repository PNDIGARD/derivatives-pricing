//
//  MonteCarloPricer.hpp
//  MC-pricer
//


#ifndef MonteCarloPricer_hpp
#define MonteCarloPricer_hpp

#include <stdio.h>
#include "parameter_classes.hpp"

double simpleMonteCarloPricer_Call(double Expiry,
                                   double Strike,
                                   double Spot,
                                   const ParameterBridge &Vol,
                                   const ParameterBridge &r,
                                   int NumberOfPaths);

#endif
